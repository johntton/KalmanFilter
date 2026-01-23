# Kalman Filter ArUco Marker Tracking

A C++ application that uses a Kalman filter to track ArUco markers detected in real-time video streams. This project combines computer vision with state estimation to predict marker positions and improve tracking accuracy.

## Overview

This application performs real-time marker detection and position prediction using:
- **ArUco Marker Detection**: Identifies ArUco markers in video frames
- **Kalman Filter**: Estimates and predicts marker positions based on measurements
- **OpenCV**: Handles video capture, image processing, and visualization

## Features

- **ArUco Marker Generation**: Create and save custom ArUco markers
- **Real-time Detection**: Detect ArUco markers in live video streams
- **Position Prediction**: Use Kalman filtering to predict next marker position
- **Visual Feedback**: Display detected positions (white dots) and predicted positions (red dots)
- **Camera Support**: Capture from any available camera device

## Project Structure

```
include/
├── KalmanFilter.h      # Kalman filter state estimation
├── ArucoDetector.h     # ArUco marker detection
├── VideoCapture.h      # Video capture wrapper
└── MarkerCreator.h     # ArUco marker generation

src/
├── main.cpp            # Main application loop
├── KalmanFilter.cpp    # Kalman filter implementation
├── ArucoDetector.cpp   # Marker detection implementation
├── VideoCapture.cpp    # Video capture implementation
└── MarkerCreator.cpp   # Marker creation implementation
```

## Components

### VideoCapture
Handles video input from connected cameras. Wraps OpenCV's VideoCapture functionality to provide frame-by-frame video data.

### ArucoDetector
Detects ArUco markers in video frames using OpenCV's ArUco module. Provides:
- Marker detection from frames
- Corner point extraction
- Marker center calculation

### MarkerCreator
Generates and saves ArUco markers for use in testing. Creates marker images that can be printed or displayed for detection.

### KalmanFilter
Implements 2D Kalman filtering for position estimation and prediction:
- Updates state based on detected marker positions
- Predicts next position
- Improves tracking accuracy by filtering out measurement noise

## Prerequisites

- **CMake**: Version 3.10 or higher
- **OpenCV**: With ArUco support (4.x recommended)
- **C++17 or later**: Compiler with C++17 support

### Installation on macOS

```bash
# Install dependencies via Homebrew
brew install cmake opencv

# Or install OpenCV from source for full ArUco support
```

## Building

```bash
# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
make

# Run the application
./KalmanFilter
```

## Usage

```bash
./KalmanFilter
```

The application will:
1. Create an ArUco marker and save it as `aruco_marker.png`
2. Open a video stream from the default camera
3. Detect ArUco markers in each frame
4. Update the Kalman filter with detected positions
5. Display:
   - **White dots**: Detected marker center positions
   - **Red dots**: Predicted marker positions using Kalman filter
6. Output marker center and predicted positions to console

### Keyboard Controls

- **ESC** or **Q**: Exit the application

## How It Works

### Kalman Filter Workflow

1. **Detection**: ArUco markers are detected in the current video frame
2. **Measurement**: The detected marker center is used as a measurement input
3. **Update**: The Kalman filter updates its internal state based on the measurement
4. **Prediction**: The filter predicts the next marker position
5. **Display**: Both detected and predicted positions are visualized on the frame

## Output

The application displays:
- Console output showing detected marker center and predicted position for each frame
- Live video with overlaid markers:
  - White circle: Detected marker center
  - Red circle: Predicted position
  - Text labels for clarity

## Dependencies

- `OpenCV 4.x` - Computer vision library with ArUco support
- `C++ Standard Library` - For standard data structures and I/O

## License

MIT License