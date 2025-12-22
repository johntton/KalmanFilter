#include "VideoCapture.h"

VideoCapture::VideoCapture(int index) {
    cap.open(index);

    if (!cap.isOpened()) {
        std::cerr << "Error: Failed to open camera at index " << index << "!\n";
    }

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
}

cv::Mat VideoCapture::getFrame() {
    cv::Mat frame;
    cap.read(frame);

    if (frame.empty()) {
        std::cerr << "Warning: Failed to grab frame!\n";
    }

    return frame;
}

VideoCapture::~VideoCapture() {
    std::cout << "VideoCapture destructor called.\n";

    cap.release();
}