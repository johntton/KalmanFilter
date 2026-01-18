#include <iostream>
#include "KalmanFilter.h"

// Get current position --> Predict next position

KalmanFilter::KalmanFilter() {
    std::cout << "KalmanFilter initialized." << std::endl;

    // 4 dynamic parameters, 2 measurement parameters, 0 control parameters
    // Dynamic: [x, y, dx, dy], Measurement: [x, y]
    cv::KalmanFilter kf(4, 2, 0); 

    // How the state evolves from one time to the next w/o measurement update
    // x(k) = A*x(k-1) where A is the transition matrix
    kf.transitionMatrix = (cv::Mat_<float>(4, 4) << 1,0,1,0, 
                                                    0,1,0,1,
                                                    0,0,1,0,
                                                    0,0,0,1);
    
    // Measurement matrix maps the true state space into the measured space
    kf.measurementMatrix = (cv::Mat_<float>(2, 4) << 1,0,0,0,
                                                   0,1,0,0);
}

