#include <gtest/gtest.h>
#include "../src/VariableDB.hpp"

TEST(VariableDB, SetGetInt) {
  auto &db = VariableDB::instance();
  db.set("a", 42);
  EXPECT_EQ(db.get<int>("a", 0), 42);
}

TEST(VariableDB, SubscribeNotify) {
  auto &db = VariableDB::instance();
  struct Obs : public IVarObserver {
    void onVariableChanged(const std::string &name, const VarValue &value) override {
      called = true;
    }
    bool called = false;
  } obs;
  db.subscribe("x", &obs);
  db.set("x", 7);
  EXPECT_TRUE(obs.called);
  db.unsubscribe("x", &obs);
}
