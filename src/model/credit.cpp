#include "model.h"

namespace s21 {

Model::Model(value_type amount, value_type percent, int period, int type) 
    : amount(amount)
    , percent(percent)
    , period(period)
    , type(type) 
{}

void Model::CreditCalculator() 
{
    if (type == ANNUITY) {
        long double rate = percent / (long double)1200;
        long double x = rate * pow(rate + 1, (long double)period) /
                        (pow(rate + 1, (long double)period) - 1);

        payment = round(x * amount * 100) / 100;
    } else if (type == DIFFERENTIATED) {
        long double rate = amount / (long double)period;

        max = round((rate + amount * percent * 30.42 / 36524.25) * 100) / 100;
        min = round((rate + rate * percent * 30.42 / 36524.25) * 100) / 100;
        payment = round((max + min) / 2 * 100) / 100;
    }
    totalPayment = round(payment * (long double)period * 100) / 100;
    overpayment = round((totalPayment - amount) * 100) / 100;
}

typename Model::reference Model::getPayment() 
{
    return payment;
}

typename Model::reference Model::getOverpayment() 
{
    return overpayment;
}

typename Model::reference Model::getTotalPayment() 
{
    return totalPayment;
}

typename Model::reference Model::getMax() 
{
    return max;
}

typename Model::reference Model::getMin() 
{
    return min;
}

void Model::setValues(value_type amount, value_type percent, int period, int type)
{
    this->amount = amount;
    this->percent = percent;
    this->period = period;
    this->type = type;
}

}  // namespace s21
