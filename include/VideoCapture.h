#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H

#include <opencv2/opencv.hpp>

class VideoCapture {
public:
    VideoCapture();
    cv::Mat initCamera();
private:
    cv::Mat img;
    cv::VideoCapture cap;
};

#endif