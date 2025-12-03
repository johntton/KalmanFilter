#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H

#include <opencv2/opencv.hpp>

class VideoCapture {
public:
    VideoCapture(int index = 1);
    ~VideoCapture();
    cv::Mat getFrame();
private:
    cv::Mat img;
    cv::VideoCapture cap;
};

#endif