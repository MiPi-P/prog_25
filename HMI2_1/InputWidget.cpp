#include "InputWidget.hpp"
#include <iostream>

InputWidget::InputWidget(const sf::Vector2f& pos, const sf::Vector2f& size, unsigned int charSize, int maxLen)
    : maxLength(maxLen), active(false) {
    box.setSize(size);
    box.setPosition(pos);
    box.setFillColor(sf::Color::Black);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(2.f);

    if (!font.loadFromFile("../assets/fonts/arial.ttf"))
        std::cerr << "Error: could not load font!" << std::endl;

    text.setFont(font);
    text.setCharacterSize(charSize);
    text.setFillColor(sf::Color::White);
    text.setPosition(pos.x + 5.f, pos.y + 5.f);

    value = "";
}

void InputWidget::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(window).x),
                              static_cast<float>(sf::Mouse::getPosition(window).y));
        active = box.getGlobalBounds().contains(mousePos);
        box.setOutlineColor(active ? sf::Color::Green : sf::Color::White);
    }

    if (!active) return;

    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode >= 32 && event.text.unicode <= 126) {
            if (value.size() < maxLength)
                value += static_cast<char>(event.text.unicode);
            text.setString(value);
        } else if (event.text.unicode == 8 && !value.empty()) { // Backspace
            value.pop_back();
            text.setString(value);
        }
    }
}

void InputWidget::draw(sf::RenderWindow& window) {
    window.draw(box);
    window.draw(text);
}
