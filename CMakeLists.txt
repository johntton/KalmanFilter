cmake_minimum_required(VERSION 3.10)
project(KalmanFilter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS}/opencv4)
include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(KalmanFilter src/main.cpp src/KalmanFilter.cpp src/ArucoDetector.cpp src/Tracker.cpp src/VideoCapture.cpp)

target_link_libraries(KalmanFilter ${OpenCV_LIBS})