#ifndef CPP3_SMARTCALC_V2_0_VIEW_VIEW_H_
#define CPP3_SMARTCALC_V2_0_VIEW_VIEW_H_

#include <QMainWindow>
#include <QButtonGroup>

#include "../structures.h"
#include "../qcustomplot.h"
#include "ui_view.h"

namespace Ui { class View; }

namespace s21 {

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget* parent = nullptr);
    ~View();

signals:
    void SetModel(std::string expression, long double x);
    void SetModel(CreditData credit_data);
    void SetModel(DepositData deposit_data);
    void AddDeposit(long double amount, int frequency);
    void AddWithdrawal(long double amount, int frequency);

private slots:
    void HandleSolution_(std::string result);
    void HandleSolution_(CreditResult credit_result);
    void HandleSolution_(DepositResult deposit_result);
    void SendDataToSmartModel_();
    void SendDataToCreditModel_();
    void SendDataToDepositModel_();
    void UpdateExpressionWindow_(QAbstractButton* button);
    void BuildGraph_();
    void ClearExpressionWindow_();
    void ChangeTab_(QAbstractButton* button);
    void AddNewDepositToTable_();
    void AddNewWithdrawalToTable_();
    void RemoveDepositFromTable_();
    void RemoveWithdrawalFromTable_();

private:
    int GetFrequency_(QString text);
    void SendAllDepositsToModel_();
    void SendAllWithdrawalsToModel_();
    
private:
    Ui::View* ui;
    QString result_expression{};
    CreditData credit_data;
    DepositData deposit_data;
    static const std::string funcs[];
};

}  // namespace s21

#endif // CPP3_SMARTCALC_V2_0_VIEW_VIEW_H_
