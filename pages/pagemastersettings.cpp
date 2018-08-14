#include "pagemastersettings.h"
#include "ui_pagemastersettings.h"

PageMasterSettings::PageMasterSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageMasterSettings)
{
    ui->setupUi(this);
    layout()->setContentsMargins(0, 0, 0, 0);
    mDieBieMS = 0;
}

PageMasterSettings::~PageMasterSettings()
{
    delete ui;
}

BMSInterface *PageMasterSettings::bms() const
{
    return mDieBieMS;
}

void PageMasterSettings::setDieBieMS(BMSInterface *dieBieMS)
{
    mDieBieMS = dieBieMS;

    if (mDieBieMS) {
        ConfigParam *p = mDieBieMS->infoConfig()->getParam("master_setting_description");
        if (p != 0) {
            ui->textEdit->setHtml(p->description);
        } else {
            ui->textEdit->setText("Master Setting Description not found.");
        }
    }
}
