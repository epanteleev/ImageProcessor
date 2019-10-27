#pragma once

enum OpType {
    UNDEFINED = 0,
    IMAGEPROCESSOR,
    CANNY,
    CONVERT,
    THRESHOLD,
    HOUGH
};

class Something {
public:
    Something(){}
    virtual ~Something(){}
    virtual OpType type(){ return UNDEFINED;}
};
