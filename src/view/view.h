#ifndef CPP3_SMARTCALC_V2_0_VIEW_VIEW_H_
#define CPP3_SMARTCALC_V2_0_VIEW_VIEW_H_

#include <QMainWindow>
#include <QTabWidget>

#include ".ui/ui_view.h"
#include "smartview.h"
#include "creditview.h"
#include "depositview.h"
#include "../controller/controller.h"

namespace s21 { class View; }

namespace s21 {

class View : public QMainWindow, public Ui_View
{
    Q_OBJECT

public:
    explicit View(Controller* c = nullptr, QWidget* parent = nullptr);
    ~View();

private slots:

private:
    s21::View* ui;
    Controller* controller;
    SmartView* smartView;
    CreditView* creditView;
    DepositView* depositView;
};

}  // namespace s21

#endif // CPP3_SMARTCALC_V2_0_VIEW_VIEW_H_
