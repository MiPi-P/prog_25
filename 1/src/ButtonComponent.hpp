#pragma once
#include "BaseComponent.hpp"
#include <functional>

class ButtonComponent : public BaseComponent {
public:
  ButtonComponent(const std::string &label, const sf::Font &font, unsigned int char_size = 18);
  ~ButtonComponent() override = default;

  void setCallback(std::function<void()> cb) { callback_ = std::move(cb); }

  void update(float dt) override;
  void draw(sf::RenderTarget &target) override;

  void onMouseEvent(const sf::Event &ev, const sf::RenderWindow &win);

  void onVariableChanged(const std::string &name, const VarValue &value) override;

private:
  sf::RectangleShape box_;
  sf::Text label_;
  std::function<void()> callback_;
  bool pressed_ = false;
};
