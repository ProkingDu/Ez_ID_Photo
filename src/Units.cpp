//
// Created by ProkingDu on 25-12-29.
//
#include "Units.hpp";
#include <opencv2/highgui.hpp>

void watch_img(cv::Mat frame) {
    cv::imshow("test",frame);
    cv::waitKey(0);
}