#pragma once

#include <QDialog>
#include "AbstractDialogWindow.h"

namespace Ui {
class DialogHough;
}

class DialogHough : public AbstractDialogWindow {
    Q_OBJECT

public:
    explicit DialogHough(AbstractMainWindow *parent);
    ~DialogHough()override;
    QImage update()override;

private:
    SettingHough settings();

private:
    Ui::DialogHough *ui;
};

class DialogHoughFabric : public AbstractDialogFabric {
public:
    inline AbstractDialogWindow* build(AbstractMainWindow* parent) const override {
        return new DialogHough(parent);
    }
};
