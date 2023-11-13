//
// Created by Алексей Заузин on 13.11.2023.
//

#include "VariableDeclarationHandler.h"

Lexeme *VariableDeclarationHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    if (node->operation->token == "int") {
        auto variable = new Variable(node->left->operation->token, var_int);
        if (node->right != nullptr) {
            variable->value = node->right->operation->token;
        }
        scope->variables.insert({variable->name, *variable});
    }
    if (node->operation->token == "str") {
        auto variable = new Variable(node->left->operation->token, var_str);
        if (node->right != nullptr) {
            variable->value = node->right->operation->token;
        }
        scope->variables.insert({variable->name, *variable});
    }
}
