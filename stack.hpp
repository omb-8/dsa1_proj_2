#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include "node.hpp"

class Stack {
private:
    Node* top;

public:
    Stack();
    ~Stack();

    void push(int value);
    int pop();
    int peek() const;
    bool empty() const;
    std::string toString() const;  // NEW for BigIntegerArithmetic
};

#endif
