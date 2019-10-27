#include "ImageConvert.h"

namespace ImProg {

cv::Mat ImageConvert::apply(Settings* set) {
    SettingsConvert* convSet = static_cast<SettingsConvert*>(set);
    cv::Mat res;
    if(convSet->type == SettingsConvert::GRAY) {
        cv::cvtColor(m_image, res, cv::COLOR_BGR2GRAY);
    }else if(convSet->type == SettingsConvert::HSV) {
        cv::cvtColor(m_image, res, cv::COLOR_BGR2HSV);
    }else {
        throw std::exception();
    }
    return res;
}

}
