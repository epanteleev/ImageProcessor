#include "ImageCanny.h"
namespace ImProg {

cv::Mat ImageCanny::apply(Settings* set){
    SettingsCanny cset = *static_cast<SettingsCanny*>(set);
    cv::Mat thresholdedMat;
    cv::Canny(m_image, thresholdedMat, cset.threshold1, cset.threshold2, cset.apertureSize, cset.L2gradient);
    return thresholdedMat;
}

}
