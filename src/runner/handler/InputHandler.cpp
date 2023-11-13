//
// Created by Алексей Заузин on 13.11.2023.
//

#include "InputHandler.h"

Lexeme *InputHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    std::string input;
    std::cin >> input;

    auto variable = scope->variables.find(node->left->operation->token);
    if (variable == scope->variables.end()) {
        throw std::runtime_error("Unknown identifier: " + node->left->operation->token);
    }
    if (variable->second.type == var_int) {
        variable->second.value = std::to_string(std::stoi(input));
    }
    if (variable->second.type == var_str) {
        variable->second.value = input;
    }

    return node->operation;
}
