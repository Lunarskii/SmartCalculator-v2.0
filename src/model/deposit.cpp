#include "model.h"

ListNode::ListNode(double amount, int frequency) 
    : amount(amount)
    , frequency(frequency) 
{}

Model::Model(value_type amount, int period, value_type rate, value_type taxRate, int paymentFrequency, bool capitalization) 
    : amount(amount)
    , period(period)
    , rate(rate)
    , taxRate(rate)
    , paymentFrequency(paymentFrequency)
    , capitalization(capitalization) 
{
    this->rate /= 100;
    this->taxRate /= 100;
}

void Model::pushDeposit(value_type amount, int frequency)
{
    deposits.emplace_back(amount, frequency);
}

void Model::pushWithdrawal(value_type amount, int frequency)
{
    withdrawals.emplace_back(amount, frequency);
}

// Функция для расчета процентов по вкладу
typename Model::value_type Model::getInterest()
{   
    // cout << "amount = " << amount << ", rate = " << rate << ", paymentFrequency = " << paymentFrequency << ", return = " << amount * rate / paymentFrequency << endl;
    return amount * rate / paymentFrequency;
}

typename Model::reference Model::getEarnedInterest()
{
    return interest;
}

typename Model::reference Model::getTax()
{
    return tax;
}

typename Model::reference Model::getAmount()
{
    return amount;
}

void Model::DepositCalculator()
{
    for (int i = 1; i <= period; ++i) {
        interest += getInterest();

        if (capitalization) {
            amount += getInterest();
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
}

void Model::setValues(value_type amount, int period, value_type rate, value_type taxRate, int paymentFrequency, bool capitalization)
{
    this->amount = amount;
    this->period = period;
    this->rate = rate;
    this->taxRate = taxRate;
    this->paymentFrequency = paymentFrequency;
    this->capitalization = capitalization;
}
