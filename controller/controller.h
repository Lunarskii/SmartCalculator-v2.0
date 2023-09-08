#ifndef CPP3_SMARTCALC_V2_0_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_CONTROLLER_CONTROLLER_H_

#include <QObject>

#include "../model/model.h"
#include "../view/view.h"

namespace s21 {

class Controller : public QObject {
  Q_OBJECT

 public:
  explicit Controller(Model* m, View* v) : model_(m), view_(v) {
    QObject::connect(view_, SIGNAL(SetModel(std::string, long double)), this,
                     SLOT(SetModel_(std::string, long double)));
    QObject::connect(view_, SIGNAL(SetModel(CreditData)), this,
                     SLOT(SetModel_(CreditData)));
    QObject::connect(view_, SIGNAL(SetModel(DepositData)), this,
                     SLOT(SetModel_(DepositData)));
    QObject::connect(view_, SIGNAL(AddDeposit(long double, int)), this,
                     SLOT(AddDeposit_(long double, int)));
    QObject::connect(view_, SIGNAL(AddWithdrawal(long double, int)), this,
                     SLOT(AddWithdrawal_(long double, int)));
  }

 signals:
  void SolutionReady(std::string result);
  void SolutionReady(CreditResult credit_result);
  void SolutionReady(DepositResult deposit_result);

 private slots:
  void SetModel_(std::string e, long double x);
  void SetModel_(CreditData credit_data);
  void SetModel_(DepositData deposit_data);
  void AddDeposit_(long double amount, int frequency);
  void AddWithdrawal_(long double amount, int frequency);

 private:
  Model* model_;
  View* view_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_CONTROLLER_CONTROLLER_H_
