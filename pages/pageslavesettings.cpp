#include "pageslavesettings.h"
#include "ui_pageslavesettings.h"

PageSlaveSettings::PageSlaveSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageSlaveSettings)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mDieBieMS = 0;
}

PageSlaveSettings::~PageSlaveSettings()
{
    delete ui;
}

BMSInterface *PageSlaveSettings::bms() const
{
    return mDieBieMS;
}

void PageSlaveSettings::setDieBieMS(BMSInterface *dieBieMS)
{
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ConfigParam *p = mDieBieMS->infoConfig()->getParam("slave_setting_description");
        if (p != 0) {
            ui->textEdit->setHtml(p->description);
        } else {
            ui->textEdit->setText("Slave Setting Description not found.");
        }
    }
}
