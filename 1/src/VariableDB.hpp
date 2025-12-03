#pragma once
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>
#include <mutex>

using VarValue = std::variant<int, double, std::string, bool>;

class IVarObserver {
public:
  virtual ~IVarObserver() = default;
  virtual void onVariableChanged(const std::string &name, const VarValue &value) = 0;
};

class VariableDB {
public:
  static VariableDB &instance();

  void set(const std::string &name, VarValue value);
  bool exists(const std::string &name) const;

  template<typename T>
  T get(const std::string &name, T default_value = T()) const {
    std::lock_guard<std::mutex> lock(mutex_);
    auto it = vars_.find(name);
    if (it == vars_.end()) return default_value;
    if (auto p = std::get_if<T>(&it->second)) return *p;
    return default_value;
  }

  void subscribe(const std::string &name, IVarObserver *obs);
  void unsubscribe(const std::string &name, IVarObserver *obs);

private:
  VariableDB() = default;
  mutable std::mutex mutex_;
  std::unordered_map<std::string, VarValue> vars_;
  std::unordered_map<std::string, std::vector<IVarObserver*>> observers_;
};
