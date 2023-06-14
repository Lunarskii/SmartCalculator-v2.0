#ifndef CPP3_SMARTCALC_V2_0_STRUCTURES_H_
#define CPP3_SMARTCALC_V2_0_STRUCTURES_H_

namespace s21
{

enum OperandType 
{
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

class StackNode
{
public:
    StackNode(const long double& d, const int& p = 0, int t = kNumber)
        : data(d)
        , priority(p)
        , type(t) 
    {}
    long double data{};
    int priority{};
    int type{};
};

class ListNode
{
public:
    ListNode(double amount, int frequency)
        : amount(amount)
        , frequency(frequency) 
    {}
    double amount{};
    int frequency{};
};

enum CreditType
{
    kAnnuity = 1,
    kDifferentiated = 2
};

struct Avg 
{
    static constexpr long double kAvgDaysInMonths = 30.42;
    static constexpr long double kAvgDaysInYear = 36524.25;
};

typedef struct
{
    long double payment{};
    long double overpayment{};
    long double total_payment{};
    long double max_payment{};
    long double min_payment{};
} CreditResult;

typedef struct
{
    long double interest{};
    long double tax{};
    long double amount{};
} DepositResult;

typedef struct
{
    long double amount{};
    long double rate{};
    int period{};
    int type{};
} CreditData;

typedef struct
{
    long double amount{};
    long double rate{};
    long double tax_rate{};
    int period{};
    long double frequency{};
    bool capitalization{};
} DepositData;

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_STRUCTURES_H_
