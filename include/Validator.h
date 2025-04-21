#pragma once
#include <string>

template<typename T>
class Validator {
public:
    virtual bool validate(const T& value) const = 0; // ������� ��������� �����
    virtual ~Validator() = default; // ��-���������� ��������
};
