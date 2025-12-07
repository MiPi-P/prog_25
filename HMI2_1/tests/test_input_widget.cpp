#include <gtest/gtest.h>
#include "../InputWidget.hpp"

// Проверяем начальные значения
TEST(InputWidgetTest, InitialState) {
    InputWidget input({0, 0}, {100, 30});
    EXPECT_EQ(input.getValue(), "");
}

// Проверяем установку значения
TEST(InputWidgetTest, SetValue) {
    InputWidget input({0, 0}, {100, 30});
    input.setValue("Hello");
    EXPECT_EQ(input.getValue(), "Hello");
}
