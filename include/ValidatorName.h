#pragma once
#include "Validator.h"
#include <regex>

class ValidatorName : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        return std::regex_match(value, std::regex("^[A-Za-z\\- ]+$"));
    }
};
