//
// Created by Алексей Заузин on 04.11.2023.
//
#include "gtest/gtest.h"
#include "parser/AbstractSyntaxTreeBuilder.h"


TEST(AbstractSyntaxTreeBuilderTest, BuildBasicTree) {
    auto builder = new AbstractSyntaxTreeBuilder();
    auto scope = builder->build("int i = 10 + 3 + 2; print i;");

    // It's easier to debug having a visual representation
    scope.ast[0].dump();

    EXPECT_EQ(scope.ast.size(), 2);
    EXPECT_EQ(scope.ast[0].root->token, "int");
    EXPECT_EQ(scope.ast[0].root->tokenType, tt_variable_declaration);
    EXPECT_EQ(scope.ast[0].left->root->token, "i");
    EXPECT_EQ(scope.ast[0].left->root->tokenType, tt_identifier);
    EXPECT_EQ(scope.ast[0].right->root->token, "+");
    EXPECT_EQ(scope.ast[0].right->root->tokenType, tt_arithmetic_operator);
    EXPECT_EQ(scope.ast[0].right->left->root->token, "+");
    EXPECT_EQ(scope.ast[0].right->left->root->tokenType, tt_arithmetic_operator);
    EXPECT_EQ(scope.ast[0].right->left->left->root->token, "10");
    EXPECT_EQ(scope.ast[0].right->left->left->root->tokenType, tt_integer);
    EXPECT_EQ(scope.ast[0].right->left->right->root->token, "3");
    EXPECT_EQ(scope.ast[0].right->left->right->root->tokenType, tt_integer);
    EXPECT_EQ(scope.ast[0].right->right->root->token, "2");
    EXPECT_EQ(scope.ast[0].right->right->root->tokenType, tt_integer);
}

TEST(AbstractSyntaxTreeBuilderTest, BuildTreeWithParenthesis) {
    auto builder = new AbstractSyntaxTreeBuilder();
    auto scope = builder->build("int i = 1 + 2 * (3 + 4);");

    scope.ast[0].dump();

    EXPECT_EQ(scope.ast.size(), 1);
    EXPECT_EQ(scope.ast[0].root->token, "int");
    EXPECT_EQ(scope.ast[0].root->tokenType, tt_variable_declaration);
    EXPECT_EQ(scope.ast[0].left->root->token, "i");
    EXPECT_EQ(scope.ast[0].left->root->tokenType, tt_identifier);

    EXPECT_EQ(scope.ast[0].right->root->token, "+");
    EXPECT_EQ(scope.ast[0].right->root->tokenType, tt_arithmetic_operator);
    EXPECT_EQ(scope.ast[0].right->left->root->token, "1");
    EXPECT_EQ(scope.ast[0].right->left->root->tokenType, tt_integer);

    EXPECT_EQ(scope.ast[0].right->right->root->token, "*");
    EXPECT_EQ(scope.ast[0].right->right->root->tokenType, tt_arithmetic_operator);
    EXPECT_EQ(scope.ast[0].right->right->left->root->token, "2");
    EXPECT_EQ(scope.ast[0].right->right->left->root->tokenType, tt_integer);
    EXPECT_EQ(scope.ast[0].right->right->right->root->token, "+");
    EXPECT_EQ(scope.ast[0].right->right->right->root->tokenType, tt_arithmetic_operator);
    EXPECT_EQ(scope.ast[0].right->right->right->left->root->token, "3");
    EXPECT_EQ(scope.ast[0].right->right->right->left->root->tokenType, tt_integer);
    EXPECT_EQ(scope.ast[0].right->right->right->right->root->token, "4");
    EXPECT_EQ(scope.ast[0].right->right->right->right->root->tokenType, tt_integer);
}