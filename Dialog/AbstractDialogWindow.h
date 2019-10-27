#pragma once
#include <QDialog>

#include "Image/Settings.h"
#include "AbstractMainWindow.h"

class AbstractDialogWindow : public QDialog {
    Q_OBJECT

protected:
    explicit AbstractDialogWindow(AbstractMainWindow *parent):
        m_parent(parent),
        m_images(parent->getImages())
    {

    }

public:
    virtual QImage update() = 0;

protected slots:
    virtual void closeApply();
    virtual void closeCancel();
    virtual void refresh();

protected:

    AbstractMainWindow *m_parent{};
    std::list<QImage>& m_images;
};


class AbstractDialogFabric {
public:
    virtual ~AbstractDialogFabric() {}

public:
    inline virtual AbstractDialogWindow* build(AbstractMainWindow *parent) const = 0;
};
