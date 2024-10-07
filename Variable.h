#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

class Variable {
public:
    Variable(const std::string& name, const std::string& type, int line, bool initialized);
    std::string toString() const;

private:
    std::string name;
    std::string type;
    int lineNumber;
    bool initialized;
};

#endif
