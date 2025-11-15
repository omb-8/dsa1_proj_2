#include "stack.hpp"
#include <string>

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    while (!empty()) pop();
}

void Stack::push(int value) {
    Node* n = new Node(value, top);
    top = n;
}

int Stack::pop() {
    if (top == nullptr) return -1;  // <- correct return for empty stack
    int val = top->getValue();
    Node* temp = top;
    top = top->getNext();
    delete temp;
    return val;
}

int Stack::peek() const {
    return empty() ? 0 : top->getValue();
}

bool Stack::empty() const {
    return top == nullptr;
}

std::string Stack::toString() const {
    std::string s;
    Node* current = top;
    while (current != nullptr) {
        s = std::to_string(current->getValue()) + s;
        current = current->getNext();
    }
    return s.empty() ? "0" : s;
}
