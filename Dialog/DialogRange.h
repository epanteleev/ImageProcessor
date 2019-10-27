#pragma once
#include <QDialog>
#include "Image/Settings.h"

namespace Ui {
class DialogRange;
}

class DialogRange : public QDialog {
    Q_OBJECT

public:
    explicit DialogRange(QWidget *parent = nullptr);

     SettingsThreshold settings();
    ~DialogRange();

private:
    Ui::DialogRange *ui;
};
