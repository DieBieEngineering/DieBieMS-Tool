#include "pageslavefan.h"
#include "ui_pageslavefan.h"

PageSlaveFAN::PageSlaveFAN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSlaveFAN)
{
    ui->setupUi(this);
    mDieBieMS = 0;
}

PageSlaveFAN::~PageSlaveFAN()
{
    delete ui;
}

BMSInterface *PageSlaveFAN::bms() const {
    return mDieBieMS;
}

void PageSlaveFAN::setDieBieMS(BMSInterface *dieBieMS) {
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ui->slaveFANTab->addRowSeparator(tr("TBD"));
    }
}
