#include "pageslavegeneral.h"
#include "ui_pageslavegeneral.h"

PageSlaveGeneral::PageSlaveGeneral(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSlaveGeneral)
{
    ui->setupUi(this);
    mDieBieMS = 0;
}

PageSlaveGeneral::~PageSlaveGeneral()
{
    delete ui;
}

BMSInterface *PageSlaveGeneral::bms() const {
    return mDieBieMS;
}

void PageSlaveGeneral::setDieBieMS(BMSInterface *dieBieMS) {
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ui->slaveSensorsTab->addRowSeparator(tr("NTC specifications"));
        ui->slaveSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCHiAmpPCBTopResistor");
        ui->slaveSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCHiAmpPCB25Deg");
        ui->slaveSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCHiAmpPCBBeta");
        ui->slaveSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCHiAmpExtTopResistor");
        ui->slaveSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCHiAmpExt25Deg");
        ui->slaveSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCHiAmpExtBeta");
    }
}
