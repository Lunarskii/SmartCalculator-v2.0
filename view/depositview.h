#ifndef CPP3_SMARTCALC_V2_0_VIEW_DEPOSITCALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_VIEW_DEPOSITCALCULATOR_H_

#include <QWidget>
#include <QComboBox>
#include "../controller/controller.h"
#include ".ui/ui_depositview.h"

namespace s21 { class DepositView; }

namespace s21 {

class DepositView : public QWidget, public Ui_DepositView
{
    Q_OBJECT

public:
    explicit DepositView(Controller* c = nullptr, QWidget *parent = nullptr);
    ~DepositView();
    int getFrequency(QString text);
    void addAllDeposits();
    void addAllWithdrawals();

private slots:
    void on_depositEqual_clicked();
    void on_addDeposit_clicked();
    void on_addWithdrawal_clicked();
    void on_removeDeposit_clicked();
    void on_removeWithdrawal_clicked();

public:
    s21::DepositView *ui;
    Controller* controller;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_VIEW_DEPOSITCALCULATOR_H_
