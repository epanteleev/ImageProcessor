#include "ImageRange.h"
#include "Settings.h"

namespace ImProg {

cv::Mat ImageRange::apply(Settings* set){
    SettingsThreshold* thset = static_cast<SettingsThreshold*>(set);
    cv::Mat thresholdedMat;
    cv::cvtColor(m_image, thresholdedMat, cv::COLOR_RGB2HSV );
    cv::inRange(thresholdedMat,cv::Scalar(thset->RTo, thset->BTo, thset->GTo),
        cv::Scalar( thset->RMax, thset->BMax, thset->GMax ), thresholdedMat);

    cv::erode(thresholdedMat,thresholdedMat, cv::getStructuringElement( cv::MORPH_ELLIPSE, cv::Size( 5, 5 )));
    cv::dilate(thresholdedMat, thresholdedMat, cv::getStructuringElement( cv::MORPH_ELLIPSE, cv::Size( 5, 5 )));

    // Замыкаем оставшиеся крупные объекты
    cv::dilate(thresholdedMat,thresholdedMat, cv::getStructuringElement( cv::MORPH_ELLIPSE, cv::Size( 5, 5 ) ));
    cv::erode(thresholdedMat, m_image, cv::getStructuringElement( cv::MORPH_ELLIPSE, cv::Size( 5, 5 ) ));
    cv::Mat t;
    m_image.copyTo(t);
    return t;
}
}
