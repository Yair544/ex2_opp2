#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "FormFieldBase.h"  // ⬅️ חדש: בסיס מופשט של כל שדה
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

    // ✅ addField כללי לכל טיפוס
    template<typename T>
    void addField(const std::string& label, sf::Vector2f pos, std::unique_ptr<Validator<T>> validator) {
        fields.emplace_back(std::make_unique<FormField<T>>(label, pos, std::move(validator)));
    }

protected:
    void validateAllFields();
    bool allValid() const;
    std::vector<std::string> getErrors() const;
    void finalizeFields();

private:
    std::vector<std::unique_ptr<FormFieldBase>> fields; // ⬅️ שינוי מ-FormField<std::string>
    std::size_t activeIndex = 0;

    sf::Clock cursorTimer;
    sf::Font font;

    sf::RenderWindow& window;
    DialogueManager* manager;
};
