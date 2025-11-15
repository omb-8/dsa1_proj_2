#ifndef EXPRESSION_READER_HPP
#define EXPRESSION_READER_HPP

#include "big-integer-arithmetic.hpp"
#include <fstream>
#include <string>

class ExpressionReader {
private:
    std::ifstream infile;
    BigIntegerArithmetic current;

public:
    ExpressionReader(const std::string& filename);
    ~ExpressionReader();
    bool readNextExpression();
    std::string getResult() const;
};

#endif
