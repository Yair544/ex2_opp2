#include "EventBookingForm.h"
#include "UIRenderer.h"

EventBookingForm::EventBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager) {
}

std::string EventBookingForm::getFormType() const {
    return "Event Booking";
}

void EventBookingForm::renderExtras(sf::RenderWindow& window) {
    // לא מציירים שום דבר מיוחד
}

void EventBookingForm::handleMouseExtras(sf::Vector2f mousePos) {
    // לא מתבצע שום דבר כאן
}
