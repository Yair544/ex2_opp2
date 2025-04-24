#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "UIButton.h"
#include "FormFieldBase.h"

class DialogueManager; // Forward declaration

class BookingForm {
protected:
    sf::RenderWindow& window;
    DialogueManager* formManager;
    sf::Font font;
    sf::Clock cursorTimer;

    std::vector<std::unique_ptr<FormFieldBase>> fields;
    int activeField = 0;

    UIButton doneButton;
    UIButton cancelButton;
    bool shouldClose;

    virtual void renderExtras(sf::RenderWindow& window) = 0;
    virtual void handleMouseExtras(sf::Vector2f mousePos) = 0;

public:
    BookingForm(sf::RenderWindow& win, DialogueManager* manager);
    virtual ~BookingForm() = default;

    void render(sf::RenderWindow& window);
    void handleInput(sf::Event event);
    void openConfirmationWindow();
    bool needsClose() const;
    virtual std::string getFormType() const = 0;
};
