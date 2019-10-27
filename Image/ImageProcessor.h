#pragma once
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc.hpp>
#include "something.h"
#include "Settings.h"

namespace ImProg {

class ImageProcessor : public Something {
public:
    ImageProcessor(cv::Mat& im):
        m_image(im)
    {}

    ~ImageProcessor() override { /*delete image;*/ }
    OpType type() override { return UNDEFINED;}

    virtual cv::Mat apply(Settings* set) = 0;

protected:
    cv::Mat& m_image;
};

}
