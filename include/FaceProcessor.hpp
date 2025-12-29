//
// Created by ProkingDu on 25-12-29.
//
#pragma once
#include <opencv2/core/mat.hpp>
#include <vector>
bool detectFace(const cv::Mat& frame, std::vector<cv::Rect>& faces);
