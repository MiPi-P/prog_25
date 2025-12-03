#pragma once
#include "Widget.h"
#include <string>

class Text : public Widget {
    sf::Text text_;
public:
    Text(const sf::Font& font, const std::string& str, unsigned int size) {
        text_.setFont(font);
        text_.setString(str);
        text_.setCharacterSize(size);
        text_.setFillColor(sf::Color::White);
    }

    void setString(const std::string& str) { text_.setString(str); }
    void setPosition(float x, float y) { text_.setPosition(x, y); }

    void draw(sf::RenderWindow& window) override {
        window.draw(text_);
    }
};
