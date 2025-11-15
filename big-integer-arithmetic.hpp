#ifndef BIG_INTEGER_ARITHMETIC_HPP
#define BIG_INTEGER_ARITHMETIC_HPP

#include <string>
#include "arithmetic-expression.hpp"
#include "stack.hpp"

class BigIntegerArithmetic {
private:
    std::string results;

    void add(Stack& a, Stack& b, Stack& result);
    void subtract(Stack& a, Stack& b, Stack& result);

    std::string stackToString(Stack& s) const;

public:
    BigIntegerArithmetic() = default;
    BigIntegerArithmetic(const ArithmeticExpression& ae);

    std::string getResults() const { return results; }

    // New function: compares two operands represented as strings of digits
    int operandComp(const std::string& op1, const std::string& op2) const {
        if (op1.length() > op2.length()) return 1;
        if (op1.length() < op2.length()) return -1;
        return op1.compare(op2); // lexicographical compare works for equal-length numbers
    }
};

#endif
