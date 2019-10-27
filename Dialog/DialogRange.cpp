#include "DialogRange.h"
#include "ui_dialogrange.h"

DialogRange::DialogRange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRange)
{
    ui->setupUi(this);

    connect(ui->applyButton, SIGNAL(clicked(bool)), SLOT(close()));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), SLOT(close()));
    connect(ui->Brange, SIGNAL(sliderReleased()),parent, SLOT(range()));
    connect(ui->Rrange, SIGNAL(sliderReleased()),parent, SLOT(range()));
    connect(ui->Grange, SIGNAL(sliderReleased()),parent, SLOT(range()));
    connect(ui->spinGrange, SIGNAL(valueChanged(int)),parent, SLOT(range()));
    connect(ui->spinBrange, SIGNAL(valueChanged(int)),parent, SLOT(range()));
    connect(ui->spinRrange, SIGNAL(valueChanged(int)),parent, SLOT(range()));
}

SettingsThreshold DialogRange::settings() {
    SettingsThreshold set;
    set.BTo = ui->Brange->value();
    set.RTo = ui->Rrange->value();
    set.GTo = ui->Grange->value();

    set.BMax = set.BTo + ui->spinBrange->value();
    set.RMax = set.RTo + ui->spinRrange->value();
    set.GMax = set.GTo + ui->spinGrange->value();

    return set;
}

DialogRange::~DialogRange() {
    delete ui;
}
