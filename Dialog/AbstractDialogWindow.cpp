#include "AbstractDialogWindow.h"
#include "QtDebug"

void AbstractDialogWindow::closeApply() {
    qDebug()<<"called AbstractDialogWindow::closeApply()";
    QImage newImage = update();
    m_parent->destroy();
    m_parent->setImage(newImage);
    m_parent->updateActions();
}

void AbstractDialogWindow::closeCancel() {
    qDebug()<<"called AbstractDialogWindow::closeCancel()";
    m_parent->destroy();
    m_parent->showImage(m_images.back());
    m_parent->updateActions();
}

void AbstractDialogWindow::refresh() {
    qDebug()<<"called AbstractDialogWindow::refresh()";
    QImage newImage = update();
    m_parent->showImage(newImage);
    m_parent->updateActions();
}
