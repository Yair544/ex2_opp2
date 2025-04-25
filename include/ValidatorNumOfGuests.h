#pragma once
#include "Validator.h"

class ValidatorNumOfGuests : public Validator<int> {
public:
    bool validate(const int& guests) const override {
        return guests >= 1 && guests <= 15;
    }

    std::string getErrorMessage() const override {
        return "Number of guests must be between 1 and 15.";
    }
};
