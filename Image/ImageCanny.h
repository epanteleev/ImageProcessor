#pragma once
#include "ImageProcessor.h"

namespace ImProg {

class ImageCanny : public ImageProcessor {
public:
    ImageCanny(cv::Mat& im):
        ImageProcessor(im)
    {

    }

    OpType type() override { return CANNY;}

    cv::Mat apply(Settings* set) override;
};

}
