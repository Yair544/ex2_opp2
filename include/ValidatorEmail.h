#pragma once
#include "Validator.h"
#include <regex>

class ValidatorEmail : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        return std::regex_match(value, std::regex("^[\\w\\.-]+@[\\w\\.-]+\\.[a-zA-Z]{2,}$"));
    }

    std::string getErrorMessage() const override {
        return "Email must be in a valid format like user@example.com.";
    }
};
