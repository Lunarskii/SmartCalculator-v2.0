#ifndef CREDITCALCULATOR_H
#define CREDITCALCULATOR_H

#include <QWidget>
#include "../controller/controller.h"

namespace Ui {
class CreditView;
}

class CreditView : public QWidget
{
    Q_OBJECT

public:
    explicit CreditView(Controller* c, QWidget *parent = nullptr);
    ~CreditView();

public:
    Ui::CreditView *ui;
    Controller* controller;
};

#endif // CREDITCALCULATOR_H
