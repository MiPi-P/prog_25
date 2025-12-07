#include <SFML/Graphics.hpp>
#include "TextWidget.hpp"
#include "InputWidget.hpp"
#include "ButtonWidget.hpp"
#include "VariableManager.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "HMI2 SCADA Test");

    VariableManager vm;
    vm.setVar("input1", "");
    vm.setVar("input2", "");

    // Первая группа
    TextWidget label1("Input 1:", {50.f, 50.f}, 24);
    InputWidget input1({50.f, 100.f}, {200.f, 40.f}, 24, 20);
    TextWidget output1("Value 1: ", {50.f, 160.f}, 24);
    ButtonWidget button1("Update 1", {270.f, 100.f}, {120.f, 40.f}, 20);
    button1.setOnClick([&]() {
        vm.setVar("input1", input1.getValue());
        output1.setText("Value 1: " + vm.getVar("input1"));
    });

    // Вторая группа
    TextWidget label2("Input 2:", {50.f, 220.f}, 24);
    InputWidget input2({50.f, 270.f}, {200.f, 40.f}, 24, 20);
    TextWidget output2("Value 2: ", {50.f, 330.f}, 24);
    ButtonWidget button2("Update 2", {270.f, 270.f}, {120.f, 40.f}, 20);
    button2.setOnClick([&]() {
        vm.setVar("input2", input2.getValue());
        output2.setText("Value 2: " + vm.getVar("input2"));
    });

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            input1.handleEvent(event, window);
            button1.handleEvent(event, window);

            input2.handleEvent(event, window);
            button2.handleEvent(event, window);
        }

        window.clear(sf::Color::Black);

        // Рисуем первую группу
        label1.draw(window);
        input1.draw(window);
        button1.draw(window);
        output1.draw(window);

        // Рисуем вторую группу
        label2.draw(window);
        input2.draw(window);
        button2.draw(window);
        output2.draw(window);

        window.display();
    }

    return 0;
}
