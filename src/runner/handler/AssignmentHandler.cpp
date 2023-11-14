/**
 * @author Alexey Zauzin
 * AssignmentHandler.cpp
 * Contains the implementation for AssignmentHandler class
 */

#include "AssignmentHandler.h"

Lexeme *AssignmentHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    auto variable = scope->variables.find(node->left->root->token);
    if (variable == scope->variables.end()) {
        throw std::runtime_error("Unknown identifier: " + node->left->root->token);
    }

    variable->second.value = node->right->root->token;
    return node->root;
}
