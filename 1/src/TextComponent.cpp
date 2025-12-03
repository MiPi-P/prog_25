#include "TextComponent.hpp"
#include "VariableDB.hpp"
#include <iostream>

TextComponent::TextComponent(const std::string &font_file, unsigned int char_size) {
  if (!font_.loadFromFile(font_file)) {
    std::cerr << "Warning: failed to load font: " << font_file << std::endl;
  }
  text_.setFont(font_);
  text_.setCharacterSize(char_size);
  text_.setFillColor(sf::Color::White);
}

void TextComponent::setText(const std::string &t) {
  text_.setString(t);
}

void TextComponent::bindToVariable(const std::string &var_name) {
  bound_var_ = var_name;
  VariableDB::instance().subscribe(var_name, this);
  if (VariableDB::instance().exists(var_name)) {
    auto sval = VariableDB::instance().get<std::string>(var_name, std::string());
    if (!sval.empty()) text_.setString(sval);
    else {
      int iv = VariableDB::instance().get<int>(var_name, INT_MIN);
      if (iv != INT_MIN) text_.setString(std::to_string(iv));
      else {
        double dv = VariableDB::instance().get<double>(var_name, -1e300);
        if (dv != -1e300) text_.setString(std::to_string(dv));
        else {
          bool bv = VariableDB::instance().get<bool>(var_name, false);
          text_.setString(bv ? "true" : "false");
        }
      }
    }
  }
}

void TextComponent::update(float /*dt*/) {
  text_.setPosition(pos_);
}

void TextComponent::draw(sf::RenderTarget &target) {
  if (!visible_) return;
  target.draw(text_);
}

void TextComponent::onVariableChanged(const std::string &name, const VarValue &value) {
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
