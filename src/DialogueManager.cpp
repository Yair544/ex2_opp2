#include "DialogueManager.h"
#include <iostream>

DialogueManager::DialogueManager() : activeForm(nullptr), isFormOpen(false) {}

void DialogueManager::setActiveForm(std::unique_ptr<BookingForm> form) {
    if (isFormOpen) return;  // Prevent multiple openings
    isFormOpen = true;

    activeForm = std::move(form);
    std::cout << "Opening " << activeForm->getFormType() << " form...\n";

    if (!formWindow.isOpen()) {

        formWindow.create(sf::VideoMode(850, 900), activeForm->getFormType());
    }
}

void DialogueManager::closeForm() {
    if (formWindow.isOpen()) {
        formWindow.close();
    }

    if (activeForm) {
        activeForm.reset();
        activeForm = nullptr;
    }

    isFormOpen = false;   // ✅ Allow opening a new form later
    std::cout << "Returned to Main Menu.\n";
}


void DialogueManager::handleFormEvents() {
    if (!isFormOpen || !formWindow.isOpen() || !activeForm) {
        return; // אין טופס פתוח
    }

    sf::Event event;
    while (formWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            closeForm();
            return;
        }

        if (activeForm) {
            activeForm->handleInput(event);
        }
    }

    if (activeForm && activeForm->needsClose()) {
        closeForm();
        return;
    }

    if (activeForm) {
        formWindow.clear(sf::Color::White);
        activeForm->render(formWindow);
        formWindow.display();
    }
}


