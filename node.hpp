#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
    int value;
    Node* next;

public:
    Node(int val, Node* n = nullptr) : value(val), next(n) {}

    int getValue() const { return value; }
    Node* getNext() const { return next; }
    void setNext(Node* n) { next = n; }
};

#endif
