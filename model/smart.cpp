#include "model.h"

namespace s21 {

Model::Model(std::string s, long double x)
{
    str = s;
    it = str.begin();
    this->x = x;
}

bool Model::IsUnaryOp_() {
    if (isSign(*it)) {
        auto index = std::distance(str.begin(), it);
        char prev = (index == 0) ? *it : *(it - 1);
        char next = *(it + 1);

        if (next == '(') {
            return false;
        } else if (index == 0 && (isDec(next) || isDot(next))) {
            return true;
        } else if (index > 0 && prev != ')' && !isDec(prev) && !isDot(prev)) {
            return true;
        }
    }

    return false;
}

bool Model::AppendIfNumber_() {
    std::string value;
    auto ptr = it;

    if (IsUnaryOp_())
    {
        value += *(ptr++);
    }

    for (; ptr != str.end() && (isDec(*ptr) || isDot(*ptr) || (isSign(*ptr) && isExp(*(ptr - 1))) || isExp(*ptr)); ++ptr) {
        value += *ptr;
    }

    try 
    {
        std::size_t pos = 0;
        long double st = std::stold(value, &pos);

        if (pos == value.size())
        {
            output.emplace(st);
        }
        else
        {
            return false;
        }
    }
    catch (const std::exception& e)
    {
        return false;
    }

    it += value.size();
    return true;
}

bool Model::AppendIfFunc_() {
    std::string functions[9] = {"cos(",  "sin(",  "tan(", "acos(", "asin(",
                                "atan(", "sqrt(", "ln(",  "log("};

    for (std::size_t i = 0; i < sizeof(functions) / sizeof(std::string); ++i) {
        if (!str.compare(std::distance(str.begin(), it), functions[i].size(), functions[i])) {
            std::string temp;

            while (*it != '(') ++it;
            ++it;

            for (int lbracket = 1; lbracket != 0; ++it) {
                if (*it == '(') {
                    ++lbracket;
                } else if (*it == ')') {
                    --lbracket;
                }
                if (lbracket != 0) {
                    temp += *it;
                }
            }

            Model tempObj(temp, x);
            tempObj.SmartCalculator();

            try 
            {
                output.emplace(CalcFunctions_(kCos + i, std::stold(tempObj.GetResult())));
            }
            catch (const std::exception& e)
            {
                return false;
            }

            return true;
        }
    }

    return false;
}

bool Model::IsWrongBrackets_() const {
    int lbracket = 0;
    int rbracket = 0;

    for (auto ptr = it; ptr != str.end(); ++ptr) {
        if (*ptr == '(') {
            ++lbracket;
        } else if (*ptr == ')') {
            ++rbracket;
            if (rbracket > lbracket) return true;
        }
    }
    if (lbracket != rbracket) return true;

    return false;
}

bool Model::IsWrongX_() const {
    if (str.find('x') != std::string::npos || str.find('X') != std::string::npos) {
        for (std::string::const_iterator ptr = it; ptr != str.end(); ++ptr) {
            char prev = (std::distance(str.begin(), ptr) > 0) ? *(ptr - 1) : *ptr;
            char next = *(ptr + 1);

            if (isX(*ptr) && ((isDot(prev) || isDot(next)) || isX(next))) {
                return true;
            }
        }
    }

    return false;
}

int Model::DetPriority_(char c) const {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == 'm') {
        return 3;
    } else {
        return 4;
    }
}

int Model::DetOp_(char c) const {
    if (c == '+') {
        return kPlus;
    } else if (c == '-') {
        return kMinus;
    } else if (c == '*') {
        return kMult;
    } else if (c == '/') {
        return kDiv;
    } else if (c == '^') {
        return kPower;
    } else {
        return kMod;
    }
}

void Model::AppendOp_() {
    char prev = *it;
    char before_prev = *(it++ - 1);

    if (!isDec(before_prev) && prev == '-' && *it == '(') {
        output.emplace(-1);
        prev = '*';
    } else if (prev == '-' && isFuncChar(*it)) {
        output.emplace(0);
        prev = '-';
    }
    while (operators.size() != 0 && DetPriority_(prev) <= operators.top().priority) {
        MoveElement_(operators, output);
    }
    operators.emplace(0, DetPriority_(prev), DetOp_(prev));
    if (prev == 'm') it += 2;
}

void Model::AppendBracket_() {
    operators.emplace(0, 0, kLbracket);
    ++it;
}

void Model::Splice_() {
    while (operators.top().type != kLbracket) {
        MoveElement_(operators, output);
    }
    operators.pop();
    ++it;
}

void Model::SpliceFull_() {
    while (operators.size() != 0) {
        MoveElement_(operators, output);
    }
}

void Model::SmartCalculator() {
    std::replace(str.begin(), str.end(), ',', '.');

    if (str.empty() || IsWrongBrackets_() || IsWrongX_()) 
    {
        str = "ERROR";
    } 
    else 
    {
        ReplaceX_();
        if (ToPolishNotation_()) {
            ToDouble_();
        } else {
            str = "ERROR";
        }
    }
}

bool Model::ToPolishNotation_() {
    while (it != str.end()) {
        if (*it == ' ') {
            ++it;
        } else if (AppendIfNumber_()) {
            
        } else if (AppendIfFunc_()) {

        } else if (*it == '(') {
            AppendBracket_();
        } else if (isOp(*it) || (std::string(it, str.end()).size() >= 3 && isMod(it))) {
            AppendOp_();
        } else if (*it == ')') {
            Splice_();
        } else {
            return false;
        }
    }
    SpliceFull_();

    return true;
}

void Model::NumberProcessing_(std::stack<StackNode>& temp) {
    long double operand1 = output.top().data;

    output.pop();
    if (isOperator(output.top().type)) {
        temp.emplace(operand1);
        SpliceOperators_(output, temp);
    } else if (output.top().type == kNumber) {
        long double operand2 = output.top().data;

        output.pop();
        output.emplace(CalcOperations_(operand2, operand1, temp.top().type));
        temp.pop();
    }
}

long double Model::CalcFunctions_(int type, long double x) {
    if (type == kCos) {
        return cos(x);
    } else if (type == kSin) {
        return sin(x);
    } else if (type == kTan) {
        return tan(x);
    } else if (type == kAcos) {
        return acos(x);
    } else if (type == kAsin) {
        return asin(x);
    } else if (type == kAtan) {
        return atan(x);
    } else if (type == kSqrt) {
        return sqrt(x);
    } else if (type == kLn) {
        return log(x);
    } else {
        return log10(x);
    }
}

long double Model::CalcOperations_(long double& operand1, long double& operand2, int type) {
    if (type == kPlus) {
        return operand1 + operand2;
    } else if (type == kMinus) {
        return operand1 - operand2;
    } else if (type == kMult) {
        return operand1 * operand2;
    } else if (type == kDiv) {
        return operand1 / operand2;
    } else if (type == kPower) {
        return pow(operand1, operand2);
    } else {
        return fmod(operand1, operand2);
    }
}

void Model::ToDouble_() {
    std::stack<StackNode> temp;

    if (GetCountNumbersOfOperators_() != output.size() - GetCountNumbersOfOperators_() - 1)
    {
        str = "ERROR";
    } 
    else 
    {
        while (output.size() > 1 || temp.size() > 0) {
            if (isOperator(output.top().type)) {
                SpliceOperators_(output, temp);
            } else if ((output.size() <= 1 && temp.size() > 0) || (output.top().type == kNumber && temp.top().type == kNumber)) {
                SpliceNumbers_(temp, output);
            } else if (output.top().type == kNumber) {
                NumberProcessing_(temp);
            }
        }
        str = std::to_string(output.top().data);
    }
}

std::string Model::GetResult() const {
    return str;
}

void Model::SetValues(std::string new_string, long double x)
{
    str = new_string;
    it = str.begin();
    this->x = x;
    while (output.size() != 0)
    {
        output.pop();
    }
    while (operators.size() != 0)
    {
        operators.pop();
    }
}

void Model::ReplaceX_()
{
    std::stringstream ss;
    ss << x;
    std::string replacement_string = ss.str();
    size_t pos = 0;

    while ((pos = str.find('x', pos)) != std::string::npos) {
        str.replace(pos, 1, replacement_string);
        pos += replacement_string.length();
    }
}

std::size_t Model::GetCountNumbersOfOperators_()
{
    std::stack<StackNode> temp(output);
    std::size_t i = 0;

    for (; temp.size() != 0; temp.pop())
    {
        if (isOperator(temp.top().type))
        {
            ++i;
        }
    }

    return i;
}

}  // namespace s21