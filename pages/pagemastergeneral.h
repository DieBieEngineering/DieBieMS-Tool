#ifndef PAGEMASTERGENERAL_H
#define PAGEMASTERGENERAL_H

#include <QWidget>
#include "bmsinterface.h"

namespace Ui {
class PageMasterGeneral;
}

class PageMasterGeneral : public QWidget
{
    Q_OBJECT

public:
    explicit PageMasterGeneral(QWidget *parent = 0);
    ~PageMasterGeneral();

    BMSInterface *bms() const;
    void setDieBieMS(BMSInterface *dieBieMS);

private:
    Ui::PageMasterGeneral *ui;
    BMSInterface *mDieBieMS;
};

#endif // PAGEMASTERGENERAL_H
