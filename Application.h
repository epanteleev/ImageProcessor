#ifndef APPLICATION_H
#define APPLICATION_H

#include "MainWindow.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QtDebug>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include "opencv2/opencv.hpp"
#include <opencv2/imgproc.hpp>

class Application
{
public:
    Application(int argc, char *argv[]);

    int run();


private:
    QApplication a;
    QCommandLineParser commandLineParser;
    MainWindow w;
};

#endif // APPLICATION_H
