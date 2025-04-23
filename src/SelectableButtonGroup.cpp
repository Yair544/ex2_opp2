#include "SelectableButtonGroup.h"

SelectableButtonGroup::SelectableButtonGroup(std::vector<std::string> items, float x, float y,
    float width, float height, float spacingX)
    : options(std::move(items)), startX(x), startY(y),
    buttonWidth(width), buttonHeight(height), spacing(spacingX) {
}

void SelectableButtonGroup::render(sf::RenderWindow& window, sf::Font& font) {
    float x = startX;
    for (int i = 0; i < options.size(); ++i) {
        sf::RectangleShape button(sf::Vector2f(buttonWidth, buttonHeight));
        button.setPosition(x, startY);
        button.setFillColor(i == selectedIndex ? sf::Color(0, 120, 255) : sf::Color::White);
        button.setOutlineThickness(2);
        button.setOutlineColor(sf::Color(160, 160, 160));
        window.draw(button);

        sf::Text label(options[i], font, 16);
        label.setFillColor(i == selectedIndex ? sf::Color::White : sf::Color::Black);
        label.setPosition(x + 10, startY + 5);
        window.draw(label);

        x += spacing;
    }
}

bool SelectableButtonGroup::handleClick(sf::Vector2f pos) {
    float x = startX;
    for (int i = 0; i < options.size(); ++i) {
        sf::FloatRect bounds(x, startY, buttonWidth, buttonHeight);
        if (bounds.contains(pos)) {
            selectedIndex = i;
            return true;
        }
        x += spacing;
    }
    return false;
}

std::string SelectableButtonGroup::getSelected() const {
    if (selectedIndex >= 0 && selectedIndex < options.size())
        return options[selectedIndex];
    return "";
}

int SelectableButtonGroup::getSelectedIndex() const {
    return selectedIndex;
}

void SelectableButtonGroup::setSelectedByText(const std::string& text) {
    for (int i = 0; i < options.size(); ++i) {
        if (options[i] == text) {
            selectedIndex = i;
            break;
        }
    }
}
