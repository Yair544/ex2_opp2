#include "UIManager.h"
#include "UIButton.h"
#include "FlightBookingForm.h"
#include "HotelBookingForm.h"
#include "CarRentalForm.h"
#include "EventBookingForm.h"
#include "TrainBookingForm.h"
#include <iostream>

UIManager::UIManager(sf::RenderWindow& win, DialogueManager& dManager)
    : window(win), formManager(dManager) {

    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    // הוספת כפתורים בעזרת UIButton
    buttons.emplace_back("Flight Booking", sf::Vector2f(100, 150), sf::Vector2f(300, 50), sf::Color::Blue, sf::Color::White, [&]() {
        formManager.setActiveForm(std::make_unique<FlightBookingForm>(window, &formManager));
        });

    buttons.emplace_back("Hotel Booking", sf::Vector2f(100, 220), sf::Vector2f(300, 50), sf::Color::Blue, sf::Color::White, [&]() {
        formManager.setActiveForm(std::make_unique<HotelBookingForm>(window, &formManager));
        });

    buttons.emplace_back("Car Rental", sf::Vector2f(100, 290), sf::Vector2f(300, 50), sf::Color::Blue, sf::Color::White, [&]() {
        formManager.setActiveForm(std::make_unique<CarRentalForm>(window, &formManager));
        });

    buttons.emplace_back("Event Booking", sf::Vector2f(100, 360), sf::Vector2f(300, 50), sf::Color::Blue, sf::Color::White, [&]() {
        formManager.setActiveForm(std::make_unique<EventBookingForm>(window, &formManager));
        });

    buttons.emplace_back("Train Booking", sf::Vector2f(100, 430), sf::Vector2f(300, 50), sf::Color::Blue, sf::Color::White, [&]() {
        formManager.setActiveForm(std::make_unique<TrainBookingForm>(window, &formManager));
        });
}

void UIManager::render() {
    sf::Text title("Travel Booking System", font, 30);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(80, 20);
    window.draw(title);

    for (const auto& button : buttons) {
        button.draw(window, font);
    }
}

void UIManager::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        std::cout << "Mouse Clicked at: " << mousePos.x << ", " << mousePos.y << std::endl;

        for (const auto& button : buttons) {
            button.handleClick(mousePos);
        }
    }
}
