#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "tokenizer.hpp"
#include "parser.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " input_file\n";
        return 1;
    }

    std::ifstream input_file(argv[1]);
    if (!input_file) {
        std::cerr << "Error: unable to open input file\n";
        return 1;
    }

    std::stringstream input_stream;
    input_stream << input_file.rdbuf();
    input_file.close();

    std::string input = input_stream.str();

    std::vector<Token> tokens = tokenize(input);

    for (const auto& token : tokens) {
        std::cout << "Token kind: " << token.kind << ", value: " << token.value << '\n';
    }

    std::string bytecode = parse(tokens);

    std::ofstream out(argv[2]);
    out << bytecode;
    out.close();

    return 0;
}
