#include "VariableDB.hpp"
#include <algorithm>

VariableDB &VariableDB::instance() {
  static VariableDB inst;
  return inst;
}

void VariableDB::set(const std::string &name, VarValue value) {
  std::vector<IVarObserver*> observers_copy;
  {
    std::lock_guard<std::mutex> lock(mutex_);
    vars_[name] = std::move(value);
    auto it = observers_.find(name);
    if (it != observers_.end()) observers_copy = it->second;
  }
  for (auto *obs : observers_copy) {
    if (obs) {
      VarValue v;
      {
        std::lock_guard<std::mutex> lock(mutex_);
        v = vars_[name];
      }
      obs->onVariableChanged(name, v);
    }
  }
}

bool VariableDB::exists(const std::string &name) const {
  std::lock_guard<std::mutex> lock(mutex_);
  return vars_.find(name) != vars_.end();
}

void VariableDB::subscribe(const std::string &name, IVarObserver *obs) {
  if (!obs) return;
  std::lock_guard<std::mutex> lock(mutex_);
  auto &vec = observers_[name];
  if (std::find(vec.begin(), vec.end(), obs) == vec.end()) vec.push_back(obs);
}

void VariableDB::unsubscribe(const std::string &name, IVarObserver *obs) {
  std::lock_guard<std::mutex> lock(mutex_);
  auto it = observers_.find(name);
  if (it == observers_.end()) return;
  auto &vec = it->second;
  vec.erase(std::remove(vec.begin(), vec.end(), obs), vec.end());
}
