#pragma once
#include "ImageProcessor.h"

namespace ImProg {

class ImageRange: public ImageProcessor {
public:
    ImageRange(cv::Mat& im):
        ImageProcessor(im)
    {

    }

    OpType type()override {
        return THRESHOLD;
    }

    cv::Mat apply(Settings* set) override;

};

}
