#include "TrainBookingForm.h"
#include "UIRenderer.h"

TrainBookingForm::TrainBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {
}

std::string TrainBookingForm::getFormType() const {
    return "Train Booking";
}

void TrainBookingForm::renderExtras(sf::RenderWindow& window) {
}

void TrainBookingForm::handleMouseExtras(sf::Vector2f mousePos) {
}
