#include "VideoCapture.h"

int main() {
    VideoCapture camera;
    
    while (true) {
        cv::Mat frame = camera.getFrame();
        if (frame.empty()) {
            break; // Exit loop if frame is empty
        }

        cv::imshow("Video", frame);
        if (cv::waitKey(30) >= 0) {
            break; // Exit on any key press
        }
    }

    return 0;
}