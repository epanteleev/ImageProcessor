#include "MainWindow.h"

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

#include "Dialog/DialogCanny.h"
#include "Dialog/DialogRange.h"
#include "Dialog/DialogHough.h"
#include "common.h"
#include "Image/ImageCanny.h"
#include "Image/ImageCountersFinder.h"
#include "Image/ImageRange.h"
#include "Image/ImageConvert.h"

#include "AbstractMainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    AbstractMainWindow(parent)
{
    createActions();
}

void MainWindow::createActions() {

    QAction *open = ui->menuFile->addAction(tr("&Open"), this, &MainWindow::open);
    open->setShortcut(tr("Ctrl+O"));
    ui->menuFile->addSeparator();


    m_saveAsAct = ui->menuFile->addAction(tr("&Save As..."), this, &MainWindow::saveAs);
    m_saveAsAct->setEnabled(false);
    m_saveAsAct->setShortcut(tr("Ctrl+Shift+S"));
    ui->menuFile->addSeparator();

    QAction *exitAct = ui->menuFile->addAction(tr("E&xit"), this, &MainWindow::close);
    exitAct->setShortcut(tr("Ctrl+Q"));


    //add canny
    QAction *cannyAct = ui->menuEdit->addAction(tr("&Canny"), this, [=]() { commonAction (DialogCannyFabric()); });
    cannyAct->setEnabled(false);

    m_convertAct =  ui->menuEdit->addMenu("&Convert");
    QAction* conv = m_convertAct->addAction(tr("&Gray"), this, [=]() { convert(SettingsConvert::GRAY);} );
    conv->setEnabled(false);

    conv = m_convertAct->addAction(tr("&HSV"), this, [=]() { convert(SettingsConvert::HSV);} );
    conv->setEnabled(false);

//    //add range
//    QAction *rangeAct = ui->menuEdit->addAction(tr("&Range"), this, &MainWindow::range);
//    rangeAct->setEnabled(false);

    //add hough
    QAction *houghAct = ui->menuEdit->addAction(tr("&Hough"), this, [=]() { commonAction (DialogHoughFabric()); });
    houghAct->setEnabled(false);



    //add back
    m_backAct = ui->menuEdit->addAction(tr("&Back"), this, &MainWindow::back);
    m_backAct->setShortcut(tr("Ctrl+Z"));
    m_backAct->setEnabled(false);


    //add help
    QMenu *helpMenu = ui->menuBar->addMenu(tr("&Help"));

    helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    helpMenu->addAction(tr("About &Qt"), &QApplication::aboutQt);
}

void MainWindow::back() {
    qDebug()<<"called MainWindow::back()";
    m_images.pop_back();
    showImage(m_images.back());
}

void MainWindow::commonAction(const AbstractDialogFabric& fabric) {
    if(m_active == nullptr){
        m_active = fabric.build(this);
    }
    if(!m_active->isVisible()){
        m_active->show();
        m_active->exec();
    }
}

void MainWindow::convert(SettingsConvert::ConvertType type) {
    SettingsConvert set;
    set.type = type;
    auto u = qimageToMat(m_images.back());
    cv::Mat mat = ImProg::ImageConvert(u).apply(&set);
    setImage(matToQimage(mat));
    updateActions();
}

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode) {
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    foreach (const QByteArray &mimeTypeName, supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    if (acceptMode == QFileDialog::AcceptSave){
        dialog.setDefaultSuffix("jpg");
    }
}

void MainWindow::open() {
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}
}

void MainWindow::saveAs() {
    QFileDialog dialog(this, tr("Save File As"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptSave);

    while (dialog.exec() == QDialog::Accepted && !saveFile(dialog.selectedFiles().first())) {}
}

void MainWindow::about() {
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}

void MainWindow::close() {
    close();
}

void MainWindow::resizeEvent(QResizeEvent* e) {
    qDebug()<<"call resizeEvent: "<< e->size() << endl;

    //ui->imageLabel->setBaseSize(e->size());
    if(ui->imageLabel->pixmap() != nullptr){
        const QPixmap* p = ui->imageLabel->pixmap();
        int w = ui->imageLabel->width();
        int h = ui->imageLabel->height();
        ui->imageLabel->setPixmap(p->scaled(w, h, Qt::KeepAspectRatio));
    }
}
