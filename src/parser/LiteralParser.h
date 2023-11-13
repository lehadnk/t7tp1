//
// Created by Алексей Заузин on 04.11.2023.
//

#ifndef T7TP1_LITERALPARSER_H
#define T7TP1_LITERALPARSER_H

#include <string>
#include <utility>
#include "dto/Lexeme.h"

class LiteralParser {
    std::vector<Lexeme> lexems;
    std::string code;
public:
    explicit LiteralParser(std::string code)
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


#endif //T7TP1_LITERALPARSER_H
