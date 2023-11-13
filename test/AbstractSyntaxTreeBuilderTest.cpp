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
    EXPECT_EQ(scope.ast[0].operation->token, "int");
    EXPECT_EQ(scope.ast[0].operation->tokenType, tt_variable_declaration);
    EXPECT_EQ(scope.ast[0].left->operation->token, "i");
    EXPECT_EQ(scope.ast[0].left->operation->tokenType, tt_identifier);
    EXPECT_EQ(scope.ast[0].right->operation->token, "+");
    EXPECT_EQ(scope.ast[0].right->operation->tokenType, tt_arithmetic_operator);
    EXPECT_EQ(scope.ast[0].right->left->operation->token, "+");
    EXPECT_EQ(scope.ast[0].right->left->operation->tokenType, tt_arithmetic_operator);
    EXPECT_EQ(scope.ast[0].right->left->left->operation->token, "10");
    EXPECT_EQ(scope.ast[0].right->left->left->operation->tokenType, tt_integer);
    EXPECT_EQ(scope.ast[0].right->left->right->operation->token, "3");
    EXPECT_EQ(scope.ast[0].right->left->right->operation->tokenType, tt_integer);
    EXPECT_EQ(scope.ast[0].right->right->operation->token, "2");
    EXPECT_EQ(scope.ast[0].right->right->operation->tokenType, tt_integer);
}

TEST(AbstractSyntaxTreeBuilderTest, BuildTreeWithParenthesis) {
    auto builder = new AbstractSyntaxTreeBuilder();
    auto scope = builder->build("int i = 1 + 2 * (3 + 4);");

    scope.ast[0].dump();

    EXPECT_EQ(scope.ast.size(), 1);
    EXPECT_EQ(scope.ast[0].operation->token, "int");
    EXPECT_EQ(scope.ast[0].operation->tokenType, tt_variable_declaration);
    EXPECT_EQ(scope.ast[0].left->operation->token, "i");
    EXPECT_EQ(scope.ast[0].left->operation->tokenType, tt_identifier);

    EXPECT_EQ(scope.ast[0].right->operation->token, "+");
    EXPECT_EQ(scope.ast[0].right->operation->tokenType, tt_arithmetic_operator);
    EXPECT_EQ(scope.ast[0].right->left->operation->token, "1");
    EXPECT_EQ(scope.ast[0].right->left->operation->tokenType, tt_integer);

    EXPECT_EQ(scope.ast[0].right->right->operation->token, "*");
    EXPECT_EQ(scope.ast[0].right->right->operation->tokenType, tt_arithmetic_operator);
    EXPECT_EQ(scope.ast[0].right->right->left->operation->token, "2");
    EXPECT_EQ(scope.ast[0].right->right->left->operation->tokenType, tt_integer);
    EXPECT_EQ(scope.ast[0].right->right->right->operation->token, "+");
    EXPECT_EQ(scope.ast[0].right->right->right->operation->tokenType, tt_arithmetic_operator);
    EXPECT_EQ(scope.ast[0].right->right->right->left->operation->token, "3");
    EXPECT_EQ(scope.ast[0].right->right->right->left->operation->tokenType, tt_integer);
    EXPECT_EQ(scope.ast[0].right->right->right->right->operation->token, "4");
    EXPECT_EQ(scope.ast[0].right->right->right->right->operation->tokenType, tt_integer);
}