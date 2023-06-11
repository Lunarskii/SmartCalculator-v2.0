#ifndef CPP3_SMARTCALC_V2_0_MODEL_MODEL_H_
#define CPP3_SMARTCALC_V2_0_MODEL_MODEL_H_

#include <cstddef> // для size_t
#include <string> // для std::string
#include <cstring> // для strncmp
#include <algorithm> // для remove_if
#include <stdexcept> // для выдачи исключений
#include <cmath>    // для математическиих функций
#include <list>

#include <iostream> // удалить если не нужнааааааааааааааааааааааааааааааааааааааааааааааааааааааааааааааааааааааааа
#include <stack>
#include <sstream>

namespace s21 {

#define ANNUITY 1
#define DIFFERENTIATED 2

class Model 
{
public:
    class StackNode
    {
    public:
        StackNode(const long double& d, const int& priority = 0, int t = kNumber)
            : data(d)
            , priority(priority)
            , type(t) 
        {}
        long double data;
        int priority;
        int type;
    };

    class ListNode
    {
    public:
        ListNode(double amount, int frequency)
            : amount(amount)
            , frequency(frequency) 
        {}
        double amount;
        int frequency;
    };

    Model() = default;
    Model(std::string s);
    Model(std::string s, long double x);
    Model(Model& other);
    ~Model() = default;

    bool isDec() const;
    bool isDec(char c) const;
    bool isX() const;
    bool isX(char c) const;
    bool isFuncChar() const;
    bool isSign() const;
    bool isSign(char c) const;
    bool isOp() const;
    bool isMod() const;
    bool isDot() const;
    bool isDot(char c) const;
    bool isExp() const;
    bool isExp(char c) const;
    bool isUnaryOp();
    bool isNumber();
    bool isFunc(int& funcType);
    bool isWrongBrackets() const;
    bool isWrongSigns() const;
    bool isWrongX() const;

    void SmartCalculator();
    bool toPolishNotation();
    void toDouble();
    std::string getResult() const;

    int detPriority(char c) const;
    int detOp(char c) const;

    bool appendFunc(int& funcType);
    void appendOp();
    void appendBracket();
    void splice();
    void spliceFull();

    void numberProcessing(std::stack<StackNode>& temp);
    long double calcFunctions(int type, long double x);
    void calcOperations(long double& operand1, long double& operand2, int type, long double& result);

    void setValues(std::string newString, long double x);

    void moveElement(std::stack<StackNode>& src, std::stack<StackNode>& dest);
    void spliceOperators(std::stack<StackNode>& src, std::stack<StackNode>& dest);
    void spliceNumbers(std::stack<StackNode>& src, std::stack<StackNode>& dest);
    void replaceX();
    inline bool isOperator(int type) { return type >= kPlus && type <= kMod; }
private:
    std::string str{};
    std::string::iterator it{str.begin()};
    long double xValue{};
    std::stack<StackNode> output;
    std::stack<StackNode> operators;
    
    enum type_t {
        kNumber = 0,
        kPlus = 1,
        kMinus = 2,
        kMult = 3,
        kDiv = 4,
        kPower = 5,
        kMod = 6,
        kCos = 11,
        kSin = 12,
        kTan = 13,
        kAcos = 14,
        kAsin = 15,
        kAtan = 16,
        kSqrt = 17,
        kLn = 18,
        kLog = 19,
        kLbracket = 20
    };

public:
    Model(long double amount, long double percent, int period, int type);
    void CreditCalculator();
    long double& getPayment();
    long double& getOverpayment();
    long double& getTotalPayment();
    long double& getMax();
    long double& getMin();
    void setValues(long double amount, long double percent, int period, int type);
    long double dround(long double &&x, int&& digits);
private:
    long double amount{};
    long double percent{};
    long double payment{};
    long double overpayment{};
    long double totalPayment{};
    long double max{};
    long double min{};
    int period{};
    int type{};

    struct avg_t {
        static constexpr long double kAvgDaysInMonths = 30.42;
        static constexpr long double kAvgDaysInYear = 36524.25;
    };

public:
    Model(long double amount, int period, long double rate, long double taxRate, long double paymentFrequency, bool capitalization);
    void DepositCalculator();
    void pushDeposit(long double amount, int frequency);
    void pushWithdrawal(long double amount, int frequency);
    long double& getEarnedInterest();
    long double& getTax();
    long double& getAmount();
    void setValues(long double amount, int period, long double rate, long double taxRate, long double paymentFrequency, bool capitalization);
private:
    long double getInterest();
    long double rate{};
    long double taxRate{};
    long double paymentFrequency{};
    bool capitalization{};
    std::list<ListNode> deposits;
    std::list<ListNode> withdrawals;
    long double interest{};
    long double tax{};
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_MODEL_MODEL_H_
