#include "operand.hpp"

Operand::Operand() : value("0"), negative(false) {}

Operand::Operand(const std::string& val) {
    if (!val.empty() && val[0] == '-') {
        negative = true;
        value = val; // keep the '-' for getValue()
    } else if (!val.empty() && val[0] == '+') {
        negative = false;
        value = val.substr(1); // remove '+' sign
    } else {
        negative = false;
        value = val;
    }
}

bool Operand::isNegative() const {
    return negative;
}

std::string Operand::getValue() const {
    return value;
}

void Operand::setValue(const std::string& val) {
    if (!val.empty() && val[0] == '-') {
        negative = true;
        value = val;
    } else if (!val.empty() && val[0] == '+') {
        negative = false;
        value = val.substr(1);
    } else {
        negative = false;
        value = val;
    }
}

void Operand::flipSign() {
    if (negative) {
        negative = false;
        if (value[0] == '-') value = value.substr(1);
    } else {
        negative = true;
        value = "-" + value;
    }
}
