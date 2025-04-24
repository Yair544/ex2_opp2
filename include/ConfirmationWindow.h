#pragma once
#include <string>
#include <vector>

class ConfirmationWindow {
public:
    static bool show(const std::string& title,
        const std::vector<std::string>& labels,
        const std::vector<std::string>& values,
        const std::vector<bool>& validities);

};
