#pragma once
#include <SFML/Graphics.hpp>

class Widget {
public:
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update() {}   // для будущего обновления по переменной
    virtual ~Widget() = default;
};