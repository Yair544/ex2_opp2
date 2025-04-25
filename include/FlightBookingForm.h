#pragma once
#include "BookingForm.h"
#include "SelectableButtonGroup.h"

class FlightBookingForm : public BookingForm {
private:
    SelectableButtonGroup timeSelector;

    void setDefaultValues();
    void renderExtras(sf::RenderWindow& window) override;
    void handleMouseExtras(sf::Vector2f mousePos) override;

public:
    FlightBookingForm(sf::RenderWindow& win, DialogueManager* manager);
    std::string getFormType() const override;

};
