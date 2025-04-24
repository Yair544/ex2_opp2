#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <sstream>
#include "Validator.h"
#include "FormFieldBase.h"

template<typename T>
class FormField : public FormFieldBase {
public:
    FormField(const std::string& lbl, sf::Vector2f pos, std::unique_ptr<Validator<T>> val)
        : value_m{}, m_validator(std::move(val)) {
        label_m = lbl;
        position_m = pos;
    }

    void draw(sf::RenderWindow& window, sf::Font& font, bool cursorVisible = false) override {
        sf::Text labelText(label_m, font, 18);
        labelText.setPosition(position_m);
        labelText.setFillColor(sf::Color::Black);
        window.draw(labelText);

        sf::RectangleShape box(sf::Vector2f(300, 35));
        box.setPosition(position_m.x + 160, position_m.y);
        box.setFillColor(sf::Color::White);
        box.setOutlineThickness(2);
        box.setOutlineColor(isActive_m ? sf::Color(0, 120, 255) : (isValid_m ? sf::Color(160, 160, 160) : sf::Color::Red));
        window.draw(box);

        std::string valStr = inputBuffer_m;
        if (isActive_m && cursorVisible) valStr += "|";
        sf::Text valText(valStr, font, 16);
        valText.setPosition(position_m.x + 165, position_m.y + 5);
        valText.setFillColor(sf::Color::Black);
        window.draw(valText);
    }

    void setActive(bool active) override {
        isActive_m = active;
    }

    void handleInput(sf::Event event) override {
        if (!isActive_m) return;

        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b') {
                if (!inputBuffer_m.empty()) inputBuffer_m.pop_back();
            }
            else if (event.text.unicode >= 32 && event.text.unicode < 128) {
                inputBuffer_m += static_cast<char>(event.text.unicode);
            }
        }
    }

    void validate() override {
        try {
            set(inputBuffer_m);
            isValid_m = m_validator->validate(value_m);
        }
        catch (...) {
            isValid_m = false;
        }
    }

    void set(const std::string& str) override {
        std::istringstream iss(str);
        iss >> value_m;
    }

    bool isFieldValid() const override {
        return isValid_m;
    }

    std::string getLabel() const override {
        return label_m;
    }

    std::string getValue() const override {
        return inputBuffer_m;
    }

    bool containsPoint(const sf::Vector2f& clickPos) const override {
        return clickPos.x > position_m.x && clickPos.x < position_m.x + 300 &&
            clickPos.y > position_m.y && clickPos.y < position_m.y + 35;
    }

private:
    T value_m{};
    std::unique_ptr<Validator<T>> m_validator;
};
