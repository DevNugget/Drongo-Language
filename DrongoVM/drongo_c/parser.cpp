#include "parser.hpp"
#include <iostream>

void push_function(std::vector<int> &local_stack_p, std::string &bytecode, std::string instruction) {
    for (auto x : local_stack_p) {
        bytecode = bytecode + instruction + std::to_string(x);
    }
    local_stack_p.clear();
}

std::string parse(std::vector<Token> tokens) {
    std::string bytecode_out;
    std::vector<int> local_stack;

    for (int tok = 0; tok < tokens.size(); tok++) {
        if (tokens[tok].kind == Number) {
            local_stack.push_back(std::stoi(tokens[tok].value));
        } else if (tokens[tok].kind == Keyword) {
            if (tokens[tok].value == "push8") {
                push_function(local_stack, bytecode_out, " 1 ");
            } else if (tokens[tok].value == "push16") {
                push_function(local_stack, bytecode_out, " 2 ");
            } else if (tokens[tok].value == "push32") {
                push_function(local_stack, bytecode_out, " 3 ");
            } else if (tokens[tok].value == "push64") {
                push_function(local_stack, bytecode_out, " 4 ");
            } 

            else if (tokens[tok].value == "ptr8") {
                bytecode_out = bytecode_out + " 18 ";
            } else if (tokens[tok].value == "ptr16") {
                bytecode_out = bytecode_out + " 19 ";
            } else if (tokens[tok].value == "ptr32") {
                bytecode_out = bytecode_out + " 20 ";
            } else if (tokens[tok].value == "ptr64") {
                bytecode_out = bytecode_out + " 21 ";
            }
        }
    }

    std::cout << "byte_code_p: " << bytecode_out << '\n';
    return bytecode_out;
}