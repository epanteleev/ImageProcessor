#pragma once

#include "random"
class Settings {
public:
    Settings(){}
};

class SettingsThreshold : public Settings {
public:
    SettingsThreshold(){}
    int RTo;
    int BTo;
    int GTo;
    int RMax;
    int BMax;
    int GMax;
};

class SettingsCanny : public Settings {
public:
    double threshold1;
    double threshold2;
    int apertureSize = 3;
    bool L2gradient = false;
};

class SettingsConvert : public Settings {
public:
    enum ConvertType {
      GRAY = 0,
      HSV
    };

public:
    ConvertType type;
};

class SettingHough : public Settings {
public:
    enum HoughType {
        LINES = 0,
        CICRLE
    };

public:
    HoughType type;
    double rho = 1;
    double theta = 3.14/180;
    int threshold = 50;
    double minLineLength = 0;
    double maxLineGap = 0;
};
