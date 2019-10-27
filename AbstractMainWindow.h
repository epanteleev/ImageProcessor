#pragma once
#include <QMainWindow>
#include <QImage>

#ifndef QT_NO_PRINTER
#include <QPrinter>
#endif

#include <QLabel>
#include <QScrollArea>
#include <QMainWindow>
#include <vector>

#include "ui_mainwindow.h"
#include "Image/ImageProcessor.h"

class AbstractMainWindow :  public QMainWindow {
    Q_OBJECT

public:
    explicit AbstractMainWindow(QWidget *parent = nullptr);
    virtual ~AbstractMainWindow();
    virtual bool loadFile(const QString &fileName);
    virtual void setImage(const QImage &newImage);
    virtual void showImage(const QImage &newImage);
    virtual void updateActions();

    virtual bool saveFile(const QString &fileName);

    virtual void destroy();

    inline std::list<QImage>& getImages() {
        return m_images;
    }

protected:
    QMenu *m_convertAct{};
    QAction *m_backAct{};
    QAction *m_saveAsAct{};
    std::list<QImage> m_images;
    Ui::MainWidget *ui{};
    QDialog* m_active{};
};
