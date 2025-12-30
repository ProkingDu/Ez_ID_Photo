//
// Created by ProkingDu on 25-12-29.
//
#pragma once
#include <opencv2/core/mat.hpp>
void watch_img(cv::Mat frame);
cv::Rect scale_rect_center(const cv::Rect& rect,float scale,const cv::Size& imgSize);  // 中心缩放rect区域
void adjust_rect_for_ID_photo(cv::Rect& rect);  // 调整为证件照尺寸