#include "HotelBookingForm.h"
#include "DialogueManager.h"
#include "FormField.h"
#include "ValidatorName.h"
#include "ValidatorID.h"
#include "ValidatorAddress.h"
#include "ValidatorEmail.h"
#include "ValidatorDate.h"
#include "ValidatorNumOfGuests.h"
#include "ValidatorRomeType.h"
#include <ctime>

HotelBookingForm::HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager),
    roomSelector({ "Single Room", "Double Room", "Suite" }, 10, 500)
{
    fields.emplace_back(std::make_unique<FormField<std::string>>("Name:", sf::Vector2f(20, 60), std::make_unique<ValidatorName>()));
    fields.emplace_back(std::make_unique<FormField<uint32_t>>("ID:", sf::Vector2f(20, 110), std::make_unique<ValidatorID>()));
    fields.emplace_back(std::make_unique<FormField<std::string>>("Address:", sf::Vector2f(20, 160), std::make_unique<ValidatorAddress>()));
    fields.emplace_back(std::make_unique<FormField<std::string>>("Email:", sf::Vector2f(20, 210), std::make_unique<ValidatorEmail>()));
    fields.emplace_back(std::make_unique<FormField<std::string>>("Hotel Name:", sf::Vector2f(20, 260), std::make_unique<ValidatorName>()));
    fields.emplace_back(std::make_unique<FormField<Date>>("Check-in Date:", sf::Vector2f(20, 310), std::make_unique<ValidatorDate>()));
    fields.emplace_back(std::make_unique<FormField<Date>>("Check-out Date:", sf::Vector2f(20, 360), std::make_unique<ValidatorDate>()));
    fields.emplace_back(std::make_unique<FormField<int>>("Number of Guests:", sf::Vector2f(20, 410), std::make_unique<ValidatorNumOfGuests>()));
    fields.emplace_back(std::make_unique<FormField<std::string>>("Room Type:", sf::Vector2f(20, 460), std::make_unique<ValidatorRomeType>()));

    setDefaultValues();
}

void HotelBookingForm::setDefaultValues() {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    auto format = [](int n) -> std::string {
        return (n < 10 ? "0" : "") + std::to_string(n);
        };

    std::string today = std::to_string(1900 + ltm.tm_year) + "-" +
        format(1 + ltm.tm_mon) + "-" +
        format(ltm.tm_mday);

    fields[5]->set(today); // Check-in
    fields[6]->set(today); // Check-out
    fields[8]->set("Single Room"); // Room Type
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
        fields[8]->set(roomSelector.getSelected());
    }
}
