
//
// Created by Алексей Заузин on 04.11.2023.
//
#include "gtest/gtest.h"
#include "parser/Lexer.h"

TEST(LexerTest, TestReadOperationOrVariableIdentifier)
{
    auto lexer = new Lexer("int i = 271;\necho \"test test\";");
    auto lexemes = lexer->parse();

    EXPECT_EQ(lexemes.size(), 8);
    EXPECT_EQ(lexemes[0].token, "int");
    EXPECT_EQ(lexemes[0].tokenType, tt_variable_declaration);
    EXPECT_EQ(lexemes[1].token, "i");
    EXPECT_EQ(lexemes[1].tokenType, tt_identifier);
    EXPECT_EQ(lexemes[2].token, "=");
    EXPECT_EQ(lexemes[2].tokenType, tt_assignment);
    EXPECT_EQ(lexemes[3].token, "271");
    EXPECT_EQ(lexemes[3].tokenType, tt_integer);
    EXPECT_EQ(lexemes[4].token, ";");
    EXPECT_EQ(lexemes[4].tokenType, tt_semicolon);
    EXPECT_EQ(lexemes[5].token, "echo");
    EXPECT_EQ(lexemes[5].tokenType, tt_identifier);
    EXPECT_EQ(lexemes[6].token, "test test");
    EXPECT_EQ(lexemes[6].tokenType, tt_string);
    EXPECT_EQ(lexemes[7].token, ";");
    EXPECT_EQ(lexemes[7].tokenType, tt_semicolon);
}

TEST(LexerTest, TestParseParenthesis) {
    auto lexer = new Lexer("int i = (b + 3);");
    auto lexemes = lexer->parse();

    EXPECT_EQ(lexemes.size(), 9);
    EXPECT_EQ(lexemes[3].token, "(");
    EXPECT_EQ(lexemes[3].tokenType, tt_parentheses_open);
    EXPECT_EQ(lexemes[7].token, ")");
    EXPECT_EQ(lexemes[7].tokenType, tt_parentheses_close);
}