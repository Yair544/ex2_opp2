#include "HotelBookingForm.h"
#include "DialogueManager.h"

HotelBookingForm::HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : BookingForm(win, manager)
{
    // הוספת שדות לכל פרטי ההזמנה
    addField("Name:", { 20, 50 }, std::make_unique<NameValidator>());
    addField("ID:", { 20, 110 }, std::make_unique<IDValidator>());
    addField("Email:", { 20, 170 }, std::make_unique<EmailValidator>());
    addField("Address:", { 20, 230 }, std::make_unique<AddressValidator>());
    addField("Hotel Name:", { 20, 290 }, std::make_unique<NameValidator>());
    addField("Check-in Date:", { 20, 350 }, std::make_unique<DateValidator>());
    addField("Check-out Date:", { 20, 410 }, std::make_unique<DateValidator>());
    addField("Guests:", { 20, 470 }, std::make_unique<GuestsValidator>());
    addField("Room Type:", { 20, 530 }, std::make_unique<RoomTypeValidator>());


    finalizeFields();  // הפעלת השדה הראשון בפועל
}
