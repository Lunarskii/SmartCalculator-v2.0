#include "controller.h"

namespace s21 {

void Controller::setSmartCalculatorData(std::string e, long double xValue) {
    model->setValues(e, xValue);
    model->SmartCalculator();
}

void Controller::setCreditCalculatorData(long double amount, long double percent, int period, int type)
{
    model->setValues(amount, percent, period, type);
    model->CreditCalculator();
}

void Controller::setDepositCalculatorData(long double amount, int period, long double rate, long double taxRate, long double paymentFrequency, bool capitalization)
{
    model->setValues(amount, period, rate, taxRate, paymentFrequency, capitalization);
    model->DepositCalculator();
}

void Controller::addDeposit(long double amount, int frequency)
{
    model->pushDeposit(amount, frequency);
}

void Controller::addWithdrawal(long double amount, int frequency)
{
    model->pushWithdrawal(amount, frequency);
}

long double& Controller::getPayment()
{
    return model->getPayment();
}

long double& Controller::getOverpayment()
{
    return model->getOverpayment();
}

long double& Controller::getTotalPayment()
{
    return model->getTotalPayment();
}

long double& Controller::getMax()
{
    return model->getMax();
}

long double& Controller::getMin()
{
    return model->getMin();
}

long double& Controller::getEarnedInterest()
{
    return model->getEarnedInterest();
}

long double& Controller::getTax()
{
    return model->getTax();
}

long double& Controller::getAmount()
{
    return model->getAmount();
}

std::string Controller::getResult() {
    return model->getResult();
}

}  // namespace s21
