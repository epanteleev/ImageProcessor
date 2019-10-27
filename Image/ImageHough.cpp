#include "ImageHough.h"
#include "opencv2/imgproc/imgproc.hpp"
namespace ImProg {

cv::Mat ImageHough::apply(Settings* set) {
    SettingHough* hset = static_cast<SettingHough*>(set);
    std::vector<cv::Vec4i> lines;
    cv::Mat res;
    m_image.convertTo(res,cv::COLOR_GRAY2BGR);
    cv::cvtColor(m_image, res, cv::COLOR_GRAY2BGR);
    cv::HoughLines(m_image, lines, hset->rho, hset->theta, hset->threshold, hset->minLineLength, hset->maxLineGap);
    m_image.copyTo(res);
    for( size_t i = 0; i < lines.size(); i++ ) {
        cv::Vec4i l = lines[i];
        cv::line(res, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0,0,255));
    }
    return res;
}

}
