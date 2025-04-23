#include "HotelBookingForm.h"
#include "DialogueManager.h"
#include "BookingForm.h"

HotelBookingForm::HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager)
{
    // הוספת שדות לכל פרטי ההזמנה
    addField<std::string>("Name:", { 20, 50 }, std::make_unique<ValidatorName>());
    addField<uint32_t>("ID:", { 20, 110 }, std::make_unique<ValidatorID>());
    addField<std::string>("Email:", { 20, 170 }, std::make_unique<ValidatorEmail>());
    addField<std::string>("Address:", { 20, 230 }, std::make_unique<ValidatorAddress>());
    addField<std::string>("Hotel Name:", { 20, 290 }, std::make_unique<ValidatorName>());
    addField<std::string>("Check-in Date:", { 20, 350 }, std::make_unique<ValidatorDate>());
    addField<std::string>("Check-out Date:", { 20, 410 }, std::make_unique<ValidatorDate>());
    addField<std::string>("Guests:", { 20, 470 }, std::make_unique<ValidatorNumOfGuests>());
    addField<std::string>("Room Type:", { 20, 530 }, std::make_unique<ValidatorRomeType>());


    finalizeFields();  // הפעלת השדה הראשון בפועל
}
