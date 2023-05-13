#include "creditview.h"

namespace s21 {

CreditView::CreditView(Controller* c, QWidget *parent) 
    : controller(c)
    , QWidget(parent)
    , ui(new s21::CreditView)
{
    ui->setupUi(this);
}

CreditView::~CreditView()
{
    delete ui;
}

void CreditView::on_creditEqual_clicked()
{
    bool RETURN_CODE = false;
    long double rate, creditAmount = ui->creditAmount->text().toDouble(&RETURN_CODE);
    int period, type;

    if (RETURN_CODE) rate = ui->percentRate->text().toDouble(&RETURN_CODE);
    if (RETURN_CODE) period = ui->creditPeriod->text().toDouble(&RETURN_CODE);
    if (RETURN_CODE)
    {
        type = ui->type_annuity->isChecked() ? ANNUITY : DIFFERENTIATED;
        controller->setCreditCalculatorData(creditAmount, rate, period, type);

        if (type == ANNUITY)
        {
            ui->monthlyPayment->setText(QString::number(controller->getPayment(), 'g', 10));
        }
        else
        {
            ui->monthlyPayment->setText(QString::number(controller->getMax(), 'g', 10) + " - " + QString::number(controller->getMin(), 'g', 10));
        }
        ui->overpayment->setText(QString::number(controller->getOverpayment(), 'g', 10));
        ui->totalPayment->setText(QString::number(controller->getTotalPayment(), 'g', 10));
    }
}

}  // namespace s21
