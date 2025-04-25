#pragma once
#include <string>
#include <sstream>

class Date {
public:
    int year;
    int month;
    int day;

    Date();

    static bool fromString(const std::string& str, Date& outDate);

    std::string toString() const;
};

inline std::istream& operator>>(std::istream& is, Date& d) {
    std::string str;
    is >> str;
    if (!Date::fromString(str, d)) {
        is.setstate(std::ios::failbit);
    }
    return is;
}