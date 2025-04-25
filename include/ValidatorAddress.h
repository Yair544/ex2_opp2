#pragma once
#include "Validator.h"
#include <regex>

class ValidatorAddress : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        return std::regex_match(value, std::regex("^[A-Za-z0-9\\-]+(\\-[A-Za-z0-9]+)*$"));
    }

    std::string getErrorMessage() const override {
        return "Address must contain only letters, numbers, and hyphens.";
    }
};
