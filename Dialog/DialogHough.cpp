#include "DialogHough.h"
#include "ui_dialoghough.h"

#include "common.h"
#include "Image/ImageHough.h"
#include <QMessageBox>
DialogHough::DialogHough(AbstractMainWindow *parent) :
    AbstractDialogWindow(parent),
    ui(new Ui::DialogHough)
{
    ui->setupUi(this);
    connect(ui->applyButton, &QAbstractButton::clicked, this, &DialogHough::closeApply);
    connect(ui->cancelButton, &QAbstractButton::clicked, this, &DialogHough::closeApply);

    connect(ui->thetaSlider, &QAbstractSlider::sliderReleased, this, &DialogHough::refresh);
    connect(ui->rhoSlider, &QAbstractSlider::sliderReleased, this, &DialogHough::refresh);
    connect(ui->thresholdSlider, &QAbstractSlider::sliderReleased, this, &DialogHough::refresh);
}

SettingHough DialogHough::settings() {
    SettingHough hough;
    hough.type = SettingHough::LINES;
    hough.rho = ui->rhoSlider->value();
    hough.theta = ui->thetaSlider->value();
    hough.threshold = ui->thresholdSlider->value();
    return hough;
}

QImage DialogHough::update() {
    cv::Mat mat = qimageToMat(m_images.back());
    SettingHough set = settings();
    cv::Mat res;
     res = ImProg::ImageHough(mat).apply(&set);
    try {
    } catch (std::exception& ex) {
        errorWindow(ex.what());
    }
    return matToQimage(res);
}

DialogHough::~DialogHough() {
    delete ui;
}
