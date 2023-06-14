#include "view.h"

namespace s21 {

void View::HandleSolution_(std::string result)
{
    result_expression = QString::fromStdString(result);
}

void View::HandleSolution_(CreditResult credit_result)
{
    if (credit_data.type == kAnnuity)
    {
        ui->monthlyPayment->setText(QString::number(credit_result.payment, 'g', 10));
    }
    else
    {
        ui->monthlyPayment->setText(QString::number(credit_result.max_payment, 'g', 10) + " - " + QString::number(credit_result.min_payment, 'g', 10));
    }
    ui->overpayment->setText(QString::number(credit_result.overpayment, 'g', 10));
    ui->totalPayment->setText(QString::number(credit_result.total_payment, 'g', 10));
}

void View::HandleSolution_(DepositResult deposit_result)
{
    ui->interest->setText(QString::number(deposit_result.interest, 'g', 10));
    ui->tax->setText(QString::number(deposit_result.tax, 'g', 10));
    ui->amount->setText(QString::number(deposit_result.amount, 'g', 10));
}

}  // namespace s21