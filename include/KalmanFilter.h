#ifndef KALMANFILTER_H
#define KALMANFILTER_H

#include <opencv2/opencv.hpp>
#include <opencv2/video/tracking.hpp>

class KalmanFilter {
public:
    KalmanFilter();
    void update(cv::Point2f measurement);
    cv::Point2f predict();
    cv::Point2f getPredictedPosition() const;
    bool isInitialized() const;
private:
    cv::KalmanFilter kf;
    cv::Point2f predictedPosition;
    bool initialized;
};

#endif