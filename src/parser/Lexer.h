//
// Created by Алексей Заузин on 04.11.2023.
//

#ifndef T7TP1_LEXER_H
#define T7TP1_LEXER_H

#include <string>
#include <utility>
#include "dto/Lexeme.h"

class Lexer {
    std::vector<Lexeme> lexemes;
    std::string code;
public:
    explicit Lexer(std::string code)
    {
        this->code = std::move(code);
    }

    int index = 0;

    std::vector<Lexeme> parse();

private:
    TokenType getTokenType(std::string &token);
    void next();
    bool isEndOfFile();
};


#endif //T7TP1_LEXER_H
