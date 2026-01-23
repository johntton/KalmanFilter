#include "VideoCapture.h"
#include "ArucoDetector.h"
#include "MarkerCreator.h"
#include "KalmanFilter.h"

int main() {
    VideoCapture camera(1);
    ArucoDetector detector;
    MarkerCreator creator;
    KalmanFilter filter;
    
    std::vector<std::vector<cv::Point2f>> corners;

    creator.createMarker(0, 200, "aruco_marker.png");
    creator.saveMarker("aruco_marker.png");
    
    while (true) {
        cv::Mat frame = camera.getFrame();
        cv::Mat detectedFrame = detector.detectAruco(frame);

        if (detectedFrame.empty()) {
            break; 
        }

        corners = detector.getCorners();
        
        // Process markers if detected
        if (!corners.empty()) {
            cv::Point2f markerCenter = detector.getMarkerCenter(corners[0]);
            
            // Update Kalman filter with measurement
            filter.update(markerCenter);
            
            // Predict next position
            cv::Point2f predictedPosition = filter.predict();
            
            std::cout << "Marker Center: " << markerCenter << std::endl;
            std::cout << "Predicted Position: " << predictedPosition << std::endl;
            
            // Draw the detected marker center (white dot)
            cv::circle(detectedFrame, markerCenter, 5, cv::Scalar(255, 255, 255), -1);
            
            // Draw the predicted position (red dot)
            cv::circle(detectedFrame, predictedPosition, 5, cv::Scalar(0, 0, 255), -1);
            
            // Add labels
            cv::putText(detectedFrame, "Detected (white)", cv::Point(10, 30), 
                       cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1);
            cv::putText(detectedFrame, "Predicted (red)", cv::Point(10, 60), 
                       cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255), 1);
        }

        cv::imshow("Marker with Kalman Filter Prediction", detectedFrame);
        if (cv::waitKey(30) >= 0) {
            break;
        }
    }
    return 0;
}