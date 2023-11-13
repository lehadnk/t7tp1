//
// Created by Алексей Заузин on 13.11.2023.
//

#include "ComparisonOperatorHandler.h"

Lexeme *ComparisonOperatorHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    if (node->operation->token == "<") {
        if (std::stoi(node->left->operation->token) < std::stoi(node->right->operation->token)) {
            return new Lexeme("1", tt_integer);
        }
    }
    if (node->operation->token == ">") {
        if (std::stoi(node->left->operation->token) > std::stoi(node->right->operation->token)) {
            return new Lexeme("1", tt_integer);
        }
    }
    if (node->operation->token == "==") {
        if (node->left->operation->token == node->right->operation->token) {
            return new Lexeme("1", tt_integer);
        }
    }

    return new Lexeme("0", tt_integer);
}
