#ifndef PAGEMASTERDISPLAY_H
#define PAGEMASTERDISPLAY_H

#include <QWidget>
#include "bmsinterface.h"

namespace Ui {
class PageMasterDisplay;
}

class PageMasterDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit PageMasterDisplay(QWidget *parent = 0);
    ~PageMasterDisplay();

    BMSInterface *bms() const;
    void setDieBieMS(BMSInterface *dieBieMS);

private:
    Ui::PageMasterDisplay *ui;
    BMSInterface *mDieBieMS;
};

#endif // PAGEMASTERDISPLAY_H
