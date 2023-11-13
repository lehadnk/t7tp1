//
// Created by Алексей Заузин on 04.11.2023.
//
#include <regex>
#include "LiteralParser.h"
#include "dto/Lexeme.h"

void LiteralParser::next()
{
    auto lexeme = Lexeme();

    for(; this->index < code.size(); this->index++) {
        if (lexeme.token.empty() && lexeme.tokenType != tt_string && (code[this->index] == ' ' || code[this->index] == '\n')) {
            continue;
        }
        if (lexeme.token.empty() && lexeme.tokenType == tt_unknown && code[this->index] == '"') {
            lexeme.tokenType = tt_string;
            continue;
        }
        if (!lexeme.token.empty() && lexeme.tokenType != tt_string && (code[this->index] == ' ' || code[this->index] == '\n' || code[this->index] == ';' || code[this->index] == '(' || code[this->index] == ')')) {
            break;
        }
        if (lexeme.tokenType == tt_string && code[this->index] == '"') {
            this->index++;
            break;
        }

        lexeme.token += code[this->index];
        if (lexeme.token == "(" || lexeme.token == ")" || lexeme.token == "{" || lexeme.token == "}") {
            this->index++;
            break;
        }
    }

    if (lexeme.token.empty()) {
        // Usually occurs at the end of file due to trailing whitespaces etc
        return;
    }

    if (lexeme.tokenType == tt_unknown) {
        lexeme.tokenType = this->getTokenType(lexeme.token);
    }

    this->lexems.emplace_back(lexeme);
}

TokenType LiteralParser::getTokenType(std::string &token) {
    if (token == "(") {
        return tt_parentheses_open;
    }

    if (token == ")") {
        return tt_parentheses_close;
    }

    if (token == "{") {
        return tt_start_of_block;
    }

    if (token == "}") {
        return tt_end_of_block;
    }

    if (token == "if") {
        return tt_if;
    }

    if (token == "for") {
        return tt_for;
    }

    if (token == "str" || token == "int") {
        return tt_variable_declaration;
    }

    if (token == "print") {
        return tt_print;
    }

    if (token == "input") {
        return tt_input;
    }

    std::regex integer_regex("[0-9]*");
    if (std::regex_match(token, integer_regex)) {
        return tt_integer;
    }

    std::regex comparison_operator_regex("==|<|>");
    if (std::regex_match(token, comparison_operator_regex)) {
        return tt_comparison_operator;
    }

    std::regex identifier_regex("[aA-zZ0-9]*");
    if (std::regex_match(token, identifier_regex)) {
        return tt_identifier;
    }

    std::regex arithmetic_operator_regex("[+/-/*]");
    if (std::regex_match(token, arithmetic_operator_regex)) {
        return tt_arithmetic_operator;
    }

    if (token == ";") {
        return tt_semicolon;
    }

    if (token == "=") {
        return tt_assignment;
    }

    if (token == "{") {
        return tt_start_of_block;
    }

    if (token == "}") {
        return tt_end_of_block;
    }

    return tt_unknown;
}

std::vector<Lexeme> LiteralParser::parse() {
    this->index = 0;
    this->lexems = std::vector<Lexeme>();
    while(!this->isEndOfFile()) {
        this->next();
    }

    return this->lexems;
}

bool LiteralParser::isEndOfFile() {
    return this->index == this->code.size();
}