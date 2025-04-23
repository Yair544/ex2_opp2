#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "BookingForm.h"

class DialogueManager {
private:
    std::unique_ptr<BookingForm> activeForm;
    bool isFormOpen;
    sf::RenderWindow formWindow;

public:
    DialogueManager();

    void setActiveForm(std::unique_ptr<BookingForm> form);
    void closeForm();
    void handleFormEvents();
};
