#ifndef DEPOSITCALCULATOR_H
#define DEPOSITCALCULATOR_H

#include <QWidget>
#include "../controller/controller.h"

namespace Ui {
class DepositView;
}

class DepositView : public QWidget
{
    Q_OBJECT

public:
    explicit DepositView(Controller* c, QWidget *parent = nullptr);
    ~DepositView();

public:
    Ui::DepositView *ui;
    Controller* controller;
};

#endif // DEPOSITCALCULATOR_H
