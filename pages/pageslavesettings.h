#ifndef PAGESLAVESETTINGS_H
#define PAGESLAVESETTINGS_H

#include <QWidget>
#include "bmsinterface.h"

namespace Ui {
class PageSlaveSettings;
}

class PageSlaveSettings : public QWidget
{
    Q_OBJECT

public:
    explicit PageSlaveSettings(QWidget *parent = 0);
    ~PageSlaveSettings();

    BMSInterface *bms() const;
    void setDieBieMS(BMSInterface *dieBieMS);

private:
    Ui::PageSlaveSettings *ui;
    BMSInterface *mDieBieMS;
};

#endif // PAGESLAVESETTINGS_H
