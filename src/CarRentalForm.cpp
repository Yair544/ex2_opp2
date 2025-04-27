#include "CarRentalForm.h"
#include "UIRenderer.h"

CarRentalForm::CarRentalForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {
}

std::string CarRentalForm::getFormType() const {
    return "Car Rental";
}

void CarRentalForm::renderExtras(sf::RenderWindow& window) {
}

void CarRentalForm::handleMouseExtras(sf::Vector2f mousePos) {
}
