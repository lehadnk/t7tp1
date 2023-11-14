/**
 * @author Alexey Zauzin
 * AbstractSyntaxTreeBuilder.cpp
 * Contains AbstractSyntaxTreeBuilder class method definitions
 */


#include "AbstractSyntaxTreeBuilder.h"

#include <utility>
#include "Lexer.h"

Scope AbstractSyntaxTreeBuilder::build(std::string code)
{
    auto lexer = new Lexer(std::move(code));
    this->lexemes = lexer->parse();
    this->index = 0;

    return *this->parseScope();
}

Scope* AbstractSyntaxTreeBuilder::parseScope() {
    auto scope = new Scope();
    while(this->getCurrent()->tokenType != tt_end_of_block && this->index < this->lexemes.size()) {
        scope->ast.emplace_back(*this->parseStatement(scope));
        this->index++;
    }

    return scope;
}

AstNode* AbstractSyntaxTreeBuilder::parseStatement(Scope* scope)
{
    if (this->getCurrent()->tokenType == tt_for) {
        return this->parseForStatement(scope);
    }
    if (this->getCurrent()->tokenType == tt_if) {
        return this->parseIfStatement(scope);
    }
    if (this->getCurrent()->tokenType == tt_input) {
        return this->parseInputStatement();
    }
    if (this->getCurrent()->tokenType == tt_identifier) {
        return this->parseIdentifier();
    }
    if (this->getCurrent()->tokenType == tt_print) {
        return this->parsePrintStatement();
    }
    if (this->getCurrent()->tokenType == tt_variable_declaration) {
        return this->parseVariableDeclaration();
    }

    throw std::runtime_error("Unknown token: " + this->getCurrent()->token);
}

AstNode* AbstractSyntaxTreeBuilder::parseVariableDeclaration()
{
    // Variable declaration statement
    auto node = new AstNode;
    node->root = this->getCurrent();
    this->index++;

    if (this->getCurrent()->tokenType != tt_identifier) {
        throw std::runtime_error("Identifier expected, got " + this->getCurrent()->token);
    }

    node->left = new AstNode(this->getCurrent());
    this->index++;

    if (this->getCurrent()->tokenType == tt_assignment) {
        this->index++;
        node->right = this->parseArithmeticExpression();
    }

    return node;
}

AstNode* AbstractSyntaxTreeBuilder::parsePrintStatement()
{
    auto node = new AstNode;
    node->root = this->getCurrent();
    this->index++;

    if (this->getCurrent()->tokenType != tt_identifier && this->getCurrent()->tokenType != tt_parentheses_open && this->getCurrent()->tokenType != tt_string) {
        throw std::runtime_error("Identifier, parenthesis or string expected, got " + this->getCurrent()->token);
    }

    node->left = this->parseArithmeticExpression();
    return node;
}

AstNode* AbstractSyntaxTreeBuilder::parseIdentifier()
{
    // Assignment statement
    auto node = new AstNode;
    node->root = new Lexeme("=", tt_assignment);
    node->left = new AstNode(this->getCurrent());
    this->index++;

    if (this->getCurrent()->tokenType != tt_assignment) {
        throw std::runtime_error("Assignment operator expected, got " + this->getCurrent()->token);
    }

    this->index++;

    node->right = this->parseArithmeticExpression();
    return node;
}

AstNode* AbstractSyntaxTreeBuilder::parseInputStatement()
{
    auto node = new AstNode;
    node->root = this->getCurrent();
    this->index++;

    if (this->getCurrent()->tokenType != tt_identifier) {
        throw std::runtime_error("Identifier expected, got " + this->getCurrent()->token);
    }

    node->left = this->parseArithmeticExpression();
    return node;
}

AstNode* AbstractSyntaxTreeBuilder::parseIfStatement(Scope *scope) {
    auto node = new AstNode;
    node->root = this->getCurrent();
    this->index++;

    if (this->getCurrent()->tokenType != tt_parentheses_open) {
        throw std::runtime_error("Open parenthesis expected, got " + this->getCurrent()->token);
    }
    this->index++;

    node->left = this->parseBooleanExpression();

    if (this->getCurrent()->tokenType != tt_parentheses_close) {
        throw std::runtime_error("Close parenthesis expected, got " + this->getCurrent()->token);
    }
    this->index++;

    if (this->getCurrent()->tokenType != tt_start_of_block) {
        throw std::runtime_error("Start of block expected, got " + this->getCurrent()->token);
    }
    this->index++;

    auto newScope = this->parseScope();
    scope->subscopes.emplace_back(*newScope);
    node->right = new AstNode(new Lexeme(std::to_string(scope->subscopes.size() - 1), tt_integer));

    if (this->getCurrent()->tokenType != tt_end_of_block) {
        throw std::runtime_error("End of block expected, got " + this->getCurrent()->token);
    }
    return node;
}

AstNode* AbstractSyntaxTreeBuilder::parseForStatement(Scope* scope) {
    auto node = new AstNode;
    node->root = this->getCurrent();
    this->index++;

    if (this->getCurrent()->tokenType != tt_parentheses_open) {
        throw std::runtime_error("Open parenthesis expected, got " + this->getCurrent()->token);
    }
    this->index++;

    node->left = this->parseStatement(scope);

    if (this->getCurrent()->tokenType != tt_semicolon) {
        throw std::runtime_error("Expected semicolon, got " + this->getCurrent()->token);
    }
    this->index++;

    node->right = new AstNode;
    node->right->root = new Lexeme("exit_condition", tt_for);
    node->right->left = this->parseBooleanExpression();

    if (this->getCurrent()->tokenType != tt_semicolon) {
        throw std::runtime_error("Expected semicolon, got " + this->getCurrent()->token);
    }
    this->index++;

    node->right->right = new AstNode;
    node->right->right->root = new Lexeme("expression", tt_for);
    node->right->right->left = this->parseStatement(scope);

    if (this->getCurrent()->tokenType != tt_parentheses_close) {
        throw std::runtime_error("Close parenthesis expected, got " + this->getCurrent()->token);
    }
    this->index++;
    this->index++;

    auto newScope = this->parseScope();
    scope->subscopes.emplace_back(*newScope);
    node->right->right->right = new AstNode(new Lexeme(std::to_string(scope->subscopes.size() - 1), tt_integer));

    return node;
}

AstNode* AbstractSyntaxTreeBuilder::parseArithmeticExpression()
{
    auto node = this->parseTerm();
    while(this->getCurrent()->tokenType == tt_arithmetic_operator && (this->getCurrent()->token == "+" || this->getCurrent()->token == "-")) {
        node = new AstNode(this->getCurrent(), node);
        this->index++;
        node->right = this->parseTerm();
    }

    return node;
}

AstNode* AbstractSyntaxTreeBuilder::parseBooleanExpression()
{
    if (this->getCurrent()->tokenType != tt_identifier && this->getCurrent()->tokenType != tt_integer && this->getCurrent()->tokenType != tt_string) {
        throw std::runtime_error("Expected identifier or integer, got " + this->getCurrent()->token);
    }

    auto node = new AstNode;
    node->left = new AstNode(this->getCurrent());
    this->index++;

    if (this->getCurrent()->tokenType != tt_comparison_operator) {
        throw std::runtime_error("Expected comparison operator, got " + this->getCurrent()->token);
    }
    node->root = this->getCurrent();
    this->index++;

    if (this->getCurrent()->tokenType != tt_integer && this->getCurrent()->tokenType != tt_string && this->getCurrent()->tokenType != tt_identifier) {
        throw std::runtime_error("Expected constant or identifier, got " + this->getCurrent()->token);
    }
    node->right = new AstNode(this->getCurrent());
    this->index++;

    return node;
}

AstNode* AbstractSyntaxTreeBuilder::parseTerm() {
    auto node = this->parseArgument();
    while(this->getCurrent()->tokenType == tt_arithmetic_operator && (this->getCurrent()->token == "*" || this->getCurrent()->token == "/")) {
        node = new AstNode(this->getCurrent(), node);
        this->index++;
        node->right = this->parseArgument();
    }

    return node;
}

AstNode* AbstractSyntaxTreeBuilder::parseArgument()
{
    if (this->getCurrent()->tokenType == tt_parentheses_open) {
        this->index++;
        auto node = this->parseArithmeticExpression();

        if (this->getCurrent()->tokenType != tt_parentheses_close) {
            throw std::runtime_error("Unclosed parenthesis, got " + this->getCurrent()->token);
        }
        this->index++;

        return node;
    }
    if (this->getCurrent()->tokenType == tt_integer || this->getCurrent()->tokenType == tt_string || this->getCurrent()->tokenType == tt_identifier) {
        auto node = new AstNode(this->getCurrent());
        this->index++;
        return node;
    }

    throw std::runtime_error("Unsupported token: " + this->getCurrent()->token);
}

Lexeme* AbstractSyntaxTreeBuilder::getCurrent() {
    return &this->lexemes[this->index];
}