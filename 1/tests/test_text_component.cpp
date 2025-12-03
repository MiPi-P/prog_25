#include <gtest/gtest.h>
#include "../src/TextComponent.hpp"

TEST(Smoke, CreateTextComponent) {
  // We don't test SFML drawing here; just construction.
  TextComponent t("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
  t.setText("Hello");
  EXPECT_TRUE(true);
}
