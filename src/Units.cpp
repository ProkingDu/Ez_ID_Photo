//
// Created by ProkingDu on 25-12-29.
//
#include "Units.hpp";
#include <opencv2/highgui.hpp>

void watch_img(cv::Mat frame) {
    cv::imshow("test",frame);
    cv::waitKey(0);
}

cv::Rect scale_rect_center(const cv::Rect& rect,float scale,const cv::Size& imgSize){  // 缩放Rect区域
    cv::Point center(rect.x + rect.width / 2 , rect.y + rect.height /2 );  // 计算中心点

    int newW = static_cast<int>(rect.width * scale);  // 新的宽度
    int newH = static_cast<int>(rect.height* scale);  // 新的高度
    int newX = center.x - newW / 2;
    int newY = center.y - newH / 2;

    cv::Rect newRect(newX,newY,newW,newH);
    cv::Rect imgRect(0,0,imgSize.width,imgSize.height);

    // 交运算防止溢出
    return newRect & imgRect;
}
void adjust_rect_for_ID_photo(cv::Rect& rect) {
    const cv::Point center(rect.x + rect.width / 2 , rect.y + rect.height /2 );  // 计算中心点
    const int newH = static_cast<int>(rect.width * 7/5);
    const int newY = center.y - newH /2;
    rect.height = newH;
    rect.y = newY;
}