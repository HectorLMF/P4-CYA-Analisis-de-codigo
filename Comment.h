#ifndef COMMENT_H
#define COMMENT_H

#include <string>

class Comment {
public:
    Comment(const std::string& content, int startLine, int endLine, bool isMultiLine);
    std::string toString() const;

private:
    std::string content;
    int startLine;
    int endLine;
    bool isMultiLine;
};

#endif
