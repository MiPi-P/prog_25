#include "ButtonComponent.hpp"
#include "VariableDB.hpp"

ButtonComponent::ButtonComponent(const std::string &label, const sf::Font &font, unsigned int char_size) {
  label_.setFont(font);
  label_.setString(label);
  label_.setCharacterSize(char_size);
  label_.setFillColor(sf::Color::Black);

  box_.setSize({150.f, 40.f});
  box_.setFillColor(sf::Color(200,200,200));
  box_.setOutlineColor(sf::Color::Black);
  box_.setOutlineThickness(2.f);
}

void ButtonComponent::update(float /*dt*/) {
  box_.setPosition(pos_);
  label_.setPosition(pos_.x + 10.f, pos_.y + 6.f);
}

void ButtonComponent::draw(sf::RenderTarget &target) {
  if (!visible_) return;
  target.draw(box_);
  target.draw(label_);
}

void ButtonComponent::onMouseEvent(const sf::Event &ev, const sf::RenderWindow &win) {
  if (ev.type == sf::Event::MouseMoved) {
    auto mp = sf::Mouse::getPosition(win);
    bool over = box_.getGlobalBounds().contains(static_cast<float>(mp.x), static_cast<float>(mp.y));
    if (over) box_.setFillColor(sf::Color(180,180,180));
    else box_.setFillColor(sf::Color(200,200,200));
  } else if (ev.type == sf::Event::MouseButtonPressed) {
    if (ev.mouseButton.button == sf::Mouse::Left) {
      auto mp = sf::Mouse::getPosition(win);
      if (box_.getGlobalBounds().contains(static_cast<float>(mp.x), static_cast<float>(mp.y))) {
        pressed_ = true;
        box_.setFillColor(sf::Color(150,150,150));
      }
    }
  } else if (ev.type == sf::Event::MouseButtonReleased) {
    if (ev.mouseButton.button == sf::Mouse::Left && pressed_) {
      auto mp = sf::Mouse::getPosition(win);
      if (box_.getGlobalBounds().contains(static_cast<float>(mp.x), static_cast<float>(mp.y))) {
        if (callback_) callback_();
      }
      pressed_ = false;
      box_.setFillColor(sf::Color(200,200,200));
    }
  }
}

void ButtonComponent::onVariableChanged(const std::string &name, const VarValue &value) {
  std::visit([this](auto &&v){
    using T = std::decay_t<decltype(v)>;
    if constexpr (std::is_same_v<T, bool>) {
      visible_ = v;
    } else if constexpr (std::is_same_v<T, std::string>) {
      label_.setString(v);
    }
  }, value);
}
