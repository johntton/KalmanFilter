#include "VideoCapture.h"

VideoCapture::VideoCapture() : cap(1) {}

cv::Mat VideoCapture::initCamera() {
    if (!cap.isOpened()) {
        std::cerr << "Camera failed to open!\n";
        return cv::Mat();
    }

    cap.read(img);
    if (img.empty()) {
        std::cerr << "Frame grab failed!\n";
        return cv::Mat();
    }

    return img;
}