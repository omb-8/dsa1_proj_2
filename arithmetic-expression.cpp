#include "arithmetic-expression.hpp"

// Default constructor
ArithmeticExpression::ArithmeticExpression()
    : op1("0"), op2("0"), oper('+') {}

// Constructor with operands and operator
ArithmeticExpression::ArithmeticExpression(const std::string& a, const std::string& b, char c)
    : op1(a), op2(b), oper(c) 
{
    // Adjust operator if second operand is negative
    if (op2.isNegative()) {
        op2.flipSign();
        if (oper == '+') oper = '-';
        else if (oper == '-') oper = '+';
    }
}

// Get first operand
std::string ArithmeticExpression::getOp1() const {
    return op1.getValue();
}

// Get second operand
std::string ArithmeticExpression::getOp2() const {
    return op2.getValue();
}

// Get operator
char ArithmeticExpression::getOperator() const {
    return oper;
}