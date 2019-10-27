#include "AbstractMainWindow.h"

#include "ui_mainwindow.h"

#include <QPrintDialog>
#include <QtPrintSupport/qtprintsupportglobal.h>
#include <QFileDialog>
#include <QImageReader>
#include <QImageWriter>
#include <QStandardPaths>
#include <QMessageBox>
#include <QMouseEvent>
#include <iostream>
#include <QDebug>


#include "common.h"
#include "Image/ImageCanny.h"
#include "Image/ImageCountersFinder.h"
#include "Image/ImageRange.h"

AbstractMainWindow::AbstractMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

AbstractMainWindow::~AbstractMainWindow() {
    delete ui;
}

void AbstractMainWindow::updateActions() {
    qDebug()<<"called AbstractMainWindow::updateActions()";
    qDebug()<<"size image stack: "<<m_images.size();
    m_backAct->setEnabled(m_images.size() > 1);
    bool bl = !m_images.back().isNull();
    m_saveAsAct->setEnabled(bl);
    if(!bl){
        return;
    }
    foreach(QAction* rb, ui->menuEdit->actions()) {
        rb->setEnabled(bl);
    }
    foreach(QAction* rb, m_convertAct->actions()) {
        rb->setEnabled(bl);
    }
}

void AbstractMainWindow::showImage(const QImage &newImage) {
    qDebug()<<"called AbstractMainWindow::showImage(const QImage &newImage)";
    Q_ASSERT(!newImage.isNull());
    const QPixmap px = QPixmap::fromImage(newImage);
    int w = ui->imageLabel->width();
    int h = ui->imageLabel->height();

    ui->imageLabel->setPixmap(px.scaled(w, h, Qt::KeepAspectRatio));

    ui->imageLabel->setAlignment(Qt::AlignCenter);
    updateActions();
}

void AbstractMainWindow::setImage(const QImage &newImage) {
    m_images.push_back(newImage);
    showImage(newImage);
}

bool AbstractMainWindow::loadFile(const QString &fileName) {
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }

    setImage(newImage);
    setWindowFilePath(fileName);

    const QString message = tr("Opened \"%1\", %2x%3, Depth: %4")
        .arg(QDir::toNativeSeparators(fileName)).arg(m_images.back().width()).arg(m_images.back().height()).arg(m_images.back().depth());
    ui->statusBar->showMessage(message);
    return true;
}

bool AbstractMainWindow::saveFile(const QString &fileName) {
    QImageWriter writer(fileName);

    if (!writer.write(m_images.back())) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot write %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName)), writer.errorString());
        return false;
    }
    const QString message = tr("Wrote \"%1\"").arg(QDir::toNativeSeparators(fileName));
    statusBar()->showMessage(message);
    return true;
}

void AbstractMainWindow::destroy(){
    qDebug()<<"called AbstractMainWindow::destroy()";
    m_active->close();
    delete m_active;
    m_active = nullptr;
}
