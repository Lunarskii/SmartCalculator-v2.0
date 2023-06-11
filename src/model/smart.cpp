#include "model.h"

namespace s21 {

Model::Model(std::string s)
{
    str = s;
    it = str.begin();
}

Model::Model(std::string s, long double x)
{
    new (this) Model(s);
    xValue = x;
}

Model::Model(Model& other)
{
    str = other.str;
    it = other.it;
    xValue = other.xValue;
}

bool Model::isDec() const {
    return (*it >= '0' && *it <= '9') || isX();
}

bool Model::isDec(char c) const {
    return (c >= '0' && c <= '9') || isX(c);
}

bool Model::isX() const {
    return *it == 'x' || *it == 'X';
}

bool Model::isX(char c) const {
    return c == 'x' || c == 'X';
}

bool Model::isFuncChar() const {
    return std::string("cstal").find(*it) != std::string::npos;
}

bool Model::isSign() const {
    return *it == '+' || *it == '-';
}

bool Model::isSign(char c) const {
    return c == '+' || c == '-';
}

bool Model::isOp() const {
    return std::string("+-*/^").find(*it) != std::string::npos;
}

bool Model::isMod() const {
    return std::string(it, it + 3) == "mod";
}

bool Model::isDot() const {
    return *it == '.';
}

bool Model::isDot(char c) const {
    return c == '.';
}

bool Model::isExp() const {
    return *it == 'e' || *it == 'E';
}

bool Model::isExp(char c) const {
    return c == 'e' || c == 'E';
}

bool Model::isUnaryOp() {
    if (isSign()) {
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

bool Model::isNumber() {
    std::string value;
    auto ptr = it;

    if (isUnaryOp())
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

        if (pos == static_cast<std::size_t>(-1) || pos == value.size())
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

bool Model::isFunc(int& funcType) {
    std::string functions[9] = {"cos(",  "sin(",  "tan(", "acos(", "asin(",
                                "atan(", "sqrt(", "ln(",  "log("};

    for (std::size_t i = 0; i < sizeof(functions) / sizeof(std::string); ++i) {
        if (!str.compare(std::distance(str.begin(), it), functions[i].size(), functions[i])) {
            funcType = (kCos + i);
            return true;
        }
    }

    return false;
}

bool Model::isWrongBrackets() const {
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

bool Model::isWrongSigns() const {
    for (auto ptr = it; ptr != str.end(); ++ptr) {
        if (*ptr == '(' && (std::string("*/^").find(*(ptr + 1)) != std::string::npos)) {
            return true;
        } else if ((*ptr == '*' && *(ptr + 1) == '/') || (*ptr == '/' && *(ptr + 1) == '*')) {
            return true;
        }
    }

    return false;
}

bool Model::isWrongX() const {
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

int Model::detPriority(char c) const {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == 'm') {
        return 3;
    } else if (c == '^') {
        return 4;
    }

    return 0;
}

int Model::detOp(char c) const {
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
    } else if (c == 'm') {
        return kMod;
    }

    return 0;
}

bool Model::appendFunc(int& funcType) {
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

    Model tempObj(temp, xValue);
    tempObj.SmartCalculator();

    try 
    {
        output.emplace(calcFunctions(funcType, std::stold(tempObj.getResult())));
    }
    catch (const std::exception& e)
    {
        return false;
    }
    
    return true;
}

void Model::appendOp() {
    char prev = *it;
    char beforePrev = *(it++ - 1);

    if (!isDec(beforePrev) && prev == '-' && *it == '(') {
        output.emplace(-1);
        prev = '*';
    } else if (prev == '-' && isFuncChar()) {
        output.emplace(0);
        prev = '-';
    }
    while (operators.size() != 0 && detPriority(prev) <= operators.top().priority) {
        moveElement(operators, output);
    }
    operators.emplace(0, detPriority(prev), detOp(prev));
    if (prev == 'm') it += 2;
}

void Model::appendBracket() {
    operators.emplace(0, 0, kLbracket);
    ++it;
}

void Model::splice() {
    while (operators.top().type != kLbracket) {
        moveElement(operators, output);
    }
    operators.pop();
    ++it;
}

void Model::spliceFull() {
    while (operators.size() != 0) {
        moveElement(operators, output);
    }
}

void Model::SmartCalculator() {
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return std::isspace(c); }), str.end());
    std::replace(str.begin(), str.end(), ',', '.');

    if (str.empty() || isWrongBrackets() || isWrongSigns() || isWrongX()) {
        str = "ERROR";
    } else {
        replaceX();
        if (toPolishNotation()) {
            toDouble();
        } else {
            str = "ERROR";
        }
    }
}

bool Model::toPolishNotation() {
    while (it != str.end()) {
        if (isNumber()) {
            
        } else if (int funcType = kNumber; isFunc(funcType)) {
            if (!appendFunc(funcType)) return false;
        } else if (*it == '(') {
            appendBracket();
        } else if (isOp() || isMod()) {
            appendOp();
        } else if (*it == ')') {
            splice();
        } else {
            return false;
        }
    }
    spliceFull();

    return true;
}

void Model::numberProcessing(std::stack<StackNode>& temp) {
    long double operand1 = output.top().data;
    long double operand2 = 0;
    long double result = 0;

    output.pop();
    if (isOperator(output.top().type)) {
        temp.emplace(operand1);
        while (isOperator(output.top().type)) {
            moveElement(output, temp);
        }
    } else if (output.top().type == kNumber) {
        operand2 = output.top().data;
        output.pop();
        calcOperations(operand2, operand1, temp.top().type, result);
        temp.pop();
        output.emplace(result);
    }
}

long double Model::calcFunctions(int type, long double x) {
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
    } else if (type == kLog) {
        return log10(x);
    }
}

void Model::calcOperations(long double& operand1, long double& operand2, int type, long double& result) {
    if (type == kPlus) {
        result = operand1 + operand2;
    } else if (type == kMinus) {
        result = operand1 - operand2;
    } else if (type == kMult) {
        result = operand1 * operand2;
    } else if (type == kDiv) {
        result = operand1 / operand2;
    } else if (type == kPower) {
        result = pow(operand1, operand2);
    } else if (type == kMod) {
        result = fmod(operand1, operand2);
    }
}

void Model::toDouble() {
    std::stack<StackNode> temp;

    if (output.size() == 1 || (output.size() == 2 && isOperator(output.top().type))) {
        if (isOperator(output.top().type)) {
            str = "ERROR";
        }
    } else {
        while (output.size() > 1 || temp.size() > 0) {
            if (isOperator(output.top().type)) {
                spliceOperators(output, temp);
            } else if ((output.size() <= 1 && temp.size() > 0) || (output.top().type == kNumber && temp.top().type == kNumber)) {
                spliceNumbers(temp, output);
            } else if (output.top().type == kNumber) {
                numberProcessing(temp);
            }
        }
    }
    if (str != "ERROR") {
        str = std::to_string(output.top().data);
    }
}

std::string Model::getResult() const {
    return str;
}

void Model::setValues(std::string newString, long double x)
{
    str = newString;
    it = str.begin();
    xValue = x;
    while (output.size() != 0)
    {
        output.pop();
    }
    while (operators.size() != 0)
    {
        operators.pop();
    }
}

void Model::replaceX()
{
    std::stringstream ss;
    ss << xValue;
    std::string replacementStr = ss.str();
    size_t pos = 0;

    while ((pos = str.find('x', pos)) != std::string::npos) {
        str.replace(pos, 1, replacementStr);
        pos += replacementStr.length();
    }
}

}  // namespace s21