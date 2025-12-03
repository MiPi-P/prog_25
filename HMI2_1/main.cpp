#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include "HMI2/Text.h"
#include "HMI2/Button.h"

int main() {
    // SFML 3: VideoMode теперь принимает Vector2u
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u{800, 600}), "HMI2 Test");

    sf::Font font;
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Не удалось загрузить шрифт!" << std::endl;
        return -1;
    }

    // Текст
    Text helloText(font, "Hello, HMI2!", 30);
    helloText.setPosition(200.f, 200.f);

    // Кнопка
    Button button(font, "Click Me", 20);
    button.setPosition(300.f, 300.f);
    button.setCallback([&helloText]() {
        helloText.setString("Button Clicked!");
    });

    while (window.isOpen()) {
        // SFML 3: pollEvent() возвращает std::optional<sf::Event>
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
            }

            // Обработка кнопки
            button.handleEvent(*event, window);
        }

        window.clear(sf::Color::Black);
        helloText.draw(window);
        button.draw(window);
        window.display();
    }

    return 0;
}
