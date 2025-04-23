#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class FormFieldBase {
public:
    virtual ~FormFieldBase() = default;

    virtual void draw(sf::RenderWindow& window, sf::Font& font, bool cursorVisible = false) = 0;
    virtual void setActive(bool active) = 0;
    virtual void handleInput(sf::Event event) = 0;
    virtual void validate() = 0;
    virtual bool isFieldValid() const = 0;
    virtual std::string getLabel() const = 0;
    virtual std::string getValue() const = 0;
    virtual bool containsPoint(const sf::Vector2f& clickPos) const = 0;
    virtual void set(const std::string& str) = 0;

protected:
    std::string label_m;
    sf::Vector2f position_m;
    std::string inputBuffer_m;
    bool isActive_m = false;
    bool isValid_m = true;
};
