#pragma once
#include "ImageProcessor.h"

namespace ImProg {

class ImageHough : public ImageProcessor{
public:
    ImageHough(cv::Mat& im):
        ImageProcessor(im)
    {

    }

    OpType type() override { return HOUGH;}

    cv::Mat apply(Settings* set) override;
};

}
