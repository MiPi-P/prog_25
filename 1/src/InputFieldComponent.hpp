#pragma once
#include "BaseComponent.hpp"
#include <string>

class InputFieldComponent : public BaseComponent {
public:
  InputFieldComponent(const sf::Font &font, unsigned int char_size = 18);
  ~InputFieldComponent() override = default;

  void setPlaceholder(const std::string &p) { placeholder_ = p; }
  void bindToVariable(const std::string &var_name);

  void update(float dt) override;
  void draw(sf::RenderTarget &target) override;

  void onEvent(const sf::Event &ev, const sf::RenderWindow &win);
  void onVariableChanged(const std::string &name, const VarValue &value) override;

private:
  sf::RectangleShape box_;
  sf::Text text_;
  sf::Font font_;
  std::string placeholder_;
  bool focused_ = false;
  std::string bound_var_;
};
