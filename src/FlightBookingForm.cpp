#include "FlightBookingForm.h"
#include "DialogueManager.h"
#include "SelectableButtonGroup.h"
#include <ctime>

FlightBookingForm::FlightBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager),
    timeSelector({ "Morning", "Noon", "Evening", "Night", "Don't Care" }, 10, 450) {

    fieldLabels = { "Name:", "ID:", "Address:", "Email:", "Departure Airport:", "Arrival Airport:", "Departure Date:", "Preferred Time:" };
    userInput.resize(fieldLabels.size(), "");
    setDefaultValues();
}

void FlightBookingForm::setDefaultValues() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    userInput[6] = std::to_string(1900 + ltm.tm_year) + "-" +
        std::to_string(1 + ltm.tm_mon) + "-" +
        std::to_string(ltm.tm_mday);

    userInput[7] = "Don't Care";
    timeSelector.setSelectedByText("Don't Care");
}

std::string FlightBookingForm::getFormType() const {
    return "Flight Booking";
}

void FlightBookingForm::renderExtras(sf::RenderWindow& window) {
    timeSelector.render(window, font);
}

void FlightBookingForm::handleMouseExtras(sf::Vector2f mousePos) {
    if (timeSelector.handleClick(mousePos)) {
        userInput[7] = timeSelector.getSelected();
    }
}
