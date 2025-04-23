#include "ConfirmationWindow.h"
#include "UIButton.h"
#include "UIRenderer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

bool ConfirmationWindow::show(const std::string& title,
    const std::vector<std::string>& labels,
    const std::vector<std::string>& values) {
    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + title);
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    bool approved = false;
    bool requestClose = false;

    // יצירת כפתורים עם פעולות ריקות
    UIButton approveButton("APPROVE", { 100, 500 }, { 120, 40 },
        sf::Color(50, 150, 50), sf::Color::White);

    UIButton cancelButton("CANCEL", { 280, 500 }, { 120, 40 },
        sf::Color(180, 0, 0), sf::Color::White);

    // הצמדת הפעולות אחרי הבנייה — בטוח ולא יוצר גישה לזיכרון שגוי
    approveButton.setOnClick([&]() {
        approved = true;
        requestClose = true;
        });

    cancelButton.setOnClick([&]() {
        requestClose = true;
        });

    while (confirmWindow.isOpen()) {
        sf::Event event;
        while (confirmWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                confirmWindow.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                approveButton.handleClick(mousePos);
                cancelButton.handleClick(mousePos);
            }
        }

        if (requestClose) {
            confirmWindow.close();
            continue;
        }

        confirmWindow.clear(sf::Color(240, 240, 240));

        // ציור כותרת
        UIRenderer::drawLabel(confirmWindow, font, "Confirm " + title, { 130, 20 }, 22);

        // ציור פרטי ההזמנה
        float yOffset = 80;
        for (size_t i = 0; i < labels.size(); ++i) {
            std::string line = labels[i] + " " + values[i];
            UIRenderer::drawLabel(confirmWindow, font, line, { 50, yOffset }, 18);
            yOffset += 30;
        }

        // ציור כפתורים
        approveButton.draw(confirmWindow, font);
        cancelButton.draw(confirmWindow, font);

        confirmWindow.display();
    }

    return approved;
}
