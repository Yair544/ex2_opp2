#include "FlightBookingForm.h"
#include "DialogueManager.h"
#include "FormField.h"
#include "ValidatorName.h"
#include "ValidatorID.h"
#include "ValidatorAddress.h"
#include "ValidatorEmail.h"
#include "ValidatorDate.h"
#include <ctime>

FlightBookingForm::FlightBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager),
    timeSelector({ "Morning", "Noon", "Evening", "Night", "Don't Care" }, 10, 500)
{
    fields.emplace_back(std::make_unique<FormField<std::string>>("Name:", sf::Vector2f(20, 60), std::make_unique<ValidatorName>()));
    fields.emplace_back(std::make_unique<FormField<uint32_t>>("ID:", sf::Vector2f(20, 110), std::make_unique<ValidatorID>()));
    fields.emplace_back(std::make_unique<FormField<std::string>>("Address:", sf::Vector2f(20, 160), std::make_unique<ValidatorAddress>()));
    fields.emplace_back(std::make_unique<FormField<std::string>>("Email:", sf::Vector2f(20, 210), std::make_unique<ValidatorEmail>()));
    fields.emplace_back(std::make_unique<FormField<std::string>>("Departure Airport:", sf::Vector2f(20, 260), std::make_unique<ValidatorName>()));
    fields.emplace_back(std::make_unique<FormField<std::string>>("Arrival Airport:", sf::Vector2f(20, 310), std::make_unique<ValidatorName>()));
    fields.emplace_back(std::make_unique<FormField<std::string>>("Departure Date:", sf::Vector2f(20, 360), std::make_unique<ValidatorDate>()));
    fields.emplace_back(std::make_unique<FormField<std::string>>("Preferred Time:", sf::Vector2f(20, 410), std::make_unique<ValidatorName>()));

    setDefaultValues();
}

void FlightBookingForm::setDefaultValues() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    auto format = [](int n) -> std::string {
        return (n < 10 ? "0" : "") + std::to_string(n);
        };

    std::string today = std::to_string(1900 + ltm.tm_year) + "-" +
        format(1 + ltm.tm_mon) + "-" +
        format(ltm.tm_mday);

    fields[6]->set(today);               // Departure Date
    fields[7]->set("Don't Care");        // Preferred Time
    timeSelector.setSelectedByText("Don't Care");

    for (auto& field : fields)
        field->validate();
}

std::string FlightBookingForm::getFormType() const {
    return "Flight Booking";
}

void FlightBookingForm::renderExtras(sf::RenderWindow& window) {
    timeSelector.render(window, font);
}

void FlightBookingForm::handleMouseExtras(sf::Vector2f mousePos) {
    if (timeSelector.handleClick(mousePos)) {
        fields[7]->set(timeSelector.getSelected());  // Update Preferred Time
    }
}
