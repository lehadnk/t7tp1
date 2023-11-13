//
// Created by Алексей Заузин on 05.11.2023.
//

#ifndef T7TP1_LEXEME_H
#define T7TP1_LEXEME_H
#include <iostream>
#include "enum/TokenType.h"

struct Lexeme {
public:
    std::string token;
    TokenType tokenType = tt_unknown;

    Lexeme() = default;
    Lexeme(std::string token, TokenType tokenType) {
        this->token = std::move(token);
        this->tokenType = tokenType;
    }


};
#endif //T7TP1_LEXEME_H
