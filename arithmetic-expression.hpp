#ifndef ARITHMETIC_EXPRESSION_HPP
#define ARITHMETIC_EXPRESSION_HPP

#include "operand.hpp"
#include <string>

class ArithmeticExpression {
private:
    Operand op1;
    Operand op2;
    char oper;

public:
    ArithmeticExpression();
    ArithmeticExpression(const std::string& a, const std::string& b, char c);

    std::string getOp1() const;
    std::string getOp2() const;
    char getOperator() const;
};

#endif