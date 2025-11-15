#include "big-integer-arithmetic.hpp"
#include <string>
#include <algorithm>
#include <cctype>

BigIntegerArithmetic::BigIntegerArithmetic(const ArithmeticExpression& ae) {
    Stack s1, s2, sResult;

    // Push digits onto stacks in reverse order (least significant digit on top)
    for (auto it = ae.getOp1().rbegin(); it != ae.getOp1().rend(); ++it)
        if (isdigit(*it)) s1.push(*it - '0');

    for (auto it = ae.getOp2().rbegin(); it != ae.getOp2().rend(); ++it)
        if (isdigit(*it)) s2.push(*it - '0');

    if (ae.getOperator() == '+') {
        add(s1, s2, sResult);
        results = " " + ae.getOp1() + "\n+" + ae.getOp2() + "\n " + stackToString(sResult);
    } else if (ae.getOperator() == '-') {
        subtract(s1, s2, sResult);
        results = " " + ae.getOp1() + "\n-" + ae.getOp2() + "\n " + stackToString(sResult);
    }
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
std::string BigIntegerArithmetic::stackToString(Stack& s) const {
    Stack temp;
    while (!s.empty()) {
        temp.push(s.pop());
    }

    std::string str;
    while (!temp.empty()) {
        int d = temp.pop();
        str += std::to_string(d);
        s.push(d); // restore original stack
    }
    return str;
}
