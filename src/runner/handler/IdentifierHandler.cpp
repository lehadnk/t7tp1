/**
 * @author Alexey Zauzin
 * IdentifierHandler
 * Contains the implementation for IdentifierHanlder
 */

#include "IdentifierHandler.h"

Lexeme *IdentifierHandler::handle(Scope *scope, AstNode *node, AstNode* parentNode) {
    auto variable = scope->variables.find(node->root->token);
    if (variable == scope->variables.end()) {
        if (parentNode != nullptr && parentNode->root->tokenType == tt_variable_declaration) {
            // Variable declaration could handle unknown identifiers in the tree
            return node->root;
        }
        throw std::runtime_error("Unknown identifier: " + node->root->token);
    }

    node->root->token = variable->second.value;
    if (variable->second.type == var_int) {
        node->root->tokenType = tt_integer;
    }
    if (variable->second.type == var_str) {
        node->root->tokenType = tt_string;
    }

    return node->root;
}
