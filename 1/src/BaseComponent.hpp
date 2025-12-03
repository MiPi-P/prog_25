#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "VariableDB.hpp"

class BaseComponent : public IVarObserver {
public:
  BaseComponent() = default;
  virtual ~BaseComponent() override = default;

  virtual void update(float dt) = 0;
  virtual void draw(sf::RenderTarget &target) = 0;

  void setPosition(float x, float y) { pos_.x = x; pos_.y = y; }
  void setSize(float w, float h) { size_.x = w; size_.y = h; }
  void setVisible(bool v) { visible_ = v; }

  virtual void onVariableChanged(const std::string &name, const VarValue &value) override {}

protected:
  sf::Vector2f pos_{0,0};
  sf::Vector2f size_{0,0};
  bool visible_ = true;
};
