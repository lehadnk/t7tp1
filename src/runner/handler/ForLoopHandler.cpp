/**
 * @author Alexey Zauzin
 * ForLoopHanlder.h
 * Contains the implementation for ForLoopHandler
 */

#include "ForLoopHandler.h"

AstNode *copyAstNode(AstNode *root) {
    AstNode *newRoot;
    if (root != NULL) {
        newRoot = new AstNode;
        newRoot->root = new Lexeme(root->root->token, root->root->tokenType);
        newRoot->left = copyAstNode(root->left);
        newRoot->right = copyAstNode(root->right);
    } else {
        return NULL;
    }

    return newRoot;
}

std::vector<AstNode>* copyAstNodeVector(std::vector<AstNode> nodes)
{
    auto newVector = new std::vector<AstNode>;
    for(auto node : nodes) {
        auto newNode = copyAstNode(&node);
        newVector->emplace_back(*newNode);
    }

    return newVector;
}

Lexeme* ForLoopHandler::handle(Scope* scope, AstNode* node, AstNode *parentNode) {
    this->scope_runner->processNode(scope, node->left, nullptr);

    auto exitConditionCopy = copyAstNode(node->right->left);
    auto continueLoopCopy = copyAstNode(node->right->right->left);
    auto subscope = &scope->subscopes[std::stoi(node->right->right->right->root->token)];
    auto bodyCopy = copyAstNodeVector(subscope->ast);
    while(this->scope_runner->processNode(scope, node->right->left, nullptr)->token != "0") {
        subscope->variables = scope->variables;
        subscope->ast = *copyAstNodeVector(*bodyCopy);
        this->scope_runner->run(subscope);
        scope->variables = subscope->variables;

        this->scope_runner->processNode(scope, node->right->right->left, nullptr);
        node->right->left = copyAstNode(exitConditionCopy);
        node->right->right->left = copyAstNode(continueLoopCopy);
    }

    return node->root;
}