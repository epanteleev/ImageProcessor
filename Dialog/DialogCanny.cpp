#include "DialogCanny.h"
#include "ui_dialogcanny.h"

#include "Image/ImageCanny.h"
#include "common.h"
#include "MainWindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

DialogCanny::DialogCanny(AbstractMainWindow *parent) :
    AbstractDialogWindow(parent),
    ui(new Ui::DialogCanny)
{
    ui->setupUi(this);

    connect(ui->threshold1, &QAbstractSlider::sliderReleased, this, &DialogCanny::refresh);
    connect(ui->threshold2, &QAbstractSlider::sliderReleased, this, &DialogCanny::refresh);
    connect(ui->apertureSlider, &QAbstractSlider::sliderReleased, this, &DialogCanny::refresh);

    connect(ui->applyButton, &QAbstractButton::clicked, this, &DialogCanny::closeApply);
    connect(ui->cancelButton, &QAbstractButton::clicked, this, &DialogCanny::closeApply);
}

SettingsCanny DialogCanny::settings(){
    SettingsCanny set;
    set.threshold1 = ui->threshold1->value();
    set.threshold2 = ui->threshold2->value();
    set.apertureSize = (ui->apertureSlider->value() - 1) * 2 + 3;
    return set;
}

QImage DialogCanny::update() {
    cv::Mat mat = qimageToMat(m_images.back());
    SettingsCanny set = settings();
    cv::Mat res = ImProg::ImageCanny(mat).apply(&set);
    return matToQimage(res);
}

DialogCanny::~DialogCanny(){
    delete ui;
}
