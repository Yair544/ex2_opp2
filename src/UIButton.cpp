#include "UIButton.h"

UIButton::UIButton(const std::string& label,
                   sf::Vector2f pos,
                   sf::Vector2f size,
                   sf::Color bg,
                   sf::Color fg,
                   std::function<void()> action)
    : text(label), position(pos), size(size),
      backgroundColor(bg), textColor(fg), onClick(action) {}

void UIButton::draw(sf::RenderWindow& window, const sf::Font& font) const {
    sf::RectangleShape button(size);
    button.setPosition(position);
    button.setFillColor(backgroundColor);
    window.draw(button);

    sf::Text buttonText(text, font, 20);
    buttonText.setFillColor(textColor);
    buttonText.setPosition(position.x + 0.5f * (size.x - buttonText.getLocalBounds().width) - 5, position.y + 5);
    window.draw(buttonText);
}

void UIButton::handleClick(const sf::Vector2f& mousePos) const {
    if (sf::FloatRect(position, size).contains(mousePos) && onClick) {
        onClick();
    }
}
void UIButton::setOnClick(std::function<void()> action) {
    onClick = action;
}
