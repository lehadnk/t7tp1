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
    rootNode->operation = new Lexeme();
    rootNode->operation->tokenType = tt_identifier;
    rootNode->operation->token = "a";
    scope->ast.emplace_back(*rootNode);

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(scope);

    EXPECT_EQ(rootNode->operation->token, "Hello World");
    EXPECT_EQ(rootNode->operation->tokenType, tt_string);
}

TEST(TestScopeInterpreter, TestSum) {
    auto *scope = new Scope();

    scope->variables.insert({"a", Variable("a", var_int, "3")});
    scope->variables.insert({"b", Variable("b", var_int, "2")});

    auto rootNode = new AstNode();
    rootNode->operation = new Lexeme();
    rootNode->operation->tokenType = tt_arithmetic_operator;
    rootNode->operation->token = "+";

    rootNode->left = new AstNode();
    rootNode->left->operation = new Lexeme();
    rootNode->left->operation->token = "a";
    rootNode->left->operation->tokenType = tt_identifier;

    rootNode->right = new AstNode();
    rootNode->right->operation = new Lexeme();
    rootNode->right->operation->token = "b";
    rootNode->right->operation->tokenType = tt_identifier;

    scope->ast.emplace_back(*rootNode);

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(scope);

    EXPECT_EQ(rootNode->operation->token, "5");
    EXPECT_EQ(rootNode->operation->tokenType, tt_integer);
}