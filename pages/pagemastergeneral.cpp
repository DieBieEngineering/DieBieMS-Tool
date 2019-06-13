/*
    Original copyright 2018 Benjamin Vedder benjamin@vedder.se and the VESC Tool project ( https://github.com/vedderb/vesc_tool )
    Now forked to:
    Danny Bokma github@diebie.nl

    This file is part of BMS Tool.

    DieBieMS Tool is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    DieBieMS Tool is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
        ui->powerStateTab->addRowSeparator(tr("Onstate"));
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "pulseToggleButton");
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "notUsedCurrentThreshold");
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "notUsedTimeout");
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "powerDownDelay");
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "allowForceOn");
        ui->powerStateTab->addRowSeparator(tr("Jump to"));
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "extEnableState");
        ui->powerStateTab->addParamRow(mDieBieMS->bmsConfig(), "chargeEnableState");

        ui->masterLimitsTab->addRowSeparator(tr("Current"));
        ui->masterLimitsTab->addParamRow(mDieBieMS->bmsConfig(), "maxAllowedCurrent");
        ui->masterLimitsTab->addRowSeparator(tr("Temperature"));
        ui->masterLimitsTab->addParamRow(mDieBieMS->bmsConfig(), "allowedTempBattDischargingMax");
        ui->masterLimitsTab->addParamRow(mDieBieMS->bmsConfig(), "allowedTempBattDischargingMin");
        ui->masterLimitsTab->addParamRow(mDieBieMS->bmsConfig(), "allowedTempBattChargingMax");
        ui->masterLimitsTab->addParamRow(mDieBieMS->bmsConfig(), "allowedTempBattChargingMin");
        ui->masterLimitsTab->addParamRow(mDieBieMS->bmsConfig(), "allowedTempBMSMax");
        ui->masterLimitsTab->addParamRow(mDieBieMS->bmsConfig(), "allowedTempBMSMin");

        ui->canTab->addRowSeparator(tr("CAN Configuration"));
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "CANID");
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "CANIDStyle");
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "CANBaudRate");
        ui->canTab->addRowSeparator(tr("CAN Messaging"));
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "emitStatusOverCAN");
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "emitStatusProtocolType");
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "useCANSafetyInput");
        ui->canTab->addParamRow(mDieBieMS->bmsConfig(), "useCANDelayedPowerDown");

        ui->masterSensorsTab->addRowSeparator(tr("NTC specifications"));
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCPCBTopResistor");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCPCB25Deg");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCPCBBeta");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCLTCTopResistor");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCLTC25Deg");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "NTCLTCBeta");
        ui->masterSensorsTab->addRowSeparator(tr("NTC enable mask"));
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "tempEnableMaskBMS");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "tempEnableMaskBattery");
        ui->masterSensorsTab->addRowSeparator(tr("Water detect enable mask"));
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "waterSensorEnableMask");
        ui->masterSensorsTab->addParamRow(mDieBieMS->bmsConfig(), "waterSensorThreshold");
    }
}
