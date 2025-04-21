#pragma once
#include "Validator.h"
#include <regex>

class AddressValidator : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        // מתאם כתובת לדפוס מסויים
        return std::regex_match(value, std::regex("^[A-Za-z0-9\\-]+(\\-[A-Za-z0-9]+)*$"));
    }
};
