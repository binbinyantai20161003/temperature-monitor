#include "connectdlg.h"
#include "ui_connectdlg.h"

ConnectDlg::ConnectDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);
}

ConnectDlg::~ConnectDlg()
{
    delete ui;
}
