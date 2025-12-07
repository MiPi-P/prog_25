#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class InputWidget {
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    std::string value;
    bool active;
    int maxLength;

public:
    InputWidget(const sf::Vector2f& pos, const sf::Vector2f& size, unsigned int charSize = 20, int maxLen = 20);

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    std::string getValue() const { return value; }
    void setValue(const std::string& v) { value = v; text.setString(value); }
};
