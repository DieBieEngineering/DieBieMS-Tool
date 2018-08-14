#ifndef PAGEMASTERSWITCH_H
#define PAGEMASTERSWITCH_H

#include <QWidget>
#include "bmsinterface.h"

namespace Ui {
class PageMasterSwitch;
}

class PageMasterSwitch : public QWidget
{
    Q_OBJECT

public:
    explicit PageMasterSwitch(QWidget *parent = 0);
    ~PageMasterSwitch();

    BMSInterface *bms() const;
    void setDieBieMS(BMSInterface *dieBieMS);

private:
    Ui::PageMasterSwitch *ui;
    BMSInterface *mDieBieMS;
};

#endif // PAGEMASTERSWITCH_H
