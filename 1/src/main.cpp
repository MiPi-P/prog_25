#include <SFML/Graphics.hpp>
#include "TextComponent.hpp"
#include "ButtonComponent.hpp"
#include "InputFieldComponent.hpp"
#include "VariableDB.hpp"
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "HMI2 Demo");
  window.setFramerateLimit(60);

  const std::string font_path = "assets/Roboto-Regular.ttf"; // replace if needed

  TextComponent label(font_path, 20);
  label.setPosition(20, 20);
  label.bindToVariable("temperature");

  ButtonComponent btn("Inc", label.getFont(), 18);
  btn.setPosition(20, 60);
  btn.setCallback([](){
    auto &db = VariableDB::instance();
    int cur = db.get<int>("temperature", 0);
    db.set("temperature", cur + 1);
  });

  InputFieldComponent input(label.getFont(), 18);
  input.setPosition(20, 120);
  input.bindToVariable("setpoint");
  input.setPlaceholder("Enter setpoint and press Enter...");

  VariableDB::instance().set("temperature", 25);
  VariableDB::instance().set("setpoint", std::string("100"));

  while (window.isOpen()) {
    sf::Event ev;
    while (window.pollEvent(ev)) {
      if (ev.type == sf::Event::Closed) window.close();

      btn.onMouseEvent(ev, window);
      input.onEvent(ev, window);
    }

    float dt = 1.0f/60.0f;
    label.update(dt);
    btn.update(dt);
    input.update(dt);

    window.clear(sf::Color(50,50,50));
    label.draw(window);
    btn.draw(window);
    input.draw(window);
    window.display();
  }

  return 0;
}
