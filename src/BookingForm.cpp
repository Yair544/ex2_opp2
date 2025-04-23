#include "BookingForm.h"
#include "DialogueManager.h"
#include "ConfirmationWindow.h"
#include "UIRenderer.h"
#include <iostream>

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : window(win), formManager(manager), shouldClose(false),
    doneButton("DONE", { 20, 570 }, { 140, 40 }, sf::Color(50, 150, 50), sf::Color::White, [&]() {
    std::cout << getFormType() << " Confirmed!\n";
    openConfirmationWindow();
        }),
    cancelButton("CANCEL", { 200, 570 }, { 140, 40 }, sf::Color(180, 0, 0), sf::Color::White, [&]() {
    std::cout << "Cancelled " << getFormType() << "\n";
    shouldClose = true;  // ✅ במקום closeForm()
        }) {

    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
}

void BookingForm::render(sf::RenderWindow& window) {
    window.clear(sf::Color(235, 235, 235));
    UIRenderer::drawLabel(window, font, getFormType(), { 20, 10 }, 26);

    bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);
    int yOffset = 60;

    for (std::size_t i = 0; i < fieldLabels.size(); ++i) {
        std::string displayText = userInput[i];
        if (i == activeField && cursorVisible)
            displayText += "|";

        UIRenderer::drawLabel(window, font, fieldLabels[i], { 20, (float)yOffset });
        UIRenderer::drawInputField(window, font, displayText, { 240, (float)yOffset - 5 }, i == activeField);
        yOffset += 50;
    }

    renderExtras(window);

    doneButton.draw(window, font);
    cancelButton.draw(window, font);
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
            if (sf::FloatRect(260, yOffset - 5, 250, 35).contains(mousePos)) {
                activeField = i;
                return;
            }
            yOffset += 50;
        }

        doneButton.handleClick(mousePos);
        cancelButton.handleClick(mousePos);

        handleMouseExtras(mousePos);
    }
}

void BookingForm::openConfirmationWindow() {
    if (ConfirmationWindow::show(getFormType(), fieldLabels, userInput)) {
        shouldClose = true;  // ✅ סגירה בטוחה כמו ב־CANCEL
    }
}

bool BookingForm::needsClose() const {
    return shouldClose;
}
