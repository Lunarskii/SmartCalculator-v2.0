#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QTabWidget>
#include "smartview.h"
#include "creditview.h"
#include "depositview.h"
#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(Controller* c, QWidget* parent = nullptr);
    ~View();

private slots:

private:
    Ui::View* ui;
    Controller* controller;
    SmartView* smartView;
    CreditView* creditView;
    DepositView* depositView;
};

#endif // VIEW_H
