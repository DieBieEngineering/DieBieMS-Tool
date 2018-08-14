#include "pageslaveswitch.h"
#include "ui_pageslaveswitch.h"

PageSlaveSwitch::PageSlaveSwitch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSlaveSwitch)
{
    ui->setupUi(this);
    mDieBieMS = 0;
}

PageSlaveSwitch::~PageSlaveSwitch()
{
    delete ui;
}

BMSInterface *PageSlaveSwitch::bms() const {
    return mDieBieMS;
}

void PageSlaveSwitch::setDieBieMS(BMSInterface *dieBieMS) {
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ui->switchTab->addParamRow(mDieBieMS->bmsConfig(), "HCUseRelay");
        ui->switchTab->addParamRow(mDieBieMS->bmsConfig(), "HCUsePrecharge");
        ui->switchTab->addParamRow(mDieBieMS->bmsConfig(), "togglePowerModeDirectHCDelay");
        ui->switchTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutHCPreCharge");
        ui->switchTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutHCPreChargeRetryInterval");
        ui->switchTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutHCRelayOverlap");
    }
}
