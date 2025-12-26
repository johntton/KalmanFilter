#include <iostream>
#include "ArucoDetector.h"
#include <string>

// Given a frame --> find the ArUco marker --> return its center (x, y)

// Constructor for ArucoDetector
ArucoDetector::ArucoDetector() {
    std::cout << "ArucoDetector initialized." << std::endl;
} 

// Function to detect ArUco markers in the frame
cv::Mat ArucoDetector::detectAruco(cv::Mat &frame) {
    parameters = cv::aruco::DetectorParameters();
    dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
    cv::aruco::ArucoDetector detector(dictionary, parameters);
    detector.detectMarkers(frame, markerCorners, markerIds, rejectedCandidates);
    cv::aruco::drawDetectedMarkers(frame, markerCorners, markerIds);

    return frame;
}

// Function to get the corners of the detected markers
std::vector<std::vector<cv::Point2f>> ArucoDetector::getCorners() {
    return markerCorners;
}

// Function to calculate the center of a marker given its corners
cv::Point2f ArucoDetector::getMarkerCenter(std::vector<cv::Point2f> corners) {
    center = cv::Point2f(0, 0);
    for (const auto& corner : corners) {
        center.x += corner.x;
        center.y += corner.y;
    }
    center.x /= corners.size();
    center.y /= corners.size();
    return center;
}

// Function to draw the center of the detected marker on the frame
cv::Mat ArucoDetector::drawCenter(cv::Mat &frame) {
    if (!markerCorners.empty()) {
        center = getMarkerCenter(markerCorners[0]);
        cv::circle(frame, center, 5, cv::Scalar(255, 255, 255), -1);
    }
    return frame;
}