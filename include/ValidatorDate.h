#pragma once
#include "Validator.h"
#include "Date.h"

class ValidatorDate : public Validator<Date> {
public:
    bool validate(const Date& date) const override {
        if (date.year < 1900 || date.year > 2100)
            return false;
        if (date.month < 1 || date.month > 12)
            return false;
        if (date.day < 1 || date.day > 31)
            return false;

        return true;
    }

    std::string getErrorMessage() const override {
        return "Date must be a valid date between 1900 and 2100.";
    }
};
