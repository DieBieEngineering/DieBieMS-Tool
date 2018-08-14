#ifndef PAGEMASTERCELL_H
#define PAGEMASTERCELL_H

#include <QWidget>
#include "bmsinterface.h"

namespace Ui {
class PageMasterCell;
}

class PageMasterCell : public QWidget
{
    Q_OBJECT

public:
    explicit PageMasterCell(QWidget *parent = 0);
    ~PageMasterCell();

    BMSInterface *bms() const;
    void setDieBieMS(BMSInterface *dieBieMS);

private:
    Ui::PageMasterCell *ui;
    BMSInterface *mDieBieMS;
};

#endif // PAGEMASTERCELL_H
