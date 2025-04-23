#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class SelectableButtonGroup {
private:
    std::vector<std::string> options;
    int selectedIndex = -1;
    float startX, startY, buttonWidth, buttonHeight, spacing;

public:
    SelectableButtonGroup(std::vector<std::string> items, float x, float y,
        float width = 150, float height = 30, float spacingX = 160);

    void render(sf::RenderWindow& window, sf::Font& font);
    bool handleClick(sf::Vector2f pos);
    std::string getSelected() const;
    int getSelectedIndex() const;
    void setSelectedByText(const std::string& text);
};
