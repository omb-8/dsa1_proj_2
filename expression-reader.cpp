#include "expression-reader.hpp"
#include "arithmetic-expression.hpp"
#include <sstream>
#include <iostream>

ExpressionReader::ExpressionReader(const std::string& filename) {
    infile.open(filename);
    if (!infile.is_open()) { std::cerr << "File not found\n"; exit(1); }
}

ExpressionReader::~ExpressionReader() { if (infile.is_open()) infile.close(); }

bool ExpressionReader::readNextExpression() {
    std::string line;
    if (!std::getline(infile, line)) return false;
    std::istringstream iss(line);
    std::string op1, op2;
    char oper;
    iss >> op1 >> oper >> op2;
    ArithmeticExpression ae(op1, op2, oper);
    current = BigIntegerArithmetic(ae);
    return true;
}

std::string ExpressionReader::getResult() const { return current.getResults(); }
