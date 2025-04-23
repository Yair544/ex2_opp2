#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class UIRenderer {
public:
    static void drawLabel(sf::RenderWindow& window, const sf::Font& font,
        const std::string& text, sf::Vector2f pos, unsigned size = 18);

    static void drawInputField(sf::RenderWindow& window, const sf::Font& font,
        const std::string& value, sf::Vector2f pos,
        bool active, float width = 250, float height = 35);
};
