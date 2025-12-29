//
// Created by ProkingDu on 25-12-29.
//
#include "FaceProcessor.hpp"
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <iostream>
using namespace std;
int main(){
    cv::Mat frame = cv::imread("../assets/test.jpg");
    if (frame.empty()) {
        std::cout << "无法加载图像，请检查文件路径！" << std::endl;
        return -1;
    }
    std::vector<cv::Rect> faces;
    detectFace(frame,faces);
    std::cout << faces.size() << endl;
}