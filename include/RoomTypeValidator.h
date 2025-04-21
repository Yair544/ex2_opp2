#pragma once
#include "Validator.h"

class RoomTypeValidator : public Validator<std::string> {
public:
    bool validate(const std::string& value) const override {
        // ���� �� ��� ���� ����� ���� ������
        return value == "Single Room" || value == "Double Room" || value == "Family Room" || value == "Presidential Suite";
    }
};
