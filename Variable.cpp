#include "Variable.h"

Variable::Variable(const std::string& name, const std::string& type, int line, bool initialized)
    : name(name), type(type), lineNumber(line), initialized(initialized) {}

std::string Variable::toString() const {
    return "Type: " + type + ", Name: " + name + ", Line: " + std::to_string(lineNumber) +
           (initialized ? ", Initialized" : ", Not Initialized");
}
