#ifndef ARUCODETECTOR_H
#define ARUCODETECTOR_H

#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/objdetect/aruco_detector.hpp>

class ArucoDetector {
public:
    ArucoDetector();
    void generateMarker();
    cv::Mat detectAruco(cv::Mat &frame);
    std::vector<std::vector<cv::Point2f>> getCorners();
    cv::Point2f getMarkerCenter(std::vector<cv::Point2f> corners);
private:
    std::vector<int> markerIds;
    std::vector<std::vector<cv::Point2f>> markerCorners, rejectedCandidates;
    cv::aruco::DetectorParameters parameters;
    cv::aruco::Dictionary dictionary;
};

#endif