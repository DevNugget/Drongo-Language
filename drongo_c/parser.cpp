#include "parser.hpp"
#include <iostream>
#include <sstream>
//#include <string>

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
            } else if (tokens[tok].value == "pushu8") {
                push_function(local_stack, bytecode_out, " 5 ");
            } else if (tokens[tok].value == "pushu16") {
                push_function(local_stack, bytecode_out, " 6 ");
            } else if (tokens[tok].value == "pushu32") {
                push_function(local_stack, bytecode_out, " 7 ");
            } else if (tokens[tok].value == "pushu64") {
                push_function(local_stack, bytecode_out, " 8 ");
            } 

            else if (tokens[tok].value == "ptr8") {
                bytecode_out = bytecode_out + " 18 ";
            } else if (tokens[tok].value == "ptr16") {
                bytecode_out = bytecode_out + " 19 ";
            } else if (tokens[tok].value == "ptr32") {
                bytecode_out = bytecode_out + " 20 ";
            } else if (tokens[tok].value == "ptr64") {
                bytecode_out = bytecode_out + " 21 ";
            } else if (tokens[tok].value == "ptru8") {
                bytecode_out = bytecode_out + " 22 ";
            } else if (tokens[tok].value == "ptru16") {
                bytecode_out = bytecode_out + " 23 ";
            } else if (tokens[tok].value == "ptru32") {
                bytecode_out = bytecode_out + " 24 ";
            } else if (tokens[tok].value == "ptru64") {
                bytecode_out = bytecode_out + " 25 ";
            }

            else if (tokens[tok].value == "@add") {
                bytecode_out = bytecode_out + " 26 ";
            } else if (tokens[tok].value == "->") {
                Token return_type_tok = tokens[tok + 1];
                if (return_type_tok.kind == Type) {
                    if (return_type_tok.value[0] == 'i') {
                        return_type_tok.value.erase(0, 1);
                        bytecode_out = bytecode_out + " 27 " + return_type_tok.value;
                    } else if (return_type_tok.value[0] == 'u') {
                        return_type_tok.value.erase(0, 1);
                        bytecode_out = bytecode_out + " 28 " + return_type_tok.value;
                    }
                }
                tok++;
            }

            else if (tokens[tok].value == "print") {
                Token print_type = tokens[tok + 1];
                if (print_type.kind == Type) {
                    if (print_type.value == "i8") {
                        bytecode_out = bytecode_out + " 10 "; 
                    } else if (print_type.value == "i16") {
                        bytecode_out = bytecode_out + " 11 "; 
                    } else if (print_type.value == "i32") {
                        bytecode_out = bytecode_out + " 12 "; 
                    } else if (print_type.value == "i64") {
                        bytecode_out = bytecode_out + " 13 "; 
                    } else if (print_type.value == "u8") {
                        bytecode_out = bytecode_out + " 14 "; 
                    } else if (print_type.value == "u16") {
                        bytecode_out = bytecode_out + " 15 "; 
                    } else if (print_type.value == "u32") {
                        bytecode_out = bytecode_out + " 16 "; 
                    } else if (print_type.value == "u64") {
                        bytecode_out = bytecode_out + " 17 "; 
                    }
                }
            }
        }
    }

    bytecode_out = remove_extra_spaces(bytecode_out);
    std::cout << "byte_code_p: " << bytecode_out << '\n';
    return bytecode_out;
}

std::string remove_extra_spaces(const std::string& input) {
    std::stringstream outputStringStream;
    std::istringstream iss(input);
    std::string word;
    while (iss >> word) {
        outputStringStream << word << " ";
    }
    return outputStringStream.str();
}