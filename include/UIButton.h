#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

class UIButton {
private:
    sf::Vector2f position;
    sf::Vector2f size;
    std::string text;
    sf::Color backgroundColor;
    sf::Color textColor;
    std::function<void()> onClick;

public:
    UIButton(const std::string& label,
        sf::Vector2f pos,
        sf::Vector2f size = { 140, 40 },
        sf::Color bg = sf::Color::Blue,
        sf::Color fg = sf::Color::White,
        std::function<void()> action = nullptr);

    void draw(sf::RenderWindow& window, const sf::Font& font) const;
    void handleClick(const sf::Vector2f& mousePos) const;

    void setOnClick(std::function<void()> action);  // ✅ זה מה שחסר לך
};

