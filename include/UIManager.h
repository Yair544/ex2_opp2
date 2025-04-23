#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "DialogueManager.h"
#include "UIButton.h"

class UIManager {
private:
    sf::RenderWindow& window;
    DialogueManager& formManager;
    sf::Font font;

    std::vector<UIButton> buttons;

public:
    UIManager(sf::RenderWindow& win, DialogueManager& dManager);
    void render();
    void handleEvent(const sf::Event& event);
};
