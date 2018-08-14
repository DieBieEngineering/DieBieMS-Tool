#ifndef PAGESLAVESWITCH_H
#define PAGESLAVESWITCH_H

#include <QWidget>
#include "bmsinterface.h"

namespace Ui {
class PageSlaveSwitch;
}

class PageSlaveSwitch : public QWidget
{
    Q_OBJECT

public:
    explicit PageSlaveSwitch(QWidget *parent = 0);
    ~PageSlaveSwitch();

    BMSInterface *bms() const;
    void setDieBieMS(BMSInterface *dieBieMS);

private:
    Ui::PageSlaveSwitch *ui;
    BMSInterface *mDieBieMS;
};

#endif // PAGESLAVESWITCH_H
