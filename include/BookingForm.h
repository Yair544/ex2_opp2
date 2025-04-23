// BookingForm.h
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class DialogueManager; // forward declaration

class BookingForm {
protected:
    sf::RenderWindow& window;
    DialogueManager* formManager;
    std::vector<std::string> fieldLabels;
    std::vector<std::string> userInput;
    int activeField = 0;
    sf::Clock cursorTimer;
    sf::Font font;

    virtual void renderExtras(sf::RenderWindow& window) {}
    virtual void handleMouseExtras(sf::Vector2f mousePos) {}

public:
    BookingForm(sf::RenderWindow& win, DialogueManager* manager);
    virtual ~BookingForm() = default;

    virtual void render(sf::RenderWindow& window);
    virtual void handleInput(sf::Event event);
    virtual std::string getFormType() const = 0;
    virtual void setDefaultValues() {}
    virtual void openConfirmationWindow();


};