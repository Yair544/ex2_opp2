#pragma once
#include "Validator.h"
#include <regex>

class ValidatorDate : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        return std::regex_match(value, std::regex("^\\d{4}-\\d{2}-\\d{2}$"));
    }

    std::string getErrorMessage() const override {
        return "Date must be in YYYY-MM-DD format.";
    }
};
