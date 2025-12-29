cmake_minimum_required(VERSION 3.31)
project(EzIDPhoto)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status: ${OpenCV_DIR}")
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)
include_directories(assets)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
include_directories(/opt/homebrew/opt/opencv/share/opencv4/haarcascades)  # 此处替换为你的级联分类器，模型文件目录
add_executable(EzIDPhoto
        src/main.cpp
        include/FaceProcessor.hpp
        include/ImageProcessor.hpp
        include/Units.hpp
        src/FaceProcessor.cpp
        src/ImageProcessor.cpp
        src/Units.cpp)

target_link_libraries(EzIDPhoto ${OpenCV_LIBS})