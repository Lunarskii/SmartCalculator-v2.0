#ifndef CPP3_SMARTCALC_V2_0_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

class Controller 
{
public:
    Controller(Model* m) : model(m) {}

    void setSmartCalculatorData(std::string e, long double xValue);
    void setCreditCalculatorData(long double amount, long double percent, int period, int type);
    void setDepositCalculatorData(long double amount, int period, long double rate, long double taxRate, int paymentFrequency, bool capitalization);
    long double& getPayment();
    long double& getOverpayment();
    long double& getTotalPayment();
    long double& getMax();
    long double& getMin();
    long double& getEarnedInterest();
    long double& getTax();
    long double& getAmount();
    std::string getResult();
    void plot();
private:
    Model* model;
};

#endif  // CPP3_SMARTCALC_V2_0_CONTROLLER_CONTROLLER_H_
