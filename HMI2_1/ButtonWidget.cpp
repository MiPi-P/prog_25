#include "ButtonWidget.hpp"
#include <iostream>

ButtonWidget::ButtonWidget(const std::string& label, const sf::Vector2f& pos, const sf::Vector2f& size, unsigned int charSize) {
    box.setSize(size);
    box.setPosition(pos);
    normalColor = sf::Color(50, 50, 200);
    hoverColor = sf::Color(100, 100, 250);
    box.setFillColor(normalColor);

    if (!font.loadFromFile("../assets/fonts/arial.ttf"))
        std::cerr << "Error: could not load font!" << std::endl;

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(charSize);
    text.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.f,
                   textBounds.top + textBounds.height / 2.f);
    text.setPosition(pos.x + size.x / 2.f, pos.y + size.y / 2.f);
}

void ButtonWidget::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    sf::Vector2f mousePos(static_cast<float>(sf::Mouse::getPosition(window).x),
                          static_cast<float>(sf::Mouse::getPosition(window).y));

    if (box.getGlobalBounds().contains(mousePos))
        box.setFillColor(hoverColor);
    else
        box.setFillColor(normalColor);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (box.getGlobalBounds().contains(mousePos) && onClick)
            onClick();
    }
}

void ButtonWidget::draw(sf::RenderWindow& window) {
    window.draw(box);
    window.draw(text);
}
