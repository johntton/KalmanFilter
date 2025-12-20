#include "MarkerCreator.h"

MarkerCreator::MarkerCreator() {}

void MarkerCreator::createMarker(int id, int size, const std::string& filename) {
    std::cout << "Creating ArUco marker." << std::endl;

    // Using 4x4 dictionary with 50 markers, marker ID 0, marker size 200x200 pixels, and border thickness 1 pixel
    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50);
    cv::aruco::generateImageMarker(dictionary, id, size, markerImage, 1); 
}

void MarkerCreator::saveMarker(const std::string& filename) {
    std::cout << "Saving marker image to file: " << filename << std::endl;

    // Save the generated marker image to a file
    std::string outPath = std::string(PROJECT_SOURCE_DIR) + "/aruco_marker.png";
    if (!cv::imwrite(outPath, markerImage)) {
        std::cerr << "Error: Unable to save the marker image." << std::endl;
        return;
    }
}

void MarkerCreator::displayMarker() {
    std::cout << "Displaying marker image." << std::endl;

    // Display the generated marker image in a window
    cv::imshow("ArUco Marker", markerImage);
    cv::waitKey(0); // Wait for a key press to close the window
}