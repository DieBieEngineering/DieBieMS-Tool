#ifndef PAGESLAVEIO_H
#define PAGESLAVEIO_H

#include <QWidget>
#include "bmsinterface.h"

namespace Ui {
class PageSlaveIO;
}

class PageSlaveIO : public QWidget
{
    Q_OBJECT

public:
    explicit PageSlaveIO(QWidget *parent = 0);
    ~PageSlaveIO();

    BMSInterface *bms() const;
    void setDieBieMS(BMSInterface *dieBieMS);

private:
    Ui::PageSlaveIO *ui;
    BMSInterface *mDieBieMS;
};

#endif // PAGESLAVEIO_H
