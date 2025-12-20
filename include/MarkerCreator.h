#ifndef MARKERCREATOR_H
#define MARKERCREATOR_H

#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/objdetect/aruco_detector.hpp>

class MarkerCreator {
public:
    MarkerCreator();
    void createMarker(int id, int size, const std::string& filename);
    void saveMarker(const std::string& filename);
    void displayMarker();
private:
    cv::Mat markerImage;
};

#endif