#include "depositview.h"
#include "ui_depositview.h"

DepositView::DepositView(Controller* c, QWidget *parent) 
    : controller(c)
    , QWidget(parent)
    , ui(new Ui::DepositView)
{
    ui->setupUi(this);
}

DepositView::~DepositView()
{
    delete ui;
}
