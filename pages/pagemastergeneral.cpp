#include "pagemastergeneral.h"
#include "ui_pagemastergeneral.h"

PageMasterGeneral::PageMasterGeneral(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageMasterGeneral)
{
    ui->setupUi(this);
    mDieBieMS = 0;
}

PageMasterGeneral::~PageMasterGeneral()
{
    delete ui;
}

BMSInterface *PageMasterGeneral::bms() const
{
    return mDieBieMS;
}

void PageMasterGeneral::setDieBieMS(BMSInterface *dieBieMS)
{
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "allowForceOn");
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "pulseToggleButton");
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "notUsedCurrentThreshold");
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "notUsedTimeout");


        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "CANID");
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "CANIDStyle");
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "emitStatusOverCAN");
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "useCANSafetyInput");
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "useCANDelayedPowerDown");

        ui->masterSensorsTab->addRowSeparator(tr("Shunt"));
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "shuntLCFactor");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "shuntLCOffset");
        ui->masterSensorsTab->addRowSeparator(tr("NTC enable mask"));
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "tempEnableMaskBMS");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "tempEnableMaskBattery");
        ui->masterSensorsTab->addRowSeparator(tr("NTC specifications"));
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCPCBTopResistor");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCPCB25Deg");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCPCBBeta");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCLTCTopResistor");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCLTC25Deg");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCLTCBeta");
    }
}
