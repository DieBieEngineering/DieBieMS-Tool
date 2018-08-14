#ifndef PAGEMASTERSETTINGS_H
#define PAGEMASTERSETTINGS_H

#include <QWidget>
#include "bmsinterface.h"

namespace Ui {
class PageMasterSettings;
}

class PageMasterSettings : public QWidget
{
    Q_OBJECT

public:
    explicit PageMasterSettings(QWidget *parent = 0);
    ~PageMasterSettings();

    BMSInterface *bms() const;
    void setDieBieMS(BMSInterface *dieBieMS);

private:
    Ui::PageMasterSettings *ui;
    BMSInterface *mDieBieMS;
};

#endif // PAGEMASTERSETTINGS_H
