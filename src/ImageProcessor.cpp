//
// Created by ProkingDu on 25-12-29.
//
#include "ImageProcessor.hpp"
#include <iostream>
bool extract_face_part(const cv::Mat& frame,const std::vector<cv::Rect>& rects,std::vector<cv::Mat>& faces) {
    if (rects.empty()) {
        std::cout << "无选定脸部区域！" << std::endl;
        return false;
    }
    for (const cv::Rect rect : rects) {
        faces.push_back(frame(rect));
    }
    return true;
}