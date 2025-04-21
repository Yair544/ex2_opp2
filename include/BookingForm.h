// BookingForm.h
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "FormField.h"
#include "Validator.h"

class DialogueManager;

class BookingForm {
public:
    BookingForm(sf::RenderWindow& win, DialogueManager* mng);
    virtual ~BookingForm() = default;

    virtual std::string getFormType() const = 0;

    void render(sf::RenderWindow& win);
    void handleInput(sf::Event event);
    void openConfirmationWindow();
    void addField(const std::string& label, sf::Vector2f pos, std::unique_ptr<Validator<std::string>> validator);


protected:
    void validateAllFields();
    bool allValid() const;
    std::vector<std::string> getErrors() const;
    void finalizeFields();  // נועד להפעלה אוטומטית אחרי יצירת שדות

private:
    std::vector<std::unique_ptr<FormField<std::string>>> fields;
    std::size_t activeIndex = 0;

    sf::Clock cursorTimer;
    sf::Font font;

    sf::RenderWindow& window;
    DialogueManager* manager;
};
