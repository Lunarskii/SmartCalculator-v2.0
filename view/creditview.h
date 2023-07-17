#ifndef CPP3_SMARTCALC_V2_0_VIEW_CREDITCALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_VIEW_CREDITCALCULATOR_H_

#include <QWidget>
#include "../controller/controller.h"
#include ".ui/ui_creditview.h"

namespace s21 { class CreditView; }

namespace s21 {

class CreditView : public QWidget, public Ui_CreditView
{
    Q_OBJECT

public:
    explicit CreditView(Controller* c = nullptr, QWidget *parent = nullptr);
    ~CreditView();

private slots:
    void on_creditEqual_clicked();

public:
    s21::CreditView *ui;
    Controller* controller;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_VIEW_CREDITCALCULATOR_H_
