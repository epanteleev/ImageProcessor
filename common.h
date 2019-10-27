#pragma once
#include "Application.h"
#include "MainWindow.h"
#include <QMessageBox>

void matToQimage(cv::InputArray image, QImage& out);

void qimageToMat(const QImage& image, cv::OutputArray out);

inline cv::Mat qimageToMat(const QImage& image) {
    cv::Mat ret;
    qimageToMat(image, ret);
    return ret;
}

inline QImage matToQimage(cv::InputArray image) {
    QImage ret;
    matToQimage(image, ret);
    return ret;
}

inline void errorWindow(const char* message){
    QMessageBox ().critical(nullptr, "Error", message);
}
