/**
 * @author Alexey Zauzin
 * InputHandler.cpp
 * Contains the implementation for InputHandler
 */

#include "InputHandler.h"

Lexeme *InputHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    std::string input;
    std::cin >> input;

    auto variable = scope->variables.find(node->left->root->token);
    if (variable == scope->variables.end()) {
        throw std::runtime_error("Unknown identifier: " + node->left->root->token);
    }
    if (variable->second.type == var_int) {
        variable->second.value = std::to_string(std::stoi(input));
    }
    if (variable->second.type == var_str) {
        variable->second.value = input;
    }

    return node->root;
}
