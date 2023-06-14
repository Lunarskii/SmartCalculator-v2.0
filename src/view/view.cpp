#include "view.h"

namespace s21 {

const std::string View::funcs[] = {"cos", "sin", "tan", "acos", "asin", "atan", "sqrt", "ln", "log"};

View::View(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    setlocale(LC_NUMERIC, "C");
    ui->setupUi(this);
    setFixedSize(415, 683);

    connect(ui->smartButtons, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(UpdateExpressionWindow_(QAbstractButton *)));
    connect(ui->tabs1, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(ChangeTab_(QAbstractButton *)));
    connect(ui->tabs2, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(ChangeTab_(QAbstractButton *)));
    connect(ui->tabs3, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(ChangeTab_(QAbstractButton *)));
    connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(SendDataToSmartModel_()));
    connect(ui->pushButton_PLOT, SIGNAL(clicked()), this, SLOT(BuildGraph_()));
    connect(ui->pushButton_undo, SIGNAL(clicked()), this, SLOT(ClearExpressionWindow_()));
    connect(ui->creditEqual, SIGNAL(clicked()), this, SLOT(SendDataToCreditModel_()));
    connect(ui->depositEqual, SIGNAL(clicked()), this, SLOT(SendDataToDepositModel_()));
    connect(ui->addDeposit, SIGNAL(clicked()), this, SLOT(AddNewDepositToTable_()));
    connect(ui->addWithdrawal, SIGNAL(clicked()), this, SLOT(AddNewWithdrawalToTable_()));
    connect(ui->removeDeposit, SIGNAL(clicked()), this, SLOT(RemoveDepositFromTable_()));
    connect(ui->removeWithdrawal, SIGNAL(clicked()), this, SLOT(RemoveWithdrawalFromTable_()));
}

View::~View()
{
    for (int row = 0; row < ui->deposits->rowCount(); ++row)
    {
        QTableWidgetItem* amount_item = ui->deposits->item(row, 0);
        QWidget* widget = ui->deposits->cellWidget(row, 1);

        delete amount_item;
        delete widget;
    }
    for (int row = 0; row < ui->withdrawals->rowCount(); ++row)
    {
        QTableWidgetItem* amount_item = ui->withdrawals->item(row, 0);
        QWidget* widget = ui->withdrawals->cellWidget(row, 1);

        delete amount_item;
        delete widget;
    }
    delete ui;
}

void View::SendDataToSmartModel_()
{
    bool return_code = false;
    long double x = ui->xValue->text().toDouble(&return_code);

    if (return_code == true) {
        emit SetModel(ui->expressionWindow->text().toStdString(), x);
        ui->expressionWindow->setText(result_expression);
    } else {
        ui->expressionWindow->setText("x is invalid");
    }
}

void View::UpdateExpressionWindow_(QAbstractButton* button)
{
    QString text = button->text();

    if (ui->expressionWindow->text() == '0' && text != ".") ui->expressionWindow->setText("");
    ui->expressionWindow->setText(ui->expressionWindow->text() += text);
    for (std::size_t i = 0; i < 9; ++i)
    {
        if (text.toStdString() == funcs[i])
        {
            ui->expressionWindow->setText(ui->expressionWindow->text() += '(');
        }
    }
}

void View::BuildGraph_()
{
    bool return_code = 0;
    int max_x = 0, min_x = 0, max_y = 0, min_y = 0;

    max_x = ui->maxX->text().toInt(&return_code);
    if (return_code) max_y = ui->maxY->text().toInt(&return_code);
    if (return_code) min_x = ui->minX->text().toInt(&return_code);
    if (return_code) min_y = ui->minY->text().toInt(&return_code);
    if (return_code) {
        int rangeX = max_x - min_x;
        std::string expression = ui->expressionWindow->text().toStdString();
        QVector<double> x(1024), y(1024);
        QPen bluePen;

        for (int i = 0; return_code && i < 1024; ++i) {
          x[i] = min_x + rangeX * (i / 1024.0);
          try {
            emit SetModel(expression, static_cast<long double>(x[i]));
          }
          catch (std::exception& e)
          {
            return;
          }

          if (result_expression == "inf")
            y[i] = INFINITY;
          else if (result_expression == "-nan")
            y[i] = NAN;
          else if (result_expression == "ERROR")
            return_code = false;
          else
            y[i] = result_expression.toDouble();
        }

        if (return_code)
        {
            ui->customPlot->addGraph();
            bluePen.setColor(QColor(30, 40, 255, 150));
            bluePen.setStyle(Qt::SolidLine);
            bluePen.setWidthF(5);
            ui->customPlot->graph(0)->setPen(bluePen);
            ui->customPlot->graph(0)->setData(x, y);
            ui->customPlot->xAxis->setLabel("x");
            ui->customPlot->yAxis->setLabel("y");
            ui->customPlot->xAxis->setRange(min_x, max_x);
            ui->customPlot->yAxis->setRange(min_y, max_y);
            ui->customPlot->replot();
        }
    }
}

void View::ClearExpressionWindow_()
{
    ui->expressionWindow->setText("0");
}

void View::ChangeTab_(QAbstractButton* button)
{
    std::size_t tab_index = ui->tabWidget->currentIndex();

    if (button == ui->Credit1 || button == ui->Credit3 && tab_index != 1)
    {
        ui->tabWidget->setCurrentIndex(1);
        setFixedSize(530, 340);
    }
    else if (button == ui->Deposit1 || button == ui->Deposit2 && tab_index != 2)
    {
        ui->tabWidget->setCurrentIndex(2);
        setFixedSize(530, 650);
    }
    else if (button == ui->Smart2 || button == ui->Smart3 && tab_index != 0)
    {
        ui->tabWidget->setCurrentIndex(0);
        setFixedSize(415, 683);
    }
}

void View::SendDataToCreditModel_()
{
    bool return_code = false;

    credit_data.amount = ui->creditAmount->text().toDouble(&return_code);
    if (return_code) credit_data.rate = ui->percentRate->text().toDouble(&return_code);
    if (return_code) credit_data.period = ui->creditPeriod->text().toDouble(&return_code);
    if (return_code)
    {
        credit_data.type = ui->type_annuity->isChecked() ? kAnnuity : kDifferentiated;
        emit SetModel(credit_data);
    }
}

int View::GetFrequency_(QString text)
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

void View::SendAllDepositsToModel_()
{
    for (int row = 0; row < ui->deposits->rowCount(); ++row)
    {
        QTableWidgetItem* amount_item = ui->deposits->item(row, 0);

        long double amount = amount_item->text().toDouble();
        QWidget* widget = ui->deposits->cellWidget(row, 1);
        QComboBox* comboBox = qobject_cast<QComboBox*>(widget);

        emit AddDeposit(amount, GetFrequency_(comboBox->currentText()));
    }
}

void View::SendAllWithdrawalsToModel_()
{
    for (int row = 0; row < ui->withdrawals->rowCount(); ++row) {
        QTableWidgetItem* amount_item = ui->withdrawals->item(row, 0);

        long double amount = amount_item->text().toDouble();
        QWidget* widget = ui->withdrawals->cellWidget(row, 1);
        QComboBox* comboBox = qobject_cast<QComboBox*>(widget);

        emit AddWithdrawal(amount, GetFrequency_(comboBox->currentText()));
    }
}

void View::SendDataToDepositModel_()
{
    bool return_code = false;

    deposit_data.amount = ui->depositAmount->text().toDouble(&return_code);
    if (return_code) deposit_data.rate = ui->rate->text().toDouble(&return_code);
    if (return_code) deposit_data.tax_rate = ui->taxRate->text().toDouble(&return_code);
    if (return_code) deposit_data.period = ui->period->text().toInt(&return_code);
    if (return_code)
    {
        QWidget* widget = ui->frequency;
        QComboBox* comboBox = qobject_cast<QComboBox*>(widget);
        QString text = comboBox->currentText();

        if (text == "1 раз в месяц")
        {
            deposit_data.frequency = 12;
        }
        else if (text == "1 раз в полгода")
        {
            deposit_data.frequency = 2;
        }
        else if (text == "1 раз в год")
        {
            deposit_data.frequency = 1;
        }

        deposit_data.capitalization = ui->capitalization->isChecked() ? true : false;
        SendAllDepositsToModel_();
        SendAllWithdrawalsToModel_();
        emit SetModel(deposit_data);
    }
}

void View::AddNewDepositToTable_()
{
    int row = ui->deposits->rowCount();
    ui->deposits->insertRow(row);
    if (row == 0)
    {
        ui->deposits->insertColumn(0);
        ui->deposits->insertColumn(1);
    }

    QTableWidgetItem* amount_item = new QTableWidgetItem(QString("0.00"));
    QComboBox* frequency_combo_box = new QComboBox();
    frequency_combo_box->addItem("1 раз в месяц");
    frequency_combo_box->addItem("1 раз в полгода");
    frequency_combo_box->addItem("1 раз в год");

    ui->deposits->setItem(row, 0, amount_item);
    ui->deposits->setCellWidget(row, 1, frequency_combo_box);
}

void View::AddNewWithdrawalToTable_()
{
    int row = ui->withdrawals->rowCount();
    ui->withdrawals->insertRow(row);
    if (row == 0)
    {
        ui->withdrawals->insertColumn(0);
        ui->withdrawals->insertColumn(1);
    }

    QTableWidgetItem* amount_item = new QTableWidgetItem(QString("0.00"));
    QComboBox* frequency_combo_box = new QComboBox();
    frequency_combo_box->addItem("1 раз в месяц");
    frequency_combo_box->addItem("1 раз в полгода");
    frequency_combo_box->addItem("1 раз в год");

    ui->withdrawals->setItem(row, 0, amount_item);
    ui->withdrawals->setCellWidget(row, 1, frequency_combo_box);
}

void View::RemoveDepositFromTable_()
{
    int row = ui->deposits->rowCount() - 1;

    if (row >= 0)
    {
        QTableWidgetItem* amount_item = ui->deposits->item(row, 0);
        QWidget* widget = ui->deposits->cellWidget(row, 1);

        delete amount_item;
        delete widget;
        ui->deposits->removeRow(row);
        if (row == 0)
        {
            ui->deposits->removeColumn(1);
            ui->deposits->removeColumn(0);
        }
    }
}

void View::RemoveWithdrawalFromTable_()
{
    int row = ui->withdrawals->rowCount() - 1;

    if (row >= 0)
    {
        QTableWidgetItem* amount_item = ui->withdrawals->item(row, 0);
        QWidget* widget = ui->withdrawals->cellWidget(row, 1);

        delete amount_item;
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
