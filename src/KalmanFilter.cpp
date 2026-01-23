#include <iostream>
#include "KalmanFilter.h"

// Get current position --> Predict next position

KalmanFilter::KalmanFilter() : initialized(false) {
    std::cout << "KalmanFilter initialized." << std::endl;

    // 4 dynamic parameters, 2 measurement parameters, 0 control parameters
    // Dynamic: [x, y, dx, dy], Measurement: [x, y]
    kf = cv::KalmanFilter(4, 2, 0); 

    // How the state evolves from one time to the next w/o measurement update
    // x(k) = A*x(k-1) where A is the transition matrix
    kf.transitionMatrix = (cv::Mat_<float>(4, 4) << 1,0,1,0,    // x dimension
                                                    0,1,0,1,    // y dimension
                                                    0,0,1,0,    // dx dimension
                                                    0,0,0,1);   // dy dimension

    // Given internal state, what parts of it we can measure
    // z(k) = H*x(k) where H is the measurement matrix
    kf.measurementMatrix = (cv::Mat_<float>(2, 4) << 1,0,0,0,   // x dimension
                                                    0,1,0,0);   // y dimension

    setIdentity(kf.processNoiseCov, cv::Scalar::all(1e-2));     // Q
    setIdentity(kf.measurementNoiseCov, cv::Scalar::all(1e-1)); // R
    setIdentity(kf.errorCovPost, cv::Scalar::all(1));           // P
    
    predictedPosition = cv::Point2f(0, 0);
}

void KalmanFilter::update(cv::Point2f measurement) {
    // Create measurement matrix
    cv::Mat measurement_mat = (cv::Mat_<float>(2, 1) << measurement.x, measurement.y);
    
    if (!initialized) {
        // Initialize state with first measurement
        kf.statePost.at<float>(0) = measurement.x;   // x position
        kf.statePost.at<float>(1) = measurement.y;   // y position
        kf.statePost.at<float>(2) = 0;               // x velocity (dx)
        kf.statePost.at<float>(3) = 0;               // y velocity (dy)
        initialized = true;
        std::cout << "Kalman Filter initialized with first measurement: (" 
                  << measurement.x << ", " << measurement.y << ")" << std::endl;
    }
    
    // Update the Kalman filter with the measurement
    kf.correct(measurement_mat);
}

cv::Point2f KalmanFilter::predict() {
    // Predict the next state
    cv::Mat prediction = kf.predict();
    
    predictedPosition.x = prediction.at<float>(0);
    predictedPosition.y = prediction.at<float>(1);
    
    return predictedPosition;
}

cv::Point2f KalmanFilter::getPredictedPosition() const {
    return predictedPosition;
}

bool KalmanFilter::isInitialized() const {
    return initialized;
}