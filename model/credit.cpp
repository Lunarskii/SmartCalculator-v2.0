#include "model.h"

namespace s21 {

Model::Model(long double amount, long double rate, int period, int type) 
{
    this->credit_data.amount = amount;
    this->credit_data.rate = rate;
    this->credit_data.period = period;
    this->credit_data.type = type;
}

void Model::CreditCalculator() 
{
    if (credit_data.type == kAnnuity) {
        long double rate = credit_data.rate / static_cast<long double>(1200);
        long double x = rate * pow(rate + 1, static_cast<long double>(credit_data.period)) /
                        (pow(rate + 1, static_cast<long double>(credit_data.period)) - 1);

        credit_result.payment = Round_(x * credit_data.amount, 2);
    } else if (credit_data.type == kDifferentiated) {
        long double rate = credit_data.amount / static_cast<long double>(credit_data.period);

        credit_result.max_payment = Round_((rate + credit_data.amount * credit_data.rate * Avg::kAvgDaysInMonths / Avg::kAvgDaysInYear), 2);
        credit_result.min_payment = Round_((rate + rate * credit_data.rate * Avg::kAvgDaysInMonths / Avg::kAvgDaysInYear), 2);
        credit_result.payment = Round_((credit_result.max_payment + credit_result.min_payment) / 2, 2);
    }
    credit_result.total_payment = Round_(credit_result.payment * static_cast<long double>(credit_data.period), 2);
    credit_result.overpayment = Round_((credit_result.total_payment - credit_data.amount), 2);
}

void Model::SetValues(CreditData credit_data)
{
    this->credit_data.amount = credit_data.amount;
    this->credit_data.rate = credit_data.rate;
    this->credit_data.period = credit_data.period;
    this->credit_data.type = credit_data.type;
}

long double Model::Round_(long double &&x, int&& digits)
{
    return std::round(x * std::pow(10, digits)) / std::pow(10, digits);
}

CreditResult Model::GetCreditResult()
{
    return credit_result;
}

}  // namespace s21
