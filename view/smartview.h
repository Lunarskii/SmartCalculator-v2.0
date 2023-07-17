#ifndef CPP3_SMARTCALC_V2_0_VIEW_SMARTCALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_VIEW_SMARTCALCULATOR_H_

#include <QWidget>
#include "qcustomplot.h"
#include "../controller/controller.h"
#include ".ui/ui_smartview.h"

namespace s21 { class SmartView; }

namespace s21 {

class SmartView : public QWidget, public Ui_SmartView
{
    Q_OBJECT

public:
    SmartView(Controller* c = nullptr, QWidget *parent = nullptr);
    ~SmartView();

private slots:
    void on_pushButton_equal_clicked();
    void updateExpressionWindow();
    void on_pushButton_PLOT_clicked();

public:
    s21::SmartView *ui;
    Controller* controller;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_VIEW_SMARTCALCULATOR_H_
