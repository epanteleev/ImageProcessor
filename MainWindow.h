#pragma once
#include <QMainWindow>
#include <QImage>

#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif

#include <QLabel>
#include <QScrollArea>
#include <vector>

#include "Dialog/DialogCanny.h"                 //todo
#include "Image/ImageProcessor.h"
#include "AbstractMainWindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public AbstractMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void open();
    void close();
    void saveAs();
    void about();
    void back();
    //void range();
    void convert(SettingsConvert::ConvertType type);
    void commonAction(const AbstractDialogFabric& fabric);
private:
    void createActions();
    void resizeEvent(QResizeEvent* e)override;

};
