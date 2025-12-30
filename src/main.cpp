//
// Created by ProkingDu on 25-12-29.
//
#include "FaceProcessor.hpp"
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "Units.hpp"
#include "ImageProcessor.hpp"
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

    // 打印区域
    for (const auto& rect : faces) {
        std::cout << "区域坐标：(" << rect.x << "," << rect.y << ")" << "尺寸：" << rect.width << "*" << rect.height << endl;
    }
    // 画框测试
    // for (const auto& r : faces) {
    //     cv::rectangle(frame,r,cv::Scalar(0,255,0),1);
    // }

    // 缩放测试
    cv::Rect newRect;
    std::vector<cv::Rect> scaledFaces;
    for (const auto& r : faces) {
        newRect = scale_rect_center(r,1.6,frame.size());
        adjust_rect_for_ID_photo(newRect);
        // cv::rectangle(frame,newRect,cv::Scalar(0,0,255),1);
        scaledFaces.push_back(newRect);
    }

    // 测试提取子图
    std::vector<cv::Mat> frame_faces;
    extract_face_part(frame,scaledFaces,frame_faces);

    // 测试展示子图
    for (const auto& iframe : frame_faces ) {
        std::cout << "显示图像" << std::endl;
        cv::imshow("child",iframe);
        cv::waitKey(1000);
    }
    // watch_img(frame);
}