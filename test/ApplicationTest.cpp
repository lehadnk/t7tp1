#include "gtest/gtest.h"
#include "parser/LiteralParser.h"
#include "parser/AbstractSyntaxTreeBuilder.h"
#include "runner/ScopeInterpreter.h"

TEST(ApplicationTest, TestSimpleCalculation) {
    auto abstractSyntaxTreeBuider = new AbstractSyntaxTreeBuilder();
    auto scope = abstractSyntaxTreeBuider->build("int a = 1; int b = a + 2; int c = a + b + 4;");

    auto scopeInterpreter = new ScopeInterpreter();
    scopeInterpreter->run(&scope);

    EXPECT_EQ(scope.variables.at("c").value, "8");
    EXPECT_EQ(scope.variables.at("c").type, var_int);
}

TEST(ApplicationTest, TestMultiplication) {
    auto abstractSyntaxTreeBuider = new AbstractSyntaxTreeBuilder();
    auto scope = abstractSyntaxTreeBuider->build("int a = 3; int b = 2; int c = a * b;");

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(&scope);

    EXPECT_EQ(scope.variables.at("c").value, "6");
    EXPECT_EQ(scope.variables.at("c").type, var_int);
}

TEST(ApplicationTest, TestOperatorOrder) {
    auto abstractSyntaxTreeBuider = new AbstractSyntaxTreeBuilder();
    auto scope = abstractSyntaxTreeBuider->build("int a = 1 + 2 * 3 + 4;");

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(&scope);

    EXPECT_EQ(scope.variables.at("a").value, "11");
    EXPECT_EQ(scope.variables.at("a").type, var_int);
}

TEST(ApplicationTest, TestBraces) {
    auto abstractSyntaxTreeBuider = new AbstractSyntaxTreeBuilder();
    auto scope = abstractSyntaxTreeBuider->build("int a = 3; int b = 2; int c = (a * b) + 2;");

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(&scope);

    EXPECT_EQ(scope.variables.at("c").value, "8");
    EXPECT_EQ(scope.variables.at("c").type, var_int);

    abstractSyntaxTreeBuider = new AbstractSyntaxTreeBuilder();
    scope = abstractSyntaxTreeBuider->build("int d = 3; int e = 2; int f = d * (e + 2);");

    scopeRunner->run(&scope);

    EXPECT_EQ(scope.variables.at("f").value, "12");
    EXPECT_EQ(scope.variables.at("f").type, var_int);
}

TEST(ApplicationTest, TestInput) {
//    auto abstractSyntaxTreeBuider = new AbstractSyntaxTreeBuilder();
//    auto scope = abstractSyntaxTreeBuider->build("int a; input a; print a;");
//
//    auto scopeRunner = new ScopeInterpreter();
//    scopeRunner->run(&scope);
}

TEST(ApplicationTest, TestIf) {
    auto abstractSyntaxTreeBuider = new AbstractSyntaxTreeBuilder();
    auto scope = abstractSyntaxTreeBuider->build("int a = 1; if (a > 0) { a = a + 1; } if (a > 3) { a = a + 1; } if (a == 2) { a = a + 1; }");

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(&scope);

    EXPECT_EQ(scope.variables.at("a").value, "3");
}

TEST(ApplicationTest, TestFor) {
    auto abstractSyntaxTreeBuider = new AbstractSyntaxTreeBuilder();
    auto scope = abstractSyntaxTreeBuider->build("int a = 0; for (int b = 0; b < 5; b = b + 1) { a = a + 1; }");

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(&scope);

    EXPECT_EQ(scope.variables.at("a").value, "5");
}

TEST(ApplicationTest, TestLogic) {
    auto abstractSyntaxTreeBuider = new AbstractSyntaxTreeBuilder();
    auto scope = abstractSyntaxTreeBuider->build("int a = 1; int b = a + 2; if (a > 0) { for(int c = 0; c < 10; c = c + 1) { print c; } }");

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(&scope);

    EXPECT_EQ(scope.variables.at("c").value, "10");
}

TEST(ApplicationTest, PrintString) {
    auto abstractSyntaxTreeBuider = new AbstractSyntaxTreeBuilder();
    auto scope = abstractSyntaxTreeBuider->build("print \"Please enter the first number:\n\";");

    auto scopeRunner = new ScopeInterpreter();
    scopeRunner->run(&scope);
}