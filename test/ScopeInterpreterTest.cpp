//
// Created by Алексей Заузин on 01.11.2023.
//
#include "gtest/gtest.h"
#include "dto/Scope.h"
#include "runner/ScopeInterpreter.h"

TEST(TestScopeInterpreter, TestVariableAssignment) {
    auto *scope = new Scope();

    scope->variables.insert({"a", Variable("a", var_str, "Hello World")});

    auto rootNode = new AstNode();
    rootNode->root = new Lexeme();
    rootNode->root->tokenType = tt_identifier;
    rootNode->root->token = "a";
    scope->ast.emplace_back(*rootNode);

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(scope);

    EXPECT_EQ(rootNode->root->token, "Hello World");
    EXPECT_EQ(rootNode->root->tokenType, tt_string);
}

TEST(TestScopeInterpreter, TestSum) {
    auto *scope = new Scope();

    scope->variables.insert({"a", Variable("a", var_int, "3")});
    scope->variables.insert({"b", Variable("b", var_int, "2")});

    auto rootNode = new AstNode();
    rootNode->root = new Lexeme();
    rootNode->root->tokenType = tt_arithmetic_operator;
    rootNode->root->token = "+";

    rootNode->left = new AstNode();
    rootNode->left->root = new Lexeme();
    rootNode->left->root->token = "a";
    rootNode->left->root->tokenType = tt_identifier;

    rootNode->right = new AstNode();
    rootNode->right->root = new Lexeme();
    rootNode->right->root->token = "b";
    rootNode->right->root->tokenType = tt_identifier;

    scope->ast.emplace_back(*rootNode);

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(scope);

    EXPECT_EQ(rootNode->root->token, "5");
    EXPECT_EQ(rootNode->root->tokenType, tt_integer);
}