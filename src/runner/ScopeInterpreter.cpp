/**
 * @author Alexey Zauzin
 * ScopeInterpreter.cpp
 * Contains ScopeInterpreter method definitions
 */

#include "ScopeInterpreter.h"
#include "runner/handler/ForLoopHandler.h"
#include "runner/handler/IfConditionHandler.h"
#include "runner/handler/InputHandler.h"
#include "runner/handler/AssignmentHandler.h"
#include "runner/handler/ArithmeticOperatorHandler.h"
#include "runner/handler/VariableDeclarationHandler.h"
#include "runner/handler/IdentifierHandler.h"
#include "runner/handler/PrintOperationHandler.h"
#include "runner/handler/ComparisonOperatorHandler.h"

void ScopeInterpreter::run(Scope* scope) {
    for(auto node : scope->ast) {
        this->processNode(scope, &node, nullptr);
    }
}

Lexeme* ScopeInterpreter::processNode(Scope* scope, AstNode* node, AstNode* parentNode) { // NOLINT(*-no-recursion)
    if (node->root->tokenType == tt_for) {
        auto handler = new ForLoopHandler(this);
        return handler->handle(scope, node, parentNode);
    }

    if (node->root->tokenType == tt_if) {
        auto handler = new IfConditionHandler(this);
        return handler->handle(scope, node, parentNode);
    }
    if (node->root->tokenType == tt_input) {
        auto handler = new InputHandler(this);
        return handler->handle(scope, node, parentNode);
    }
    if (node->right != nullptr) {
        node->right->root = this->processNode(scope, node->right, node);
    }
    if (node->root->tokenType == tt_assignment) {
        auto handler = new AssignmentHandler(this);
        return handler->handle(scope, node, parentNode);
    }
    if (node->left != nullptr) {
        node->left->root = this->processNode(scope, node->left, node);
    }
    if (node->root->tokenType == tt_arithmetic_operator) {
        auto handler = new ArithmeticOperatorHandler(this);
        handler->handle(scope, node, parentNode);
    }
    if (node->root->tokenType == tt_variable_declaration) {
        auto handler = new VariableDeclarationHandler(this);
        handler->handle(scope, node, parentNode);
    }
    if (node->root->tokenType == tt_identifier) {
        auto handler = new IdentifierHandler(this);
        return handler->handle(scope, node, parentNode);
    }
    if (node->root->tokenType == tt_integer || node->root->tokenType == tt_string) {
        return node->root;
    }
    if (node->root->tokenType == tt_print) {
        auto handler = new PrintOperationHandler(this);
        return handler->handle(scope, node, parentNode);
    }
    if (node->root->tokenType == tt_comparison_operator) {
        auto handler = new ComparisonOperatorHandler(this);
        return handler->handle(scope, node, parentNode);
    }

    return node->root;
}
