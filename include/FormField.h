#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "Validator.h"

template<typename T>
class FormField {
public:
    FormField(const std::string& lbl, sf::Vector2f pos, std::unique_ptr<Validator<T>> val)
        : label(lbl), position(pos), m_validator(std::move(val)), isActive(false), isValid(true) {
    }

    void draw(sf::RenderWindow& window, sf::Font& font, bool cursorVisible = false) {
        sf::Text labelText(label, font, 18);
        labelText.setPosition(position);
        labelText.setFillColor(sf::Color::Black);
        window.draw(labelText);

        sf::RectangleShape box(sf::Vector2f(300, 35));
        box.setPosition(position.x + 160, position.y);
        box.setFillColor(sf::Color::White);
        box.setOutlineThickness(2);
        box.setOutlineColor(isActive ? sf::Color(0, 120, 255) : (isValid ? sf::Color(160, 160, 160) : sf::Color::Red));
        window.draw(box);

        std::string valStr = value;
        if (isActive && cursorVisible) valStr += "|";
        sf::Text valText(valStr, font, 16);
        valText.setPosition(position.x + 165, position.y + 5);
        valText.setFillColor(sf::Color::Black);
        window.draw(valText);
    }

    void setActive(bool active) {
        isActive = active;
    }

    void handleInput(sf::Event event) {
        if (!isActive) return;

        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b') {
                if (!value.empty()) value.pop_back();
            }
            else if (event.text.unicode >= 32 && event.text.unicode < 128) {
                value += static_cast<char>(event.text.unicode);
            }
        }
    }

    void validate() {
        isValid = m_validator->validate(value); // קריאה לוולידטור המתאים לשדה
    }

    bool isFieldValid() const {
        return isValid;
    }

    std::string getLabel() const {
        return label;
    }

    std::string getValue() const {
        return value;
    }

    bool containsPoint(const sf::Vector2f& clickPos) const {
        return clickPos.x > position.x && clickPos.x < position.x + 300 &&
            clickPos.y > position.y && clickPos.y < position.y + 35;
    }

private:
    std::string label;
    sf::Vector2f position;
    T value; // ערך השדה
    bool isActive; // קובע אם השדה פעיל
    bool isValid; // קובע אם השדה תקין
    std::unique_ptr<Validator<T>> m_validator; // וולידטור לטיפוס הספציפי של השדה
};
