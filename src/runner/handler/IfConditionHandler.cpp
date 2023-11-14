//
// Created by Алексей Заузин on 13.11.2023.
//

#include "IfConditionHandler.h"

Lexeme *IfConditionHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    auto processConditionNodeResult = this->scope_runner->processNode(scope, node->left, nullptr);
    if (processConditionNodeResult->token == "1") {
        auto subscope = &scope->subscopes[std::stoi(node->right->root->token)];
        subscope->variables = scope->variables;
        this->scope_runner->run(subscope);
        scope->variables = subscope->variables;
    }

    return node->root;
}
