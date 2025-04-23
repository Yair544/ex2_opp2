#pragma once
#include "BookingForm.h"
#include "SelectableButtonGroup.h"

class HotelBookingForm : public BookingForm {
private:
    SelectableButtonGroup roomSelector;

    void setDefaultValues();
    void renderExtras(sf::RenderWindow& window) override;
    void handleMouseExtras(sf::Vector2f mousePos) override;

public:
    HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager);
    std::string getFormType() const override;
};
