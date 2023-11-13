//
// Created by Алексей Заузин on 13.11.2023.
//

#include "AssignmentHandler.h"

Lexeme *AssignmentHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    auto variable = scope->variables.find(node->left->operation->token);
    if (variable == scope->variables.end()) {
        throw std::runtime_error("Unknown identifier: " + node->left->operation->token);
    }

    variable->second.value = node->right->operation->token;
    return node->operation;
}
