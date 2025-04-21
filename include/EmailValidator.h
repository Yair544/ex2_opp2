#pragma once
#include "Validator.h"
#include <regex>

class EmailValidator : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        return std::regex_match(value, std::regex("^[\\w\\.-]+@[\\w\\.-]+\\.[a-zA-Z]{2,}$"));
    }
};
