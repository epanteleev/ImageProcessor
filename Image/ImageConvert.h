#pragma once
#include "ImageProcessor.h"

namespace ImProg {

class ImageConvert : public ImageProcessor {
public:
    ImageConvert(cv::Mat& im):
        ImageProcessor(im)
    {

    }

    OpType type() override { return CONVERT;}

    cv::Mat apply(Settings* set) override;
};

}
