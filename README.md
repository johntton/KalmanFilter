# Kalman Filter ArUco Marker Tracking

A C++ application that detects an ArUco marker in a live camera feed and uses a Kalman filter to estimate and predict its position. This project combines computer vision with state estimation to smooth noisy detections and anticipate where the marker will be next.

## Overview

The application uses:
- **ArUco marker detection** to find a marker in each video frame
- **A Kalman filter** to estimate the marker's position and velocity and predict its next position
- **OpenCV** for video capture, image processing, and display

## Features

- **Marker generation**: Generates a printable ArUco marker (`aruco_marker.png`)
- **Real-time detection**: Detects ArUco markers (`DICT_4X4_50`) in a live camera feed
- **Position prediction**: Predicts the marker's next position with a constant-velocity Kalman filter
- **Visual feedback**: Draws the detected center (white dot) and predicted position (red dot) on each frame

## Project Structure

```
include/
├── KalmanFilter.h      # Kalman filter state estimation
├── ArucoDetector.h     # ArUco marker detection
├── VideoCapture.h      # Camera capture wrapper
└── MarkerCreator.h     # ArUco marker generation

src/
├── main.cpp            # Main application loop
├── KalmanFilter.cpp    # Kalman filter implementation
├── ArucoDetector.cpp   # Marker detection implementation
├── VideoCapture.cpp    # Camera capture implementation
└── MarkerCreator.cpp   # Marker generation implementation
```

## Components

### VideoCapture
Wraps OpenCV's `cv::VideoCapture`. Opens a camera by index and returns frames at 640×480.

### ArucoDetector
Detects ArUco markers from the `DICT_4X4_50` dictionary. Provides:
- Marker detection, with detected markers outlined on the frame
- Corner point extraction
- Marker center calculation (the average of the four corners)

### MarkerCreator
Generates an ArUco marker image and saves it so it can be printed or shown on another screen for testing.

### KalmanFilter
Wraps `cv::KalmanFilter` with a constant-velocity model:
- **State**: `[x, y, dx, dy]` (position and velocity)
- **Measurement**: `[x, y]` (the detected marker center)
- Initializes its state from the first measurement
- Corrects its estimate with each new measurement, then predicts the next position

## Prerequisites

- **CMake** 3.10 or higher
- **A C++17 compiler**
- **OpenCV 4.7 or later** with the contrib `aruco` module (Homebrew's `opencv` package includes it)

### Installation on macOS

```bash
brew install cmake opencv
```

## Building

From the project root:

```bash
cmake -S . -B build
cmake --build build
```

## Usage

```bash
./build/KalmanFilter
```

The application will:
1. Generate an ArUco marker (ID 0, 200×200 px) and save it as `aruco_marker.png` in the project root
2. Open the camera at index `1` (set in `src/main.cpp`; change it to `0` if that is your default camera)
3. Detect ArUco markers in each frame and track the first one found
4. Update the Kalman filter with the marker's center, then predict its next position
5. Display the live feed with:
   - **White dot**: Detected marker center
   - **Red dot**: Predicted position
6. Print the detected center and predicted position to the console for each frame

Print `aruco_marker.png` or open it on another screen, then hold it in front of the camera.

### Keyboard Controls

- **Any key**: Exit the application (the video window must be focused)

## How It Works

For each frame:

1. **Detect**: Find ArUco markers in the frame
2. **Measure**: Use the first detected marker's center as the measurement
3. **Correct**: Update the Kalman filter's state with the measurement
4. **Predict**: Project the state forward one step to estimate the next position
5. **Display**: Draw both the detected and predicted positions on the frame

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
