#ifndef SMARTCALCULATOR_H
#define SMARTCALCULATOR_H

#include <QWidget>
#include "qcustomplot.h"
#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SmartView; }
QT_END_NAMESPACE

class SmartView : public QWidget
{
    Q_OBJECT

public:
    SmartView(Controller* c, QWidget *parent = nullptr);
    ~SmartView();

private slots:
    void on_pushButton_equal_clicked();
    void updateExpressionWindow();
    void on_pushButton_PLOT_clicked();

public:
    Ui::SmartView *ui;
    Controller* controller;
};
#endif // SMARTCALCULATOR_H
