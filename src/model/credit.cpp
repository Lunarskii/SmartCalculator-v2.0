#include "model.h"

namespace s21 {

Model::Model(long double amount, long double percent, int period, int type) 
    : amount(amount)
    , percent(percent)
    , period(period)
    , type(type) 
{}

void Model::CreditCalculator() 
{
    if (type == ANNUITY) {
        long double rate = percent / static_cast<long double>(1200);
        long double x = rate * pow(rate + 1, static_cast<long double>(period)) /
                        (pow(rate + 1, static_cast<long double>(period)) - 1);

        payment = dround(x * amount, 2);
    } else if (type == DIFFERENTIATED) {
        long double rate = amount / static_cast<long double>(period);

        max = dround((rate + amount * percent * avg_t::kAvgDaysInMonths / avg_t::kAvgDaysInYear), 2);
        min = dround((rate + rate * percent * avg_t::kAvgDaysInMonths / avg_t::kAvgDaysInYear), 2);
        payment = dround((max + min) / 2, 2);
    }
    totalPayment = dround(payment * static_cast<long double>(period), 2);
    overpayment = dround((totalPayment - amount), 2);
}

long double& Model::getPayment() 
{
    return payment;
}

long double& Model::getOverpayment() 
{
    return overpayment;
}

long double& Model::getTotalPayment() 
{
    return totalPayment;
}

long double& Model::getMax() 
{
    return max;
}

long double& Model::getMin() 
{
    return min;
}

void Model::setValues(long double amount, long double percent, int period, int type)
{
    this->amount = amount;
    this->percent = percent;
    this->period = period;
    this->type = type;
}

long double Model::dround(long double &&x, int&& digits)
{
    return std::round(x * std::pow(10, digits)) / std::pow(10, digits);
}

}  // namespace s21
