#include "ConfirmationWindow.h"
#include "UIButton.h"
#include "UIRenderer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

bool ConfirmationWindow::show(const std::string& title,
    const std::vector<std::string>& labels,
    const std::vector<std::string>& values,
    const std::vector<bool>& validities) {

    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + title);
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    bool approved = false;
    bool requestClose = false;

    UIButton approveButton("APPROVE", { 100, 500 }, { 120, 40 },
        sf::Color(50, 150, 50), sf::Color::White);

    UIButton cancelButton("CANCEL", { 280, 500 }, { 120, 40 },
        sf::Color(180, 0, 0), sf::Color::White);

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
            if (event.type == sf::Event::Closed)
                confirmWindow.close();

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
        UIRenderer::drawLabel(confirmWindow, font, "Confirm " + title, { 130, 20 }, 22);

        float yOffset = 80;
        for (size_t i = 0; i < labels.size(); ++i) {
            std::string line = labels[i] + ": " + values[i];
            sf::Color color = validities[i] ? sf::Color::Black : sf::Color::Red;

            if (!validities[i]) {
                line += " ❌ Invalid";
            }

            UIRenderer::drawLabel(confirmWindow, font, line, { 50, yOffset }, 18, color);
            yOffset += 30;
        }

        approveButton.draw(confirmWindow, font);
        cancelButton.draw(confirmWindow, font);

        confirmWindow.display();
    }

    return approved;
}
