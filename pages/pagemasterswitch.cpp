#include "pagemasterswitch.h"
#include "ui_pagemasterswitch.h"

PageMasterSwitch::PageMasterSwitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageMasterSwitch)
{
    ui->setupUi(this);
    mDieBieMS = 0;
}

PageMasterSwitch::~PageMasterSwitch()
{
    delete ui;
}

BMSInterface *PageMasterSwitch::bms() const
{
    return mDieBieMS;
}

void PageMasterSwitch::setDieBieMS(BMSInterface *dieBieMS)
{
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "LCUseDischarge");
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "LCUsePrecharge");
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "minimalPrechargePercentage");
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutLCPreCharge");
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutDischargeRetry");        
        ui->dischargeTab->addParamRow(mDieBieMS->bmsConfig(), "maxAllowedCurrent");

        ui->chargeTab->addParamRow(mDieBieMS->bmsConfig(), "chargerEnabledThreshold");
        ui->chargeTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutChargerDisconnected");
        ui->chargeTab->addParamRow(mDieBieMS->bmsConfig(), "allowChargingDuringDischarge");
        ui->chargeTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutChargeRetry");
    }
}
