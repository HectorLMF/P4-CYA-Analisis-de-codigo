#include "Loop.h"

Loop::Loop(const std::string& type, int line) : type(type), lineNumber(line) {}

std::string Loop::toString() const {
    return "Loop Type: " + type + ", Line: " + std::to_string(lineNumber);
}
