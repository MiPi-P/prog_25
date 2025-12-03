#include "InputFieldComponent.hpp"
#include "VariableDB.hpp"
#include <iostream>

InputFieldComponent::InputFieldComponent(const sf::Font &font, unsigned int char_size) : font_(font) {
  box_.setSize({300.f, 30.f});
  box_.setFillColor(sf::Color::White);
  box_.setOutlineThickness(2.f);
  box_.setOutlineColor(sf::Color::Black);

  text_.setFont(font_);
  text_.setCharacterSize(char_size);
  text_.setFillColor(sf::Color::Black);
}

void InputFieldComponent::bindToVariable(const std::string &var_name) {
  bound_var_ = var_name;
  VariableDB::instance().subscribe(var_name, this);
}

void InputFieldComponent::update(float /*dt*/) {
  box_.setPosition(pos_);
  text_.setPosition(pos_.x + 5.f, pos_.y + 4.f);
}

void InputFieldComponent::draw(sf::RenderTarget &target) {
  if (!visible_) return;
  target.draw(box_);
  if (text_.getString().isEmpty() && !focused_) {
    sf::Text ph(placeholder_, font_, text_.getCharacterSize());
    ph.setFillColor(sf::Color(150,150,150));
    ph.setPosition(text_.getPosition());
    target.draw(ph);
  } else {
    target.draw(text_);
  }
}

void InputFieldComponent::onEvent(const sf::Event &ev, const sf::RenderWindow &win) {
  if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left) {
    auto mp = sf::Mouse::getPosition(win);
    if (box_.getGlobalBounds().contains(static_cast<float>(mp.x), static_cast<float>(mp.y))) {
      focused_ = true;
      box_.setOutlineColor(sf::Color::Blue);
    } else {
      focused_ = false;
      box_.setOutlineColor(sf::Color::Black);
    }
  } else if (focused_) {
    if (ev.type == sf::Event::TextEntered) {
      uint32_t unicode = ev.text.unicode;
      if (unicode == 8) { // backspace
        auto s = text_.getString();
        if (!s.isEmpty()) {
          std::string str = s.toAnsiString();
          str.pop_back();
          text_.setString(str);
        }
      } else if (unicode < 128) {
        char c = static_cast<char>(unicode);
        if (c == '\r' || c == '\n') {
          if (!bound_var_.empty()) {
            VariableDB::instance().set(bound_var_, text_.getString().toAnsiString());
          }
        } else {
          auto s = text_.getString().toAnsiString();
          s.push_back(c);
          text_.setString(s);
        }
      }
    }
  }
}

void InputFieldComponent::onVariableChanged(const std::string &name, const VarValue &value) {
  if (name != bound_var_) return;
  std::visit([this](auto &&v){
    using T = std::decay_t<decltype(v)>;
    if constexpr (std::is_same_v<T, std::string>) {
      text_.setString(v);
    } else if constexpr (std::is_same_v<T, bool>) {
      text_.setString(v ? "true" : "false");
    } else {
      text_.setString(std::to_string(v));
    }
  }, value);
}
