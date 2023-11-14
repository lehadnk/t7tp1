/**
 * @author Alexey Zauzin
 * ArithmeticOperatorHandler.cpp
 * Contains the implementation for ArithmeticOperationsHandler
 */

#include "ArithmeticOperatorHandler.h"

Lexeme *ArithmeticOperatorHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    if (node->left->root->tokenType == tt_integer && node->right->root->tokenType == tt_integer) {
        if (node->root->token == "+") {
            node->root->token = std::to_string(stoi(node->left->root->token) + stoi(node->right->root->token));
            node->root->tokenType = tt_integer;
        }
        if (node->root->token == "*") {
            node->root->token = std::to_string(stoi(node->left->root->token) * stoi(node->right->root->token));
            node->root->tokenType = tt_integer;
        }
        if (node->root->token == "-") {
            node->root->token = std::to_string(stoi(node->left->root->token) - stoi(node->right->root->token));
            node->root->tokenType = tt_integer;
        }
        if (node->root->token == "/") {
            node->root->token = std::to_string(stoi(node->left->root->token) / stoi(node->right->root->token));
            node->root->tokenType = tt_integer;
        }
    } else {
        if (node->root->token == "+") {
            node->root->token = node->left->root->token + node->right->root->token;
            node->root->tokenType = tt_string;
        } else {
            throw std::runtime_error("Operation" + node->root->token + " is not defined for arguments of this type");
        }
    }
}
