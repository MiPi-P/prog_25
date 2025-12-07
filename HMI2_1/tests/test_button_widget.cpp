#include <gtest/gtest.h>
#include "../ButtonWidget.hpp"

TEST(ButtonWidgetTest, OnClickWorks) {
    bool clicked = false;
    ButtonWidget button("Test", {0,0}, {100,30});

    button.setOnClick([&]() { clicked = true; });

    // Симулируем клик через новый метод click()
    button.click();

    EXPECT_TRUE(clicked);
}
