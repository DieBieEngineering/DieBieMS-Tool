#ifndef PAGESLAVEFAN_H
#define PAGESLAVEFAN_H

#include <QWidget>
#include "bmsinterface.h"

namespace Ui {
class PageSlaveFAN;
}

class PageSlaveFAN : public QWidget
{
    Q_OBJECT

public:
    explicit PageSlaveFAN(QWidget *parent = 0);
    ~PageSlaveFAN();

    BMSInterface *bms() const;
    void setDieBieMS(BMSInterface *dieBieMS);

private:
    Ui::PageSlaveFAN *ui;
    BMSInterface *mDieBieMS;
};

#endif // PAGESLAVEFAN_H
