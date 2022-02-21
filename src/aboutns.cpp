#include "aboutns.h"
#include "ui_aboutns.h"

aboutNS::aboutNS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutNS)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::ToolTip);
    QPixmap nscnLogo(":/icon/avatar_nscnEdit");
    nscnLogo=nscnLogo.scaled(100,100, Qt::KeepAspectRatio);
    ui->nscnlabel->setPixmap(nscnLogo);
    ui->aboutLabel->setOpenExternalLinks(true);
}

aboutNS::~aboutNS()
{
    delete ui;
}

void aboutNS::on_closeBtn_clicked()
{
    this->close();
}

