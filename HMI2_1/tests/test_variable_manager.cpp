#include <gtest/gtest.h>
#include "../VariableManager.hpp"

TEST(VariableManagerTest, SetAndGet) {
    VariableManager vm;
    vm.setVar("x", "42");
    EXPECT_EQ(vm.getVar("x"), "42");
}

TEST(VariableManagerTest, DefaultEmpty) {
    VariableManager vm;
    EXPECT_EQ(vm.getVar("unknown"), "");
}
