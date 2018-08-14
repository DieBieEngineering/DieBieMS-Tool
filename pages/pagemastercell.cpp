#include "pagemastercell.h"
#include "ui_pagemastercell.h"

PageMasterCell::PageMasterCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageMasterCell)
{
    ui->setupUi(this);
    mDieBieMS = 0;
}

PageMasterCell::~PageMasterCell()
{
    delete ui;
}

BMSInterface *PageMasterCell::bms() const
{
    return mDieBieMS;
}

void PageMasterCell::setDieBieMS(BMSInterface *dieBieMS)
{
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ui->specificationsTab->addParamRow(mDieBieMS->bmsConfig(), "noOfCells");
        ui->specificationsTab->addParamRow(mDieBieMS->bmsConfig(), "batteryCapacity");
        ui->specificationsTab->addParamRow(mDieBieMS->bmsConfig(), "cellHardUnderVoltage");
        ui->specificationsTab->addParamRow(mDieBieMS->bmsConfig(), "cellHardOverVoltage");
        ui->specificationsTab->addParamRow(mDieBieMS->bmsConfig(), "cellLCSoftUnderVoltage");
        ui->specificationsTab->addParamRow(mDieBieMS->bmsConfig(), "cellHCSoftUnderVoltage");
        ui->specificationsTab->addParamRow(mDieBieMS->bmsConfig(), "cellSoftOverVoltage");
        ui->specificationsTab->addParamRow(mDieBieMS->bmsConfig(), "maxUnderAndOverVoltageErrorCount");
        ui->specificationsTab->addParamRow(mDieBieMS->bmsConfig(), "hysteresisDischarge");
        ui->specificationsTab->addParamRow(mDieBieMS->bmsConfig(), "hysteresisCharge");

        ui->balancingTab->addParamRow(mDieBieMS->bmsConfig(), "cellBalanceStart");
        ui->balancingTab->addParamRow(mDieBieMS->bmsConfig(), "cellBalanceDifferenceThreshold");
        ui->balancingTab->addParamRow(mDieBieMS->bmsConfig(), "cellBalanceUpdateInterval");
        ui->balancingTab->addParamRow(mDieBieMS->bmsConfig(), "maxSimultaneousDischargingCells");

        ui->throttlingTab->addRowSeparator(tr("Discharge"));
        ui->throttlingTab->addParamRow(mDieBieMS->bmsConfig(), "cellThrottleLowerStart");
        ui->throttlingTab->addParamRow(mDieBieMS->bmsConfig(), "cellThrottleLowerMargin");
        ui->throttlingTab->addParamRow(mDieBieMS->bmsConfig(), "throttleDisChargeIncreaseRate");
        ui->throttlingTab->addRowSeparator(tr("Charge"));
        ui->throttlingTab->addParamRow(mDieBieMS->bmsConfig(), "cellThrottleUpperStart");
        ui->throttlingTab->addParamRow(mDieBieMS->bmsConfig(), "cellThrottleUpperMargin");
        ui->throttlingTab->addParamRow(mDieBieMS->bmsConfig(), "throttleChargeIncreaseRate");

        ui->socTab->addParamRow(mDieBieMS->bmsConfig(), "soCMethod");
        ui->socTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutChargeCompleted");
        ui->socTab->addParamRow(mDieBieMS->bmsConfig(), "timeoutChargingCompletedMinimalMismatch");
        ui->socTab->addParamRow(mDieBieMS->bmsConfig(), "maxMismatchThreshold");
        ui->socTab->addParamRow(mDieBieMS->bmsConfig(), "stateOfChargeStoreInterval");
    }
}





