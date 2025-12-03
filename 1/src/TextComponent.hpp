#pragma once
#include "BaseComponent.hpp"
#include <string>

class TextComponent : public BaseComponent {
public:
  TextComponent(const std::string &font_file, unsigned int char_size = 18);
  ~TextComponent() override = default;

  void setText(const std::string &t);
  void bindToVariable(const std::string &var_name);
  const sf::Font &getFont() const { return font_; }

  void update(float dt) override;
  void draw(sf::RenderTarget &target) override;

  void onVariableChanged(const std::string &name, const VarValue &value) override;

private:
  sf::Text text_;
  sf::Font font_;
  std::string bound_var_;
};
