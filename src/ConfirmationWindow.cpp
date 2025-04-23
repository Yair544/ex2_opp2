#include "ConfirmationWindow.h"
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
                if (mousePos.x >= 100 && mousePos.x <= 220 && mousePos.y >= 300 && mousePos.y <= 345) {
                    approved = true;
                    confirmWindow.close();
                }
                else if (mousePos.x >= 280 && mousePos.x <= 400 && mousePos.y >= 300 && mousePos.y <= 345) {
                    confirmWindow.close();
                }
            }
        }

        confirmWindow.clear(sf::Color(240, 240, 240));

        sf::Text titleText("Confirm " + title, font, 22);
        titleText.setFillColor(sf::Color::Black);
        titleText.setPosition(130, 20);
        confirmWindow.draw(titleText);

        std::string bookingInfo;
        for (size_t i = 0; i < labels.size(); ++i) {
            bookingInfo += labels[i] + " " + values[i] + "\n";
        }

        sf::Text details(bookingInfo, font, 18);
        details.setFillColor(sf::Color::Black);
        details.setPosition(50, 80);
        confirmWindow.draw(details);

        sf::RectangleShape approveButton(sf::Vector2f(120, 40));
        approveButton.setPosition(100, 300);
        approveButton.setFillColor(sf::Color(50, 150, 50));
        confirmWindow.draw(approveButton);

        sf::Text approveText("APPROVE", font, 18);
        approveText.setFillColor(sf::Color::White);
        approveText.setPosition(118, 310);
        confirmWindow.draw(approveText);

        sf::RectangleShape cancelButton(sf::Vector2f(120, 40));
        cancelButton.setPosition(280, 300);
        cancelButton.setFillColor(sf::Color(180, 0, 0));
        confirmWindow.draw(cancelButton);

        sf::Text cancelText("CANCEL", font, 18);
        cancelText.setFillColor(sf::Color::White);
        cancelText.setPosition(305, 310);
        confirmWindow.draw(cancelText);

        confirmWindow.display();
    }

    return approved;
}
