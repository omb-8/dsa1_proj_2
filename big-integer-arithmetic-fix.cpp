/*
My fixed version of big-integer-arithmetic.cpp.
I initialized the stack with the digits in the correct order (least significant digit on top).
I used operandComp to determine the order of subtraction and to handle negative results.
I truncated leading zeros from the result and formatted the output according to the test cases.
*/

#include "big-integer-arithmetic.hpp"
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>

BigIntegerArithmetic::BigIntegerArithmetic(const ArithmeticExpression& ae) {
    Stack s1, s2, sResult;
    // Extract operands and operator from the ArithmeticExpression
    std::string op1 = ae.getOp1();
    std::string op2 = ae.getOp2();
    char op = ae.getOperator();

    // Push digits onto stacks in reverse order (least significant digit on top)
    for (char c : op1)
        if (isdigit(c)) s1.push(c - '0');

    for (char c : op2)
        if (isdigit(c)) s2.push(c - '0');

    // Keep track of whether the result will be negative for subtraction
    bool negativeResult = false;
    if (op == '+') {
        add(s1, s2, sResult);
    } else if (op == '-') {
        // Determine which operand is larger for correct subtraction
        if (operandComp(op1, op2) >= 0) {
            subtract(s1, s2, sResult);
        } else {
            negativeResult = true;
            subtract(s2, s1, sResult);
        }
    }

    // Truncate leading zeros from the result (unless the result is zero)
    std::string resultStr = stackToString(sResult);
    std::size_t pos = resultStr.find_first_not_of('0');
    if (pos != std::string::npos) {
        resultStr = resultStr.substr(pos);
    } else {
        resultStr = "0";
    }
    
    // Format the output with proper alignment according to tests
    int widthNum = std::max({
        static_cast<int>(op1.length()),
        static_cast<int>(op2.length()),
        static_cast<int>(resultStr.length())
    });
    int totalWidth = widthNum + 1; // +1 for operator or space

    std::ostringstream oss;

    // First line: "   200" style
    oss << std::setw(totalWidth) << op1 << '\n';

    // Second line: "+100" or "-1000" style
    oss << op << std::setw(widthNum) << op2 << '\n';

    // Third line: positive vs negative result special-cased
    if (negativeResult) {
        std::string resWithSign = "-" + resultStr;
        // Right-align the whole "-res" in totalWidth columns
        oss << std::setw(totalWidth) << resWithSign;
    } else {
        // Space in column 0, digits right-aligned after that
        oss << ' ' << std::setw(widthNum) << resultStr;
    }

    results = oss.str();
}

void BigIntegerArithmetic::add(Stack& a, Stack& b, Stack& result) {
    int carry = 0;
    while (!a.empty() || !b.empty() || carry) {
        int x = a.empty() ? 0 : a.pop();
        int y = b.empty() ? 0 : b.pop();
        int sum = x + y + carry;
        result.push(sum % 10);
        carry = sum / 10;
    }
}

void BigIntegerArithmetic::subtract(Stack& a, Stack& b, Stack& result) {
    int borrow = 0;
    while (!a.empty() || !b.empty()) {
        int x = a.empty() ? 0 : a.pop();
        int y = b.empty() ? 0 : b.pop();
        int diff = x - y - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push(diff);
    }
}

// Convert stack to string (most significant digit first)
// NOTE: stackToString assumes MSD is on top (only use on result stack!)
std::string BigIntegerArithmetic::stackToString(Stack& s) const {
    Stack temp;
    std::string str;
    
    while (!s.empty()) {
        int d = s.pop();
        str += std::to_string(d);
        temp.push(d);
    }

    while (!temp.empty()) {
        s.push(temp.pop()); // Restore original stack
    }

    return str;
}
