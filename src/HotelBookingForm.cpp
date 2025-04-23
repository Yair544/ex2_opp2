#include "HotelBookingForm.h"
#include "DialogueManager.h"
#include "SelectableButtonGroup.h"
#include <ctime>


HotelBookingForm::HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager),
    roomSelector({ "Single Room", "Double Room", "Suite" }, 10, 500) {

    fieldLabels = { "Name:", "ID:", "Address:", "Email:", "Hotel Name:", "Check-in Date:", "Check-out Date:", "Number of Guests:", "Room Type:" };
    userInput.resize(fieldLabels.size(), "");
    setDefaultValues();
}

void HotelBookingForm::setDefaultValues() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    std::string today = std::to_string(1900 + ltm.tm_year) + "-" +
        std::to_string(1 + ltm.tm_mon) + "-" +
        std::to_string(ltm.tm_mday);

    userInput[5] = today; // Check-in
    userInput[6] = today; // Check-out
    userInput[8] = "Single Room"; // Default room
    roomSelector.setSelectedByText("Single Room");
}

std::string HotelBookingForm::getFormType() const {
    return "Hotel Booking";
}

void HotelBookingForm::renderExtras(sf::RenderWindow& window) {
    roomSelector.render(window, font);
}

void HotelBookingForm::handleMouseExtras(sf::Vector2f mousePos) {
    if (roomSelector.handleClick(mousePos)) {
        userInput[8] = roomSelector.getSelected();
    }
}
