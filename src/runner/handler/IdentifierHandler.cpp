//
// Created by Алексей Заузин on 13.11.2023.
//

#include "IdentifierHandler.h"

Lexeme *IdentifierHandler::handle(Scope *scope, AstNode *node, AstNode* parentNode) {
    auto variable = scope->variables.find(node->operation->token);
    if (variable == scope->variables.end()) {
        if (parentNode != nullptr && parentNode->operation->tokenType == tt_variable_declaration) {
            // Variable declaration could handle unknown identifiers in the tree
            return node->operation;
        }
        throw std::runtime_error("Unknown identifier: " + node->operation->token);
    }

    node->operation->token = variable->second.value;
    if (variable->second.type == var_int) {
        node->operation->tokenType = tt_integer;
    }
    if (variable->second.type == var_str) {
        node->operation->tokenType = tt_string;
    }

    return node->operation;
}
