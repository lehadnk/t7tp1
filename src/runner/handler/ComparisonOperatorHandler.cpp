//
// Created by Алексей Заузин on 13.11.2023.
//

#include "ComparisonOperatorHandler.h"

Lexeme *ComparisonOperatorHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    if (node->root->token == "<") {
        if (std::stoi(node->left->root->token) < std::stoi(node->right->root->token)) {
            return new Lexeme("1", tt_integer);
        }
    }
    if (node->root->token == ">") {
        if (std::stoi(node->left->root->token) > std::stoi(node->right->root->token)) {
            return new Lexeme("1", tt_integer);
        }
    }
    if (node->root->token == "==") {
        if (node->left->root->token == node->right->root->token) {
            return new Lexeme("1", tt_integer);
        }
    }

    return new Lexeme("0", tt_integer);
}
