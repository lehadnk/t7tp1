//
// Created by Алексей Заузин on 13.11.2023.
//

#include "ArithmeticOperatorHandler.h"

Lexeme *ArithmeticOperatorHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    if (node->left->operation->tokenType == tt_integer && node->right->operation->tokenType == tt_integer) {
        if (node->operation->token == "+") {
            node->operation->token = std::to_string(stoi(node->left->operation->token) + stoi(node->right->operation->token));
            node->operation->tokenType = tt_integer;
        }
        if (node->operation->token == "*") {
            node->operation->token = std::to_string(stoi(node->left->operation->token) * stoi(node->right->operation->token));
            node->operation->tokenType = tt_integer;
        }
        if (node->operation->token == "-") {
            node->operation->token = std::to_string(stoi(node->left->operation->token) - stoi(node->right->operation->token));
            node->operation->tokenType = tt_integer;
        }
        if (node->operation->token == "/") {
            node->operation->token = std::to_string(stoi(node->left->operation->token) / stoi(node->right->operation->token));
            node->operation->tokenType = tt_integer;
        }
    } else {
        if (node->operation->token == "+") {
            node->operation->token = node->left->operation->token + node->right->operation->token;
            node->operation->tokenType = tt_string;
        } else {
            throw std::runtime_error("Operation" + node->operation->token + " is not defined for arguments of this type");
        }
    }
}
