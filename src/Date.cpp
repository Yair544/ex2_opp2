#include "Date.h"
#include <stdexcept>

Date::Date() : year(0), month(0), day(0) {}

bool Date::fromString(const std::string& str, Date& outDate) {
    if (str.length() != 10 || str[4] != '-' || str[7] != '-')
        return false;

    try {
        outDate.year = std::stoi(str.substr(0, 4));
        outDate.month = std::stoi(str.substr(5, 2));
        outDate.day = std::stoi(str.substr(8, 2));

        if (outDate.month < 1 || outDate.month > 12)
            return false;
        if (outDate.day < 1 || outDate.day > 31)
            return false;

        return true;
    }
    catch (...) {
        return false;
    }
}

std::string Date::toString() const {
    std::string result = std::to_string(year) + "-";

    if (month < 10) result += "0";
    result += std::to_string(month) + "-";

    if (day < 10) result += "0";
    result += std::to_string(day);

    return result;
}
