#ifndef STACKIMAGES_H
#define STACKIMAGES_H

#include <list>
#include <QImage>

class StackImage{
public:
    StackImage(){}
    inline void pushBack(QImage&& image){
        m_images.push_back(image);
    }

    inline QImage& pop(){
        return m_images.back();
    }
private:
    std::list<QImage> m_images;
};

#endif // STACKIMAGES_H
