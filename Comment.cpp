#include "Comment.h"

Comment::Comment(const std::string& content, int startLine, int endLine, bool isMultiLine)
    : content(content), startLine(startLine), endLine(endLine), isMultiLine(isMultiLine) {}

std::string Comment::toString() const {
    return (isMultiLine ? "Multiline" : "Single-line") + std::string(" comment from line ") +
           std::to_string(startLine) + " to " + std::to_string(endLine) + ": " + content;
}
