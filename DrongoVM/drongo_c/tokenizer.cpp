#include "tokenizer.hpp"

#include <sstream>
#include <algorithm>
#include <iostream>

std::vector<Token> tokenize(const std::string& input) {
    std::vector<Token> tokens;

    std::istringstream input_stream(input);
    std::string line;

    while (std::getline(input_stream, line)) {
        line = line + " ";
        std::vector<char> current_value;
        current_value.reserve(line.size());
        TokenKind current_type = Identifier;
        bool skip_next = false;

        for (char c : line) {
                if (c == ' ') {
                    if (!current_value.empty()) {
                        Token token = {current_type, std::string(current_value.data(), current_value.size())};
                        tokens.push_back(token);
                        current_value.clear();
                        current_type = Identifier;
                        skip_next = true;
                    }
                }
                else if (isdigit(c)) {
                    current_type = Number;
                    std::cout << "Number" << '\n';
                }
                else if (isalpha(c)) {
                    current_type = Identifier;
                    std::cout << "Iden" << '\n';
                }


                if (skip_next == false) {
                    current_value.push_back(c);
                } else { skip_next = false; }

                std::string str;
                for (auto x : current_value) {
                    str = str + x;
                }
                if (str == "push8" || str == "push16" || str == "push32" || str == "push64" || str == "ptr8" || str == "ptr16" || str == "ptr32" || str == "ptr64" || str == "@add") {
                    current_type = Keyword;
                    std::cout << "Key" << '\n';
                }
            
            }

        }

    return tokens;
}
