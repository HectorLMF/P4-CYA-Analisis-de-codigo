#include "code_analyzer.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    CodeAnalyzer analyzer(argv[1], argv[2]);
    analyzer.analyze();
    analyzer.writeOutput();

    return 0;
}
