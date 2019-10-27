#ifndef IMAGECOUNTERSFINDER_H
#define IMAGECOUNTERSFINDER_H

#include "ImageProcessor.h"

namespace ImProg {

class ImageCountersFinder : public ImageProcessor {
public:
    ImageCountersFinder(cv::Mat& im) :
        ImageProcessor(im)
    {

    }

    cv::Mat apply(Settings* set) override;
};

}

#endif // IMAGECOUNTERSFINDER_H
