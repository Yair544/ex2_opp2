#pragma once
#include "Validator.h"

class ValidatorTimePreference : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        return value == "Morning" || value == "Noon" ||
            value == "Evening" || value == "Night" || value == "Don't Care";
    }

    std::string getErrorMessage() const override {
        return "Preferred time must be Morning, Noon,\n Evening, Night or Don't Care.";
    }
};
