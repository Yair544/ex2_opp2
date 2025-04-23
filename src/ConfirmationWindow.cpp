#include "ConfirmationWindow.h"
#include "UIRenderer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

bool ConfirmationWindow::show(const std::string& title, const std::vector<std::string>& labels, const std::vector<std::string>& values) {
    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + title);
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    bool approved = false;

    while (confirmWindow.isOpen()) {
        sf::Event event;
        while (confirmWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                confirmWindow.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                if (sf::FloatRect(100, 300, 120, 40).contains(mousePos)) {
                    approved = true;
                    confirmWindow.close();
                }
                else if (sf::FloatRect(280, 300, 120, 40).contains(mousePos)) {
                    confirmWindow.close();
                }
            }
        }

        confirmWindow.clear(sf::Color(240, 240, 240));
        UIRenderer::drawLabel(confirmWindow, font, "Confirm " + title, { 130, 20 }, 22);

        float yOffset = 80;
        for (size_t i = 0; i < labels.size(); ++i) {
            std::string line = labels[i] + " " + values[i];
            UIRenderer::drawLabel(confirmWindow, font, line, { 50, yOffset }, 18);
            yOffset += 30;
        }

        UIRenderer::drawButton(confirmWindow, font, "APPROVE", { 100, 500 }, sf::Color(50, 150, 50));
        UIRenderer::drawButton(confirmWindow, font, "CANCEL", { 280, 500 }, sf::Color(180, 0, 0));

        confirmWindow.display();
    }

    return approved;
}
