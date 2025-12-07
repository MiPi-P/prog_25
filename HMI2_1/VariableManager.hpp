#pragma once
#include <string>
#include <unordered_map>

class VariableManager {
private:
    std::unordered_map<std::string, std::string> vars;

public:
    void setVar(const std::string& name, const std::string& value) {
        vars[name] = value;
    }

    std::string getVar(const std::string& name) {
        return vars[name];
    }
};
