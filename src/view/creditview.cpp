#include "creditview.h"
#include "ui_creditview.h"

CreditView::CreditView(Controller* c, QWidget *parent) 
    : controller(c)
    , QWidget(parent)
    , ui(new Ui::CreditView)
{
    ui->setupUi(this);
}

CreditView::~CreditView()
{
    delete ui;
}
