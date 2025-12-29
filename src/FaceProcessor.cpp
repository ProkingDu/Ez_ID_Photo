//
// Created by ProkingDu on 25-12-29.
//
#include "FaceProcessor.hpp"
#include "Units.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
bool detectFace(const cv::Mat& frame, std::vector<cv::Rect>& faces) {  // 函数仅返回是否检测成功，结果由引用变量传递。
    // 加载级联分类器模型
    cv::CascadeClassifier cascade_classifier;
    if (!cascade_classifier.load("assets/haarcascade_frontalface_alt.xml")) {
        std::cout << "无法加载级联分类器文件！" << std::endl;
        return false;
    }

    // 预处理
    cv::Mat gray;
    cv::cvtColor(frame,gray,cv::COLOR_BGR2GRAY);
    cv::equalizeHist(gray,gray);

    // 检测人脸
    cascade_classifier.detectMultiScale(gray,faces);
    return true;
}