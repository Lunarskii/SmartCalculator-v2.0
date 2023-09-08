#include "controller.h"

namespace s21 {

void Controller::SetModel_(std::string e, long double x) {
  model_->SetValues(e, x);
  model_->SmartCalculator();
  emit SolutionReady(model_->GetResult());
}

void Controller::SetModel_(CreditData credit_data) {
  model_->SetValues(credit_data);
  model_->CreditCalculator();
  emit SolutionReady(model_->GetCreditResult());
}

void Controller::SetModel_(DepositData deposit_data) {
  model_->SetValues(deposit_data);
  model_->DepositCalculator();
  emit SolutionReady(model_->GetDepositResult());
}

void Controller::AddDeposit_(long double amount, int frequency) {
  model_->PushDeposit(amount, frequency);
}

void Controller::AddWithdrawal_(long double amount, int frequency) {
  model_->PushWithdrawal(amount, frequency);
}

}  // namespace s21
