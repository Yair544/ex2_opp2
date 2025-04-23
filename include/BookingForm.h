#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "UIButton.h"

class DialogueManager; // Forward declaration

class BookingForm {
protected:
    sf::RenderWindow& window;
    DialogueManager* formManager;
    sf::Font font;
    sf::Clock cursorTimer;

    std::vector<std::string> fieldLabels;
    std::vector<std::string> userInput;
    int activeField = 0;
    bool shouldClose = false;

    UIButton doneButton;
    UIButton cancelButton;

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
    bool needsClose() const;
};
