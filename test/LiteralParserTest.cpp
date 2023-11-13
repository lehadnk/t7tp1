
//
// Created by Алексей Заузин on 04.11.2023.
//
#include "gtest/gtest.h"
#include "parser/LiteralParser.h"

TEST(LiteralParserTest, TestReadOperationOrVariableIdentifier)
{
    auto literalParser = new LiteralParser("int i = 271;\necho \"test test\";");
    auto lexems = literalParser->parse();

    EXPECT_EQ(lexems.size(), 8);
    EXPECT_EQ(lexems[0].token, "int");
    EXPECT_EQ(lexems[0].tokenType, tt_variable_declaration);
    EXPECT_EQ(lexems[1].token, "i");
    EXPECT_EQ(lexems[1].tokenType, tt_identifier);
    EXPECT_EQ(lexems[2].token, "=");
    EXPECT_EQ(lexems[2].tokenType, tt_assignment);
    EXPECT_EQ(lexems[3].token, "271");
    EXPECT_EQ(lexems[3].tokenType, tt_integer);
    EXPECT_EQ(lexems[4].token, ";");
    EXPECT_EQ(lexems[4].tokenType, tt_semicolon);
    EXPECT_EQ(lexems[5].token, "echo");
    EXPECT_EQ(lexems[5].tokenType, tt_identifier);
    EXPECT_EQ(lexems[6].token, "test test");
    EXPECT_EQ(lexems[6].tokenType, tt_string);
    EXPECT_EQ(lexems[7].token, ";");
    EXPECT_EQ(lexems[7].tokenType, tt_semicolon);
}

TEST(LiteralParserTest, TestParseParenthesis) {
    auto literalParser = new LiteralParser("int i = (b + 3);");
    auto lexems = literalParser->parse();

    EXPECT_EQ(lexems.size(), 9);
    EXPECT_EQ(lexems[3].token, "(");
    EXPECT_EQ(lexems[3].tokenType, tt_parentheses_open);
    EXPECT_EQ(lexems[7].token, ")");
    EXPECT_EQ(lexems[7].tokenType, tt_parentheses_close);
}