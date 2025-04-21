#pragma once
#include "BookingForm.h"
#include "NameValidator.h"
#include "IDValidator.h"
#include "EmailValidator.h"
#include "GuestsValidator.h"
#include "AddressValidator.h"
#include "DateValidator.h"
#include "RoomTypeValidator.h"

class HotelBookingForm : public BookingForm {
public:
    HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager);

    std::string getFormType() const override { return "Hotel Booking Form"; }
};
