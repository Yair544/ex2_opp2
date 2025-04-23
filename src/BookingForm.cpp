// BookingForm.cpp
#include "BookingForm.h"
#include "DialogueManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ConfirmationWindow.h>

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager) : window(win), formManager(manager) {
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
}

void BookingForm::render(sf::RenderWindow& window) {
    window.clear(sf::Color(235, 235, 235));
    sf::Text title(getFormType(), font, 26);
    title.setFillColor(sf::Color(20, 20, 20));
    title.setStyle(sf::Text::Bold);
    title.setPosition(20, 10);
    window.draw(title);

    bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);
    int yOffset = 60;

    for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
        sf::Text label(fieldLabels[i], font, 18);
        label.setFillColor(sf::Color(60, 60, 60));
        label.setPosition(20, yOffset);
        window.draw(label);

        sf::RectangleShape inputBox(sf::Vector2f(250, 35));
        inputBox.setPosition(240, yOffset - 5);
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineThickness(2);
        inputBox.setOutlineColor(i == activeField ? sf::Color(0, 120, 255) : sf::Color(160, 160, 160));
        window.draw(inputBox);

        std::string displayText = userInput[i];
        if (i == activeField && cursorVisible) displayText += "|";

        sf::Text inputText(displayText, font, 16);
        inputText.setFillColor(sf::Color::Black);
        inputText.setPosition(245, yOffset);
        window.draw(inputText);

        yOffset += 50;
    }

    renderExtras(window);

    // Buttons
    sf::RectangleShape submitButton(sf::Vector2f(140, 40));
    submitButton.setPosition(20, 570);
    submitButton.setFillColor(sf::Color(50, 150, 50));
    window.draw(submitButton);

    sf::Text submitText("DONE", font, 20);
    submitText.setFillColor(sf::Color::White);
    submitText.setPosition(50, 580);
    window.draw(submitText);

    sf::RectangleShape cancelButton(sf::Vector2f(140, 40));
    cancelButton.setPosition(200, 570);
    cancelButton.setFillColor(sf::Color(180, 0, 0));
    window.draw(cancelButton);

    sf::Text cancelText("CANCEL", font, 20);
    cancelText.setFillColor(sf::Color::White);
    cancelText.setPosition(230, 580);
    window.draw(cancelText);
}

void BookingForm::handleInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == '\b' && !userInput[activeField].empty()) {
            userInput[activeField].pop_back();
        }
        else if (event.text.unicode >= 32 && event.text.unicode < 128) {
            userInput[activeField] += static_cast<char>(event.text.unicode);
        }
    }
    else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Tab) {
            activeField = (activeField + 1) % userInput.size();
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
        int yOffset = 60;
        for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
            sf::FloatRect inputBoxBounds(260, yOffset - 5, 250, 35);
            if (inputBoxBounds.contains(mousePos)) {
                activeField = i;
                return;
            }
            yOffset += 50;
        }

        if (mousePos.x >= 20 && mousePos.x <= 160 && mousePos.y >= 570 && mousePos.y <= 610) {
            std::cout << getFormType() << " Confirmed!\n";
            openConfirmationWindow();
            return;
        }
        if (mousePos.x >= 200 && mousePos.x <= 340 && mousePos.y >= 570 && mousePos.y <= 610) {
            std::cout << "Cancelled " << getFormType() << "\n";
            formManager->closeForm();
            return;
        }

        handleMouseExtras(mousePos);
    }
}
/////////////////////////////
void BookingForm::openConfirmationWindow() {
    if (ConfirmationWindow::show(getFormType(), fieldLabels, userInput)) {
        formManager->closeForm();
    }
}