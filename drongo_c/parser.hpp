#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include "tokenizer.hpp"

std::string parse(std::vector<Token> tokens);
std::string remove_extra_spaces(const std::string& input);

#endif