#include "pageslaveio.h"
#include "ui_pageslaveio.h"

PageSlaveIO::PageSlaveIO(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSlaveIO)
{
    ui->setupUi(this);
    mDieBieMS = 0;
}

PageSlaveIO::~PageSlaveIO()
{
    delete ui;
}

BMSInterface *PageSlaveIO::bms() const {
    return mDieBieMS;
}

void PageSlaveIO::setDieBieMS(BMSInterface *dieBieMS) {
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ui->slaveIOTab->addRowSeparator(tr("TBD"));
    }
}
