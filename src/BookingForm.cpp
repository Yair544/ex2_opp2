// BookingForm.cpp
#include "BookingForm.h"
#include "DialogueManager.h"
#include <iostream>

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* mng)
    : window(win), manager(mng) {
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");
}

//void BookingForm::addField(const std::string& label, sf::Vector2f pos, std::unique_ptr<Validator<T>> validator) {
//    // כאן תיווסף שדה חדש עם הוולידטור המתאים
//    fields.emplace_back(std::make_unique<FormField<T>>(label, pos, std::move(validator)));
//}

void BookingForm::finalizeFields() {
    if (!fields.empty()) {
        for (auto& f : fields) f->setActive(false); // לוודא שאין שדה אחר פעיל
        activeIndex = 0;
        fields[0]->setActive(true);
    }
}

void BookingForm::render(sf::RenderWindow& win) {
    win.clear(sf::Color(240, 240, 240));
    bool cursorOn = cursorTimer.getElapsedTime().asMilliseconds() % 1000 < 500;
    for (const auto& f : fields) {
        f->draw(win, font, cursorOn);
    }
    win.display();
}

void BookingForm::handleInput(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f clickPos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

        for (std::size_t i = 0; i < fields.size(); ++i) {
            if (fields[i]->containsPoint(clickPos)) {
                fields[activeIndex]->setActive(false);
                activeIndex = i;
                fields[activeIndex]->setActive(true);
                break;
            }
        }
        return; // ❗ חשוב: לא להמשיך לשאר הקלט אם זו לחיצת עכבר בלבד
    }

    // הקלדה או הכנסת טקסט
    if (event.type == sf::Event::TextEntered || event.type == sf::Event::KeyPressed) {
        if (activeIndex < fields.size()) {
            fields[activeIndex]->handleInput(event);
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
            validateAllFields();
            openConfirmationWindow();
        }
    }
}

void BookingForm::validateAllFields() {
    for (auto& f : fields) {
        f->validate();
    }
}

bool BookingForm::allValid() const {
    for (const auto& f : fields) {
        if (!f->isFieldValid())
            return false;
    }
    return true;
}

std::vector<std::string> BookingForm::getErrors() const {
    std::vector<std::string> result;
    for (const auto& f : fields) {
        if (!f->isFieldValid())
            result.push_back(f->getLabel());
    }
    return result;
}

void BookingForm::openConfirmationWindow() {
    sf::RenderWindow confirm(sf::VideoMode(500, 300), "Confirmation");

    while (confirm.isOpen()) {
        sf::Event e;
        while (confirm.pollEvent(e)) {
            if (e.type == sf::Event::Closed) confirm.close();

            if (e.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mouse(e.mouseButton.x, e.mouseButton.y);
                if (mouse.y >= 250 && mouse.y <= 290) {
                    if (mouse.x >= 30 && mouse.x <= 170) {
                        if (allValid()) manager->closeForm();
                        confirm.close();
                    }
                    else if (mouse.x >= 200 && mouse.x <= 340) {
                        confirm.close();
                    }
                }
            }
        }

        confirm.clear(sf::Color::White);

        sf::Text title(allValid() ? "All data valid!" : "Error: Invalid Fields", font, 20);
        title.setFillColor(allValid() ? sf::Color::Green : sf::Color::Red);
        title.setPosition(20, 20);
        confirm.draw(title);

        if (!allValid()) {
            auto errors = getErrors();
            int y = 60;
            for (const auto& err : errors) {
                sf::Text errText("Invalid: " + err, font, 18);
                errText.setFillColor(sf::Color::Black);
                errText.setPosition(40, y);
                confirm.draw(errText);
                y += 30;
            }
        }

        sf::RectangleShape approve(sf::Vector2f(140, 40));
        approve.setPosition(30, 250);
        approve.setFillColor(sf::Color(50, 150, 50));
        confirm.draw(approve);

        sf::Text approveText("APPROVE", font, 18);
        approveText.setPosition(50, 258);
        approveText.setFillColor(sf::Color::White);
        confirm.draw(approveText);

        sf::RectangleShape cancel(sf::Vector2f(140, 40));
        cancel.setPosition(200, 250);
        cancel.setFillColor(sf::Color(180, 0, 0));
        confirm.draw(cancel);

        sf::Text cancelText("CANCEL", font, 18);
        cancelText.setPosition(230, 258);
        cancelText.setFillColor(sf::Color::White);
        confirm.draw(cancelText);

        confirm.display();
    }
}
