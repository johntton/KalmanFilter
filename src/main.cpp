#include "VideoCapture.h"

int main() {
    VideoCapture vc;
    
    while (true) {
        cv::Mat frame = vc.initCamera();
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