#pragma once
#include "BookingForm.h"
#include "DialogueManager.h"

class CarRentalForm : public BookingForm {
public:
    CarRentalForm(sf::RenderWindow& win, DialogueManager* manager);

    std::string getFormType() const override;
    void renderExtras(sf::RenderWindow& window) override;
    void handleMouseExtras(sf::Vector2f mousePos) override;
};
