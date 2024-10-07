#ifndef LOOP_H
#define LOOP_H

#include <string>

class Loop {
public:
    Loop(const std::string& type, int line);
    std::string toString() const;

private:
    std::string type;
    int lineNumber;
};

#endif
