#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextWidget {
private:
    sf::Text text;
    sf::Font font;

public:
    TextWidget(const std::string& str, const sf::Vector2f& pos, unsigned int charSize = 20);

    void setText(const std::string& str) { text.setString(str); }
    void draw(sf::RenderWindow& window) { window.draw(text); }
};
