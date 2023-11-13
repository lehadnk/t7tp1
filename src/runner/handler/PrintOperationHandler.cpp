//
// Created by Алексей Заузин on 13.11.2023.
//

#include "PrintOperationHandler.h"

Lexeme *PrintOperationHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    std::cout << node->left->operation->token;
}
