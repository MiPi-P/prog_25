#pragma once
#include "Widget.h"
#include <functional>

class Button : public Widget {
    sf::RectangleShape rect_;
    sf::Text text_;
    std::function<void()> callback_;
public:
    Button(const sf::Font& font, const std::string& str, unsigned int size) {
        text_.setFont(font);
        text_.setString(str);
        text_.setCharacterSize(size);
        text_.setFillColor(sf::Color::White);
        rect_.setSize({150.f, 50.f});
        rect_.setFillColor(sf::Color::Blue);
    }

    void setPosition(float x, float y) {
        rect_.setPosition(x, y);
        text_.setPosition(x + 10, y + 10);
    }

    void setCallback(std::function<void()> cb) { callback_ = cb; }

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed) {
            auto mousePos = sf::Mouse::getPosition(window);
            if (rect_.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                if (callback_) callback_();
            }
        }
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(rect_);
        window.draw(text_);
    }
};
