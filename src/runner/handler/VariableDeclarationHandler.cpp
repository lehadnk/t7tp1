/**
 * @author Alexey Zauzin
 * VariableDeclarationHandler.cpp
 * Contain the implementation for VariableDeclarationHandler
 */

#include "VariableDeclarationHandler.h"

Lexeme *VariableDeclarationHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    if (node->root->token == "int") {
        auto variable = new Variable(node->left->root->token, var_int);
        if (node->right != nullptr) {
            variable->value = node->right->root->token;
        }
        scope->variables.insert({variable->name, *variable});
    }
    if (node->root->token == "str") {
        auto variable = new Variable(node->left->root->token, var_str);
        if (node->right != nullptr) {
            variable->value = node->right->root->token;
        }
        scope->variables.insert({variable->name, *variable});
    }
}
