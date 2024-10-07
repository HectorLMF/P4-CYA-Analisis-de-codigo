#include "code_analyzer.h"
#include <fstream>
#include <regex>
#include <iostream>

CodeAnalyzer::CodeAnalyzer(const std::string& inputFile, const std::string& outputFile)
    : inputFile(inputFile), outputFile(outputFile) {}

void CodeAnalyzer::analyze() {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Error opening input file\n";
        return;
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(inFile, line)) {
        analyzeLine(line, lineNumber);
        lineNumber++;
    }
}

void CodeAnalyzer::analyzeLine(const std::string& line, int lineNumber) {
    detectVariable(line, lineNumber);
    detectLoop(line, lineNumber);
    detectMainFunction(line);
    detectComment(line, lineNumber);
}

void CodeAnalyzer::detectVariable(const std::string& line, int lineNumber) {
    std::regex intRegex("^\\s*int\\s+(\\w+)\\s*(=.*)?;");
    std::regex doubleRegex("^\\s*double\\s+(\\w+)\\s*(=.*)?;");
    std::regex forLoopRegex("\\bfor\\s*\\(");
    std::regex whileLoopRegex("\\bwhile\\s*\\(");
    std::regex ifConditionRegex("\\bif\\s*\\(");
    std::smatch match;

    // Excluir variables dentro de bucles o condicionales
    if (std::regex_search(line, forLoopRegex) || 
        std::regex_search(line, whileLoopRegex) || 
        std::regex_search(line, ifConditionRegex)) {
        return;
    }

    // Detectar y contar variables de tipo int
    if (std::regex_search(line, match, intRegex)) {
        variables.emplace_back(match[1], "int", lineNumber, match[2].matched);
        ++intVarCount;  // Incrementar contador de variables int
    }
    // Detectar y contar variables de tipo double
    else if (std::regex_search(line, match, doubleRegex)) {
        variables.emplace_back(match[1], "double", lineNumber, match[2].matched);
        ++doubleVarCount;  // Incrementar contador de variables double
    }
}

void CodeAnalyzer::detectLoop(const std::string& line, int lineNumber) {
    std::regex forLoopRegex("\\bfor\\s*\\(");
    std::regex whileLoopRegex("\\bwhile\\s*\\(");
    std::smatch match;

    // Detectar bucles de tipo for
    if (std::regex_search(line, forLoopRegex)) {
        loops.emplace_back("for", lineNumber);
        ++forLoopCount;  // Incrementar contador de bucles for
    }
    // Detectar bucles de tipo while
    else if (std::regex_search(line, whileLoopRegex)) {
        loops.emplace_back("while", lineNumber);
        ++whileLoopCount;  // Incrementar contador de bucles while
    }
}


void CodeAnalyzer::detectMainFunction(const std::string& line) {
    if (line.find("int main") != std::string::npos) {
        hasMainFunction = true;
    }
}

void CodeAnalyzer::detectComment(const std::string& line, int lineNumber) {
    std::regex singleCommentRegex("//(.*)");
    std::regex multiCommentStartRegex("/\\*(.*)");
    std::regex multiCommentEndRegex("(.*)\\*/");
    static bool insideMultiComment = false;
    static std::string multiCommentContent;
    static int multiCommentStartLine;

    std::smatch match;

    if (insideMultiComment) {
        if (std::regex_search(line, match, multiCommentEndRegex)) {
            insideMultiComment = false;
            multiCommentContent += match[1];
            comments.emplace_back(multiCommentContent, multiCommentStartLine, lineNumber, true);
        } else {
            multiCommentContent += line + "\n";
        }
    } else if (std::regex_search(line, match, multiCommentStartRegex)) {
        insideMultiComment = true;
        multiCommentContent = match[1].str() + "\n";
        multiCommentStartLine = lineNumber;
    } else if (std::regex_search(line, match, singleCommentRegex)) {
        comments.emplace_back(match[1], lineNumber, lineNumber, false);
    }
}

void CodeAnalyzer::writeOutput() {
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Error opening output file\n";
        return;
    }

    // Write analyzed content to output file
    outFile << "Variables:\n";
    outFile << "Número de variables int: " << intVarCount << "\n";
    outFile << "Número de variables double: " << doubleVarCount << "\n";
    outFile << "-----------------------------\n";
    for (const auto& var : variables) {
        outFile << var.toString() << "\n";
    }
    
    outFile << "-----------------------------\n";
    outFile << "Bucles:\n";
    outFile << "Número de bucles for: " << forLoopCount << "\n";
    outFile << "Número de bucles while: " << whileLoopCount << "\n";
    outFile << "-----------------------------\n";
    for (Loop loop : loops) {
        outFile << loop.toString() << "\n";
    }
    
    outFile << "-----------------------------\n";
    outFile << "Comentarios:\n";
    for (const auto& comment : comments) {
        outFile << comment.toString() << "\n";
    }

    outFile << "\n¿Main presente?: " << (hasMainFunction ? "si" : "no") << "\n";
}
