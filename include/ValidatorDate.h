#pragma once
#include "Validator.h"
#include <regex>

class ValidatorDate : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        // מאמת פורמט של תאריך (YYYY-MM-DD)
        return std::regex_match(value, std::regex("^\\d{4}-\\d{2}-\\d{2}$"));
    }
};
