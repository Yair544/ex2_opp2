#include "UIRenderer.h"

void UIRenderer::drawLabel(sf::RenderWindow& window, const sf::Font& font,
    const std::string& text, sf::Vector2f pos, unsigned size) {
    sf::Text label(text, font, size);
    label.setFillColor(sf::Color(60, 60, 60));
    label.setPosition(pos);
    window.draw(label);
}

void UIRenderer::drawInputField(sf::RenderWindow& window, const sf::Font& font,
    const std::string& value, sf::Vector2f pos,
    bool active, float width, float height) {
    sf::RectangleShape inputBox(sf::Vector2f(width, height));
    inputBox.setPosition(pos);
    inputBox.setFillColor(sf::Color::White);
    inputBox.setOutlineThickness(2);
    inputBox.setOutlineColor(active ? sf::Color(0, 120, 255) : sf::Color(160, 160, 160));
    window.draw(inputBox);

    sf::Text inputText(value, font, 16);
    inputText.setFillColor(sf::Color::Black);
    inputText.setPosition(pos.x + 5, pos.y + 5);
    window.draw(inputText);
}
