#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class ConfirmationWindow {
public:
    static bool show(const std::string& title, const std::vector<std::string>& labels, const std::vector<std::string>& values);
};
