#pragma once
#include "Validator.h"

class ValidatorRomeType : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        return value == "Single Room" || value == "Double Room" ||
            value == "Family Room" || value == "Presidential Suite";
    }

    std::string getErrorMessage() const override {
        return "Room type must be Single Room, Double Room, Family Room, or Presidential Suite.";
    }
};
