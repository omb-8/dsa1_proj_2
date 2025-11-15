#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>

class Operand {
private:
    std::string value;
    bool negative;

public:
    Operand();
    Operand(const std::string& val);

    bool isNegative() const;
    std::string getValue() const;
    void setValue(const std::string& val);
    void flipSign();
};

#endif