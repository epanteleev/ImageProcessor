#include "ImageCountersFinder.h"
#include "ImageCanny.h"

namespace ImProg
{

cv::Mat ImageCountersFinder::apply(Settings *set){
    cv::Mat canny_img = ImageCanny(m_image).apply(set);
    std::vector< std::vector<cv::Point>> countours;
    std::vector< cv::Vec4i > hierarchy;
    cv::findContours(canny_img, countours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
    cv::drawContours(m_image, countours, -1, cv::Scalar(255), cv::FILLED);
    cv::Mat res;
    m_image.copyTo(res);
    return res;
}

}
