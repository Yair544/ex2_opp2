#pragma once
#include "BookingForm.h"
#include "ValidatorName.h"
#include "ValidatorID.h"
#include "ValidatorEmail.h"
#include "ValidatorNumOfGuests.h"
#include "ValidatorAddress.h"
#include "ValidatorDate.h"
#include "ValidatorRomeType.h"

class HotelBookingForm : public BookingForm {
public:
    HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager);

    std::string getFormType() const override { return "Hotel Booking Form"; }
};
