#pragma once
#include "Validator.h"
#include <cctype>

class ValidatorID : public Validator<uint32_t> {
public:
    bool validate(const uint32_t& value) const override {
        std::string str = std::to_string(value);
        if (str.length() != 9 || !std::all_of(str.begin(), str.end(), ::isdigit))
            return false;

        int sum = 0;
        for (int i = 0; i < 9; ++i) {
            int digit = str[i] - '0';
            int step = digit * ((i % 2) + 1);
            if (step > 9) step -= 9;
            sum += step;
        }
        return sum % 10 == 0;
    }

    std::string getErrorMessage() const override {
        return "ID must be 9 digits with a valid Israeli check digit.";
    }
};
