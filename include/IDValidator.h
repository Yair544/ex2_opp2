#pragma once
#include "Validator.h"
#include <cctype>

class IDValidator : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        if (value.length() != 9 || !std::all_of(value.begin(), value.end(), ::isdigit)) return false;

        int sum = 0;
        for (int i = 0; i < 9; ++i) {
            int digit = value[i] - '0';
            int step = digit * ((i % 2) + 1);
            if (step > 9) step -= 9;
            sum += step;
        }
        return sum % 10 == 0;
    }
};
