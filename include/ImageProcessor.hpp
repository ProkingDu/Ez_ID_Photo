//
// Created by ProkingDu on 25-12-29.
//
#pragma once
#include <vector>
#include <opencv2/core/mat.hpp>
bool extract_face_part(const cv::Mat& frame,const std::vector<cv::Rect>& rects,std::vector<cv::Mat>& faces);