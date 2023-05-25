#include "model.h"

namespace s21 {

Model::Stack::Node::Node(const_reference d, const int& priority, type_t t, Node* prev)
        : data(d)
        , priority(priority)
        , type(t)
        , prev(prev)
{}

Model::Model()
{
    output = new Stack;
    operators = new Stack;
}

Model::Model(std::string s)
{
    str = s;
    it = str.begin();
    output = new Stack;
    operators = new Stack;
}

Model::Model(std::string s, value_type x)
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

Model::~Model()
{
    delete output;
    delete operators;
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
    bool RESULT_CODE = false;
    auto ptr = it;

    if (isUnaryOp()) { // попробовать убрать true
        RESULT_CODE = true;
        ++ptr;
    }

    if (isX(*ptr)) {
        RESULT_CODE = true;
    } else if (isDec(*ptr) || isDot(*ptr)) {
        RESULT_CODE = true;
        for (bool dot = false; RESULT_CODE && ptr != str.end() && (isDec(*ptr) || isDot(*ptr)); ++ptr) {
            if (isDot(*ptr)) {
                dot ? RESULT_CODE = false : RESULT_CODE = true;
                dot = true;
            }
        }
        if (isExp(*ptr)) {
            ++ptr;
            if (ptr != str.end() && isSign(*ptr)) ++ptr;
            if (ptr == str.end() || isDot(*ptr) || !isDec(*ptr)) {
                RESULT_CODE = false;
            }
        }
    }

    return RESULT_CODE;
}

bool Model::isFunc(type_t& funcType) {
    std::string functions[9] = {"cos(",  "sin(",  "tan(", "acos(", "asin(",
                                "atan(", "sqrt(", "ln(",  "log("};

    for (size_type i = 0; i < sizeof(functions) / sizeof(std::string); ++i) {
        if (!str.compare(std::distance(str.begin(), it), functions[i].size(), functions[i])) {
            funcType = (type_t)(COS + i);
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
        return PLUS;
    } else if (c == '-') {
        return MINUS;
    } else if (c == '*') {
        return MULT;
    } else if (c == '/') {
        return DIV;
    } else if (c == '^') {
        return POWER;
    } else if (c == 'm') {
        return MOD;
    }

    return 0;
}

void Model::appendNumber() {
    int sign = 1;

    if (isSign()) {
        if (*it == '-') sign = -1;
        ++it;
    }

    if (isX()) {
        output->push(xValue * sign);
        ++it;
    } else {
        std::string temp;

        for (; it != str.end() && (isDec() || isDot() || isExp() || (isSign() && isExp(*(it - 1)))); ++it) {
            temp += *it;
        }
        output->push(std::stold(temp) * sign);
    }
}

bool Model::appendFunc(type_t& funcType) {
    std::string temp;

//    while (*(it - 1) != '(') ++it;
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

    tempObj.it = tempObj.str.begin();
    if (tempObj.isNumber()) {
        output->push(std::stold(tempObj.getResult()), funcType);
        return true;
    }
    // возможно тут  вообще  не нужны никакие  проверки для  nan,  inf  и т.п.,  так  как  stold и  to_string все нормально  обрабатывают
    return false;
}

void Model::appendOp() {
    char prev = *it;
    char beforePrev = *(it++ - 1);

    if (!isDec(beforePrev) && prev == '-' && *it == '(') {
        output->push(-1);
        prev = '*';
    } else if (prev == '-' && isFuncChar()) {
        output->push(0);
        prev = '-';
    }
    while (operators->getNode() != nullptr && detPriority(prev) <= operators->getPriority()) {
        output->moveElement(*operators);
    }
    operators->push(0, (type_t)detOp(prev), detPriority(prev));
    if (prev == 'm') it += 2;
}

void Model::appendBracket() {
    operators->push(0, LBRACKET);
    ++it;
}

void Model::splice() {
    while (operators->getType() != LBRACKET) {
        output->moveElement(*operators);
    }
    operators->pop();
    ++it;
}

void Model::spliceFull() {
    while (operators->getNode() != nullptr) {
        output->moveElement(*operators);
    }
}

void Model::SmartCalculator() {
    str.erase(std::remove_if(str.begin(), str.end(), [](char c) { return std::isspace(c); }), str.end());
    std::replace(str.begin(), str.end(), ',', '.');

    if (str.empty() || isWrongBrackets() || isWrongSigns() || isWrongX()) {
        str = "ERROR";
    } else {
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
            appendNumber();
        } else if (type_t funcType = NUMBER; isFunc(funcType)) {
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

void Model::numberProcessing(Stack& temp) {
    value_type operand1 = output->getData();
    value_type operand2 = 0;
    value_type result = 0;

    output->pop();
    if (isOperator(output->getType())) {
        temp.push(operand1);
        while (isOperator(output->getType())) {
            temp.moveElement(*output);
        }
    } else if (isFunction(output->getType()) || output->getType() == NUMBER) {
        if (isFunction(output->getType())) {
            calcFunctions(result);
            operand2 = result;
        } else if (output->getType() == NUMBER) {
            operand2 = output->getData();
        }
        output->pop();
        calcOperations(operand2, operand1, temp.getType(), result);
        temp.pop();
        output->push(result);
    }
}

void Model::functionProcessing() {
    value_type result = 0;

    calcFunctions(result);
    output->pop();
    output->push(result);
}

void Model::calcFunctions(value_type& result) {
    type_t type = output->getType();
    value_type x = output->getData();

    if (type == COS) {
        result = cos(x);
    } else if (type == SIN) {
        result = sin(x);
    } else if (type == TAN) {
        result = tan(x);
    } else if (type == ACOS) {
        result = acos(x);
    } else if (type == ASIN) {
        result = asin(x);
    } else if (type == ATAN) {
        result = atan(x);
    } else if (type == SQRT) {
        result = sqrt(x);
    } else if (type == LN) {
        result = log(x);
    } else if (type == LOG) {
        result = log10(x);
    }
}

void Model::calcOperations(value_type& operand1, value_type& operand2, type_t type, value_type& result) {
    if (type == PLUS) {
        result = operand1 + operand2;
    } else if (type == MINUS) {
        result = operand1 - operand2;
    } else if (type == MULT) {
        result = operand1 * operand2;
    } else if (type == DIV) {
        result = operand1 / operand2;
    } else if (type == POWER) {
        result = pow(operand1, operand2);
    } else if (type == MOD) {
        result = fmod(operand1, operand2);
    }
}

void Model::toDouble() {
    Stack temp;

    if (output->size() == 1 || (output->size() == 2 && isOperator(output->getType()))) {
        if (isFunction(output->getType())) {
            functionProcessing();
            str = std::to_string(output->getData());
        } else if (isOperator(output->getType())) {
            str = "ERROR";
        }
    } else {
        while (output->size() > 1 || temp.size() > 0) {
            if (isOperator(output->getType())) {
                temp.spliceOperators(*output);
            } else if (isFunction(output->getType())) {
                functionProcessing();
            } else if ((output->size() <= 1 && temp.size() > 0) || (output->getType() == NUMBER && temp.getType() == NUMBER)) {
                output->spliceNumbers(temp);
            } else if (output->getType() == NUMBER) {
                numberProcessing(temp);
            }
        }
    }
    if (str != "ERROR") {
        str = std::to_string(output->getData());
    }
}

std::string Model::getResult() const {
    return str;
}

void Model::setValues(std::string newString, value_type x)
{
    str = newString;
    it = str.begin();
    xValue = x;
    output->clear();
    operators->clear();
}

}  // namespace s21