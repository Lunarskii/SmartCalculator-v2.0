#include "model.h"

namespace s21 {

Model::Model(long double amount, int period, long double rate, long double taxRate, long double paymentFrequency, bool capitalization) 
    : amount(amount)
    , period(period)
    , rate(rate)
    , taxRate(rate)
    , paymentFrequency(paymentFrequency)
    , capitalization(capitalization) 
{
    this->rate /= 100;
    this->taxRate /= 100;
    interest = 0;
}

void Model::pushDeposit(long double amount, int frequency)
{
    deposits.emplace_back(amount, frequency);
}

void Model::pushWithdrawal(long double amount, int frequency)
{
    withdrawals.emplace_back(amount, frequency);
}

long double Model::getInterest()
{   
    return amount * rate / paymentFrequency;
}

long double& Model::getEarnedInterest()
{
    return interest;
}

long double& Model::getTax()
{
    return tax;
}

long double& Model::getAmount()
{
    return amount;
}

void Model::DepositCalculator()
{
    for (int i = 1; i <= period; ++i) 
    {
        if ((paymentFrequency == 1 && i % 12 == 0)
            || (paymentFrequency == 2 && i % 6 == 0)
            || paymentFrequency == 12
            || i == period)
        {
            if (i == period && !(i % 6 == 0 || i % 12 == 0))
            {
                if (paymentFrequency == 2) 
                {
                    paymentFrequency += fmod(period, 6) / 12;
                } 
                else if (paymentFrequency == 1) 
                {
                    paymentFrequency += 1 - (fmod(period, 12) / 12);
                }
            }
            interest += getInterest();

            if (capitalization) 
            {
                amount += getInterest();
            }
        }

        for (const auto& deposit : deposits) {
            if (i % deposit.frequency == 0) {
                amount += deposit.amount;
            }
        }
        for (const auto& withdrawal : withdrawals) {
            if (i % withdrawal.frequency == 0) {
                amount -= withdrawal.amount;
            }
        }
    }
    if (rate > 0.125)
    {
        tax = interest * taxRate;
    }
    deposits.clear();
    withdrawals.clear();
}

void Model::setValues(long double amount, int period, long double rate, long double taxRate, long double paymentFrequency, bool capitalization)
{
    this->amount = amount;
    this->period = period;
    this->rate = rate / 100;
    this->taxRate = taxRate / 100;
    this->paymentFrequency = paymentFrequency;
    this->capitalization = capitalization;
    this->interest = 0;
    this->tax = 0;
}

}  // namespace s21
