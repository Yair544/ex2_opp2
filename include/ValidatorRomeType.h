#pragma once
#include "Validator.h"

class ValidatorRomeType : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        // בודק אם סוג החדר שנבחר נמצא ברשימה
        return value == "Single Room" || value == "Double Room" || value == "Family Room" || value == "Presidential Suite";
    }
};
