#pragma once
#include "BookingForm.h"
#include "DialogueManager.h"

class EventBookingForm : public BookingForm {
public:
    EventBookingForm(sf::RenderWindow& win, DialogueManager* manager);

    std::string getFormType() const override;
    void renderExtras(sf::RenderWindow& window) override;
    void handleMouseExtras(sf::Vector2f mousePos) override;
};
