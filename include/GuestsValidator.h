#pragma once
#include "Validator.h"

class GuestsValidator : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        try {
            int guests = std::stoi(value);
            return guests >= 1 && guests <= 10;
        }
        catch (...) {
            return false;
        }
    }
};
