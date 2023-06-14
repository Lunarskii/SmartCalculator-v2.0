#ifndef CPP3_SMARTCALC_V2_0_MODEL_MODEL_H_
#define CPP3_SMARTCALC_V2_0_MODEL_MODEL_H_

#include <algorithm>
#include <cmath>
#include <list>
#include <stack>
#include <sstream>

#include "../structures.h"
#include "../type_predicates.h"

namespace s21 {

class Model 
{
public:
    Model() = default;
    Model(std::string s, long double x = 0);
    ~Model() = default;

    void SmartCalculator();
    std::string GetResult() const;
    void SetValues(std::string new_string, long double x);
private:
    bool IsUnaryOp_();
    bool IsWrongBrackets_() const;
    bool IsWrongX_() const;
    bool AppendIfNumber_();
    bool AppendIfFunc_();
    bool ToPolishNotation_();
    void ToDouble_();
    int DetPriority_(char c) const;
    int DetOp_(char c) const;
    void AppendOp_();
    void AppendBracket_();
    void Splice_();
    void SpliceFull_();
    void NumberProcessing_(std::stack<StackNode>& temp);
    long double CalcFunctions_(int type, long double x);
    long double CalcOperations_(long double& operand1, long double& operand2, int type);
    void MoveElement_(std::stack<StackNode>& src, std::stack<StackNode>& dest);
    void SpliceOperators_(std::stack<StackNode>& src, std::stack<StackNode>& dest);
    void SpliceNumbers_(std::stack<StackNode>& src, std::stack<StackNode>& dest);
    void ReplaceX_();
    std::size_t GetCountNumbersOfOperators_();
    inline bool isOperator(int type) { return type >= kPlus && type <= kMod; }
private:
    std::string str{};
    std::string::iterator it{str.begin()};
    long double x{};
    std::stack<StackNode> output;
    std::stack<StackNode> operators;

public:
    Model(long double amount, long double rate, int period, int type);
    void CreditCalculator();
    void SetValues(CreditData credit_data);
    CreditResult GetCreditResult();
private:
    long double Round_(long double &&x, int&& digits);
private:
    CreditData credit_data{};
    CreditResult credit_result{};

public:
    Model(long double amount, int period, long double rate, long double tax_rate, long double frequency, bool capitalization);
    void DepositCalculator();
    void PushDeposit(long double amount, int frequency);
    void PushWithdrawal(long double amount, int frequency);
    void SetValues(DepositData deposit_data);
    DepositResult GetDepositResult();
private:
    long double GetInterest_();
private:
    std::list<ListNode> deposits;
    std::list<ListNode> withdrawals;
    DepositData deposit_data{};
    DepositResult deposit_result{};
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_MODEL_MODEL_H_
