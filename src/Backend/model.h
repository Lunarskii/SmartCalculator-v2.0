
#include <cstddef> // для size_t
#include <string> // для std::string
#include <cstring> // для strncmp
#include <algorithm> // для remove_if
#include <stdexcept> // для выдачи исключений
#include <cmath>    // для математическиих функций

#include <iostream>

#define ANNUITY 1
#define DIFFERENTIATED 2

typedef enum {
  NUMBER = 0,
  PLUS = 1,
  MINUS = 2,
  MULT = 3,
  DIV = 4,
  POWER = 5,
  MOD = 6,
  COS = 11,
  SIN = 12,
  TAN = 13,
  ACOS = 14,
  ASIN = 15,
  ATAN = 16,
  SQRT = 17,
  LN = 18,
  LOG = 19,
  LBRACKET = 20,
} type_t;

inline bool isFunction(type_t type) {
    return type >= COS && type <= LOG;
}

inline bool isOperator(type_t type) {
    return type >= PLUS && type <= MOD;
}

class Model {
    public:
        class Stack;

        using value_type = long double;
        using reference = long double&;
        using const_reference = const long double&;
        using size_type = std::size_t;

        Model(std::string s);
        Model(std::string s, value_type x);
        ~Model();

        // посмотреть правила именования функций
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
        bool isFunc(type_t& funcType);
        bool isWrongBrackets() const;
        bool isWrongSigns() const;
        bool isWrongX() const;

        void SmartCalculator();
        bool toPolishNotation();
        void toDouble();
        std::string getResult() const;

        int detPriority(char c) const;
        int detOp(char c) const;

        void appendNumber();
        bool appendFunc(type_t& funcType);
        void appendOp();
        void appendBracket();
        void splice();
        void spliceFull();

        void numberProcessing(Stack& temp);
        void functionProcessing();
        void calcFunctions(value_type& result);
        void calcOperations(value_type& operand1, value_type& operand2, type_t type, value_type& result);
    private:
        std::string str;
        std::string::iterator it;
        value_type xValue;
        Stack* output;
        Stack* operators;

    public:
        Model(value_type amount, value_type percent, int period, int type);
        void CreditCalculator();
        reference getPayment();
        reference getOverpayment();
        reference getTotalPayment();
        reference getMax();
        reference getMin();
    private:
        value_type amount;
        value_type percent;
        value_type payment;
        value_type overpayment;
        value_type totalPayment;
        value_type max;
        value_type min;
        int period;
        int type;

    public:
        Model(value_type amount, value_type percent, value_type tax, int period, int frequency, int capitalization);
        void DepositCalculator();
        reference getInvoiceSum();
        reference getTax();
    private:
        value_type tax;
        value_type invoiceSum;
        int frequency;
        int capitalization;
};

class Model::Stack {
    public:
        class Node;

        using value_type = long double;
        using reference = long double&;
        using const_reference = const long double&;
        using size_type = std::size_t;
        
        Stack();
        ~Stack();

        void push(const_reference data, type_t type = NUMBER, int priority = 0);
        void pop();
        value_type top() const; // по сути вообще не нужен
        size_type size() const;
        void moveElement(Stack& other);
        void spliceOperators(Stack& other);
        void spliceNumbers(Stack &other);

        int getPriority() const;
        value_type getData() const;
        type_t getType() const;
        Node* getNode() const;
    private:
        Node* peak{nullptr};
};

class Model::Stack::Node {
    public:
        Node(const_reference d, const int& priority, type_t t, Node* prev = nullptr);
    public: // private
        value_type data;
        int priority;
        type_t type;
        Node* prev;
};