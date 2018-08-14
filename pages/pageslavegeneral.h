#ifndef PAGESLAVEGENERAL_H
#define PAGESLAVEGENERAL_H

#include <QWidget>
#include "bmsinterface.h"

namespace Ui {
class PageSlaveGeneral;
}

class PageSlaveGeneral : public QWidget
{
    Q_OBJECT

public:
    explicit PageSlaveGeneral(QWidget *parent = 0);
    ~PageSlaveGeneral();

    BMSInterface *bms() const;
    void setDieBieMS(BMSInterface *dieBieMS);

private:
    Ui::PageSlaveGeneral *ui;
    BMSInterface *mDieBieMS;
};

#endif // PAGESLAVEGENERAL_H
