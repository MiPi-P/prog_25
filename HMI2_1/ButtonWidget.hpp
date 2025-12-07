#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

class ButtonWidget {
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Font font;
    sf::Color normalColor;
    sf::Color hoverColor;
    std::function<void()> onClick;

public:
    ButtonWidget(const std::string& label, const sf::Vector2f& pos, const sf::Vector2f& size, unsigned int charSize = 20);

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void setOnClick(std::function<void()> func) { onClick = func; }

    // Новый метод для тестов
    void click() { if (onClick) onClick(); }
};
