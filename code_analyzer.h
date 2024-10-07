#ifndef CODE_ANALYZER_H
#define CODE_ANALYZER_H

#include <string>
#include <vector>
#include "Variable.h"
#include "Loop.h"
#include "Comment.h"

class CodeAnalyzer {
public:
    CodeAnalyzer(const std::string& inputFile, const std::string& outputFile);
    void analyze();
    void writeOutput();
    
private:

    int intVarCount = 0;
    int doubleVarCount = 0;

    int forLoopCount = 0;
    int whileLoopCount = 0;


    std::string inputFile;
    std::string outputFile;
    std::vector<Variable> variables;
    std::vector<Loop> loops;
    std::vector<Comment> comments;
    bool hasMainFunction = false;

    void analyzeLine(const std::string& line, int lineNumber);
    void detectVariable(const std::string& line, int lineNumber);
    void detectLoop(const std::string& line, int lineNumber);
    void detectMainFunction(const std::string& line);
    void detectComment(const std::string& line, int lineNumber);
};

#endif
