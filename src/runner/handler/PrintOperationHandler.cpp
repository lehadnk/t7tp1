/**
 * @author Alexey Zauzin
 * PrintOperationHandler.cpp
 * Contains the implementation for PrintOperationHandler
 */

#include "PrintOperationHandler.h"

Lexeme *PrintOperationHandler::handle(Scope *scope, AstNode *node, AstNode *parentNode) {
    std::cout << node->left->root->token;
}
