#-------------------------------------------------
#
# Project created by QtCreator 2019-10-10T00:32:12
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

requires(qtConfig(filedialog))
qtHaveModule(printsupport): QT += printsupport


TARGET = ImageWidget
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/OpenCV/lib -lopencv_core
unix:!macx: LIBS += -L$$PWD/OpenCV/lib -lopencv_videoio
unix:!macx: LIBS += -L$$PWD/OpenCV/lib -lopencv_highgui
unix:!macx: LIBS += -L$$PWD/OpenCV/lib -lopencv_video
unix:!macx: LIBS += -L$$PWD/OpenCV/lib -lopencv_objdetect
unix:!macx: LIBS += -L$$PWD/OpenCV/lib -lopencv_imgproc
unix:!macx: LIBS += -L$$PWD/OpenCV/lib -lopencv_imgcodecs
unix:!macx: LIBS += -L$$PWD/OpenCV/lib -lopencv_calib3d
unix:!macx: LIBS += -L$$PWD/OpenCV/lib -lopencv_features2d
unix:!macx: LIBS += -L$$PWD/OpenCV/lib -lopencv_flann

INCLUDEPATH += $$PWD/OpenCV/include/opencv4
DEPENDPATH += $$PWD/OpenCV/include/opencv4

CONFIG += c++11

SOURCES += \
        main.cpp \
    Application.cpp \
    Image/ImageCanny.cpp \
    Image/ImageCountersFinder.cpp \
    Dialog/DialogCanny.cpp \
    Dialog/DialogRange.cpp \
    Image/ImageRange.cpp \
    common.cpp \
    AbstractMainWindow.cpp \
    Image/ImageConvert.cpp \
    Dialog/AbstractDialogWindow.cpp \
    MainWindow.cpp \
    Image/ImageHough.cpp \
    Dialog/DialogHough.cpp


HEADERS += \
    Image/ImageProcessor.h \
    Application.h \
    Image/ImageCanny.h \
    common.h \
    Image/ImageCountersFinder.h \
    Image/Settings.h \
    Image/something.h \
    Dialog/DialogCanny.h \
    stackimages.h \
    Dialog/DialogRange.h \
    Image/ImageRange.h \
    AbstractMainWindow.h \
    Image/ImageConvert.h \
    Dialog/AbstractDialogWindow.h \
    MainWindow.h \
    Image/ImageHough.h \
    Dialog/DialogHough.h

FORMS += \
        Form/mainwindow.ui \
    Form/dialogcanny.ui \
    Form/dialogrange.ui \
    Form/dialoghough.ui


