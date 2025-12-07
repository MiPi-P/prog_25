#include "TextWidget.hpp"
#include <iostream>

TextWidget::TextWidget(const std::string& str, const sf::Vector2f& pos, unsigned int charSize) {
    if (!font.loadFromFile("../assets/fonts/arial.ttf"))
        std::cerr << "Error: could not load font!" << std::endl;

    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(charSize);
    text.setFillColor(sf::Color::White);
    text.setPosition(pos);
}
