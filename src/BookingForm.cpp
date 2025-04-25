#include "BookingForm.h"
#include "ConfirmationWindow.h"
#include "UIRenderer.h"
#include <iostream>

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager)
    : window(win), formManager(manager), shouldClose(false),
    doneButton("DONE", { 20, 570 }, { 140, 40 }, sf::Color(50, 150, 50), sf::Color::White, [&]() {

    for (auto& field : fields) field->validate();
    bool allValid = std::all_of(fields.begin(), fields.end(),
        [](const std::unique_ptr<FormFieldBase>& f) { return f->isFieldValid(); });
    if (allValid) {
        std::cout << getFormType() << " Confirmed!\n";
    }
    openConfirmationWindow();

        }),
    cancelButton("CANCEL", { 200, 570 }, { 140, 40 }, sf::Color(180, 0, 0), sf::Color::White, [&]() {
    std::cout << "Cancelled " << getFormType() << "\n";
    shouldClose = true;
        }) {
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
}

void BookingForm::render(sf::RenderWindow& window) {
    window.clear(sf::Color(235, 235, 235));
    UIRenderer::drawLabel(window, font, getFormType(), { 20, 10 }, 26);

    bool cursorVisible = (cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500);

    for (std::size_t i = 0; i < fields.size(); ++i) {
        fields[i]->draw(window, font, i == activeField && cursorVisible);
    }

    renderExtras(window);
    doneButton.draw(window, font);
    cancelButton.draw(window, font);
}

void BookingForm::handleInput(sf::Event event) {
    if (event.type == sf::Event::TextEntered || event.type == sf::Event::KeyPressed) {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab) {
            fields[activeField]->setActive(false);  // כיבוי שדה נוכחי
            activeField = (activeField + 1) % fields.size();
            fields[activeField]->setActive(true);   // הפעלה של הבא
        }
        else {
            fields[activeField]->handleInput(event);
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

        for (std::size_t i = 0; i < fields.size(); ++i) {
            if (fields[i]->containsPoint(mousePos)) {
                // כיבוי של כל השדות
                for (auto& f : fields)
                    f->setActive(false);

                // הפעלת השדה שנבחר
                activeField = i;
                fields[i]->setActive(true);
                return;
            }
        }

        doneButton.handleClick(mousePos);
        cancelButton.handleClick(mousePos);
        handleMouseExtras(mousePos);
    }
}


void BookingForm::openConfirmationWindow() {
    std::vector<std::string> labels;
    std::vector<std::string> values;
    std::vector<bool> validities;
    std::vector<std::string> errorMessages;

    for (const auto& field : fields) {
        labels.push_back(field->getLabel());
        values.push_back(field->getValue());
        bool isValid = field->isFieldValid();
        validities.push_back(isValid);

        if (!isValid) {
            errorMessages.push_back(field->getLabel() + ": " + field->getErrorMessage());
        }
    }

    if (ConfirmationWindow::show(getFormType(), labels, values, validities, errorMessages)) {
        shouldClose = true;
    }
}

bool BookingForm::needsClose() const {
    return shouldClose;
}

