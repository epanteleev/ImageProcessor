#pragma once
#include <QDialog>

#include "Image/Settings.h"
#include "AbstractMainWindow.h"
#include "AbstractDialogWindow.h"

namespace Ui {
class DialogCanny;
}

class DialogCanny : public AbstractDialogWindow {
    Q_OBJECT

public:
    explicit DialogCanny(AbstractMainWindow *parent);

    SettingsCanny settings();
    QImage update();
    ~DialogCanny();



private:
    Ui::DialogCanny *ui;
};

class DialogCannyFabric : public AbstractDialogFabric {
public:
    inline AbstractDialogWindow* build(AbstractMainWindow *parent)const override {
        return new DialogCanny(parent);
    }
};
