#include "depositview.h"

namespace s21 {

DepositView::DepositView(Controller* c, QWidget *parent) 
    : controller(c)
    , QWidget(parent)
    , ui(new s21::DepositView)
{
    ui->setupUi(this);
}

DepositView::~DepositView()
{
    for (int row = 0; row < ui->deposits->rowCount(); ++row)
    {
        QTableWidgetItem* amountItem = ui->deposits->item(row, 0);
        QWidget* widget = ui->deposits->cellWidget(row, 1);

        delete amountItem;
        delete widget;
    }
    for (int row = 0; row < ui->withdrawals->rowCount(); ++row)
    {
        QTableWidgetItem* amountItem = ui->withdrawals->item(row, 0);
        QWidget* widget = ui->withdrawals->cellWidget(row, 1);

        delete amountItem;
        delete widget;
    }
    delete ui;
}

int DepositView::getFrequency(QString text)
{
    if (text == "1 раз в месяц")
    {
        return 1;
    }
    else if (text == "1 раз в полгода")
    {
        return 6;
    }
    else if (text == "1 раз в год")
    {
        return 12;
    }

    return 0;
}

void DepositView::addAllDeposits()
{
    for (int row = 0; row < ui->deposits->rowCount(); ++row)
    {
        QTableWidgetItem* amountItem = ui->deposits->item(row, 0);

        long double amount = amountItem->text().toDouble();
        QWidget* widget = ui->deposits->cellWidget(row, 1);
        QComboBox* comboBox = qobject_cast<QComboBox*>(widget);

        controller->addDeposit(amount, getFrequency(comboBox->currentText()));
    }
}

void DepositView::addAllWithdrawals()
{
    for (int row = 0; row < ui->withdrawals->rowCount(); ++row) {
        QTableWidgetItem* amountItem = ui->withdrawals->item(row, 0);

        long double amount = amountItem->text().toDouble();
        QWidget* widget = ui->withdrawals->cellWidget(row, 1);
        QComboBox* comboBox = qobject_cast<QComboBox*>(widget);

        controller->addWithdrawal(amount, getFrequency(comboBox->currentText()));
    }
}

void DepositView::on_depositEqual_clicked()
{
    bool RETURN_CODE = false;
    long double depositAmount, rate, taxRate;
    int period, frequency;
    bool capitalization;

    depositAmount = ui->depositAmount->text().toDouble(&RETURN_CODE);
    if (RETURN_CODE) period = ui->period->text().toInt(&RETURN_CODE);
    if (RETURN_CODE) rate = ui->rate->text().toDouble(&RETURN_CODE);
    if (RETURN_CODE) taxRate = ui->taxRate->text().toDouble(&RETURN_CODE);
    if (RETURN_CODE)
    {
        QWidget* widget = ui->frequency;
        QComboBox* comboBox = qobject_cast<QComboBox*>(widget);
        QString text = comboBox->currentText();
        int frequency = 0;

        if (text == "1 раз в месяц")
        {
            frequency = 12;
        }
        else if (text == "1 раз в полгода")
        {
            frequency = 2;
        }
        else if (text == "1 раз в год")
        {
            frequency = 1;
        }

        capitalization = ui->capitalization->isChecked() ? true : false;
        addAllDeposits();
        addAllWithdrawals();

        controller->setDepositCalculatorData(depositAmount, period, rate, taxRate, frequency, capitalization);

        ui->interest->setText(QString::number(controller->getEarnedInterest(), 'g', 10));
        ui->tax->setText(QString::number(controller->getTax(), 'g', 10));
        ui->amount->setText(QString::number(controller->getAmount(), 'g', 10));
    }
}

void DepositView::on_addDeposit_clicked()
{
    int row = ui->deposits->rowCount();
    ui->deposits->insertRow(row);
    if (row == 0)
    {
        ui->deposits->insertColumn(0);
        ui->deposits->insertColumn(1);
    }

    QTableWidgetItem* amountItem = new QTableWidgetItem(QString("0.00"));
    QComboBox* frequencyComboBox = new QComboBox();
    frequencyComboBox->addItem("1 раз в месяц");
    frequencyComboBox->addItem("1 раз в полгода");
    frequencyComboBox->addItem("1 раз в год");

    ui->deposits->setItem(row, 0, amountItem);
    ui->deposits->setCellWidget(row, 1, frequencyComboBox);
}

void DepositView::on_addWithdrawal_clicked()
{
    int row = ui->withdrawals->rowCount();
    ui->withdrawals->insertRow(row);
    if (row == 0)
    {
        ui->withdrawals->insertColumn(0);
        ui->withdrawals->insertColumn(1);
    }

    QTableWidgetItem* amountItem = new QTableWidgetItem(QString("0.00"));
    QComboBox* frequencyComboBox = new QComboBox();
    frequencyComboBox->addItem("1 раз в месяц");
    frequencyComboBox->addItem("1 раз в полгода");
    frequencyComboBox->addItem("1 раз в год");

    ui->withdrawals->setItem(row, 0, amountItem);
    ui->withdrawals->setCellWidget(row, 1, frequencyComboBox);
}

void DepositView::on_removeDeposit_clicked()
{
    int row = ui->deposits->rowCount() - 1;

    if (row >= 0)
    {
        QTableWidgetItem* amountItem = ui->deposits->item(row, 0);
        QWidget* widget = ui->deposits->cellWidget(row, 1);

        delete amountItem;
        delete widget;
        ui->deposits->removeRow(row);
        if (row == 0)
        {
            ui->deposits->removeColumn(1);
            ui->deposits->removeColumn(0);
        }
    }
}

void DepositView::on_removeWithdrawal_clicked()
{
    int row = ui->withdrawals->rowCount() - 1;

    if (row >= 0)
    {
        QTableWidgetItem* amountItem = ui->withdrawals->item(row, 0);
        QWidget* widget = ui->withdrawals->cellWidget(row, 1);

        delete amountItem;
        delete widget;
        ui->withdrawals->removeRow(row);
        if (row == 0)
        {
            ui->withdrawals->removeColumn(1);
            ui->withdrawals->removeColumn(0);
        }
    }
}

}  // namespace s21

