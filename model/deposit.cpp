#include "model.h"

namespace s21 {

Model::Model(long double amount, int period, long double rate,
             long double tax_rate, long double frequency, bool capitalization) {
  this->deposit_result.amount = amount;
  this->deposit_data.period = period;
  this->deposit_data.rate = rate / 100;
  this->deposit_data.tax_rate = tax_rate / 100;
  this->deposit_data.frequency = frequency;
  this->deposit_data.capitalization = capitalization;
}

void Model::PushDeposit(long double amount, int frequency) {
  deposits.emplace_back(amount, frequency);
}

void Model::PushWithdrawal(long double amount, int frequency) {
  withdrawals.emplace_back(amount, frequency);
}

long double Model::GetInterest_() {
  return deposit_result.amount * deposit_data.rate / deposit_data.frequency;
}

void Model::DepositCalculator() {
  for (int i = 1; i <= deposit_data.period; ++i) {
    if ((deposit_data.frequency == 1 && i % 12 == 0) ||
        (deposit_data.frequency == 2 && i % 6 == 0) ||
        deposit_data.frequency == 12 || i == deposit_data.period) {
      if (i == deposit_data.period && !(i % 6 == 0 || i % 12 == 0)) {
        if (deposit_data.frequency == 2) {
          deposit_data.frequency += fmod(deposit_data.period, 6) / 12;
        } else if (deposit_data.frequency == 1) {
          deposit_data.frequency += 1 - (fmod(deposit_data.period, 12) / 12);
        }
      }
      deposit_result.interest += GetInterest_();

      if (deposit_data.capitalization) {
        deposit_result.amount += GetInterest_();
      }
    }

    for (const auto& deposit : deposits) {
      if (i % deposit.frequency == 0) {
        deposit_result.amount += deposit.amount;
      }
    }
    for (const auto& withdrawal : withdrawals) {
      if (i % withdrawal.frequency == 0) {
        deposit_result.amount -= withdrawal.amount;
      }
    }
  }
  if (deposit_data.rate > 0.125) {
    deposit_result.tax = deposit_result.interest * deposit_data.tax_rate;
  }
  deposits.clear();
  withdrawals.clear();
}

void Model::SetValues(DepositData deposit_data) {
  this->deposit_result.amount = deposit_data.amount;
  this->deposit_data.period = deposit_data.period;
  this->deposit_data.rate = deposit_data.rate / 100;
  this->deposit_data.tax_rate = deposit_data.tax_rate / 100;
  this->deposit_data.frequency = deposit_data.frequency;
  this->deposit_data.capitalization = deposit_data.capitalization;
  deposit_result.interest = 0;
  deposit_result.tax = 0;
}

DepositResult Model::GetDepositResult() { return deposit_result; }

}  // namespace s21
