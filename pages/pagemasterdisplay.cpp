#include "pagemasterdisplay.h"
#include "ui_pagemasterdisplay.h"

PageMasterDisplay::PageMasterDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageMasterDisplay)
{
    ui->setupUi(this);
    mDieBieMS = 0;
}

PageMasterDisplay::~PageMasterDisplay()
{
    delete ui;
}

BMSInterface *PageMasterDisplay::bms() const
{
    return mDieBieMS;
}

void PageMasterDisplay::setDieBieMS(BMSInterface *dieBieMS)
{
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ui->durationsTab->addParamRow(mDieBieMS->bmsConfig(), "displayTimeoutBatteryDead");
        ui->durationsTab->addParamRow(mDieBieMS->bmsConfig(), "displayTimeoutBatteryError");
        ui->durationsTab->addParamRow(mDieBieMS->bmsConfig(), "displayTimeoutBatteryErrorPreCharge");
        ui->durationsTab->addParamRow(mDieBieMS->bmsConfig(), "displayTimeoutSplashScreen");

        ui->customTab->addRowSeparator(tr("TBD"));
    }
}
