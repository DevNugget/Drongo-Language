#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>

enum TokenKind {
    Identifier,
    Number,
    Keyword,
    Type,
};

struct Token {
    TokenKind kind;
    std::string value;
};

std::vector<Token> tokenize(const std::string& input);

#endif // TOKENIZER_HPP
