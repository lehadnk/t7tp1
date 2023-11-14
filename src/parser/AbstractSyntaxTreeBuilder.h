/**
 * @author Alexey Zauzin
 * AbstractSyntaxTreeBuilder.h
 * Hedaer file for AbstractSyntaxTreeBuilder
 */

#ifndef T7TP1_ABSTRACTSYNTAXTREEBUILDER_H
#define T7TP1_ABSTRACTSYNTAXTREEBUILDER_H


#include "dto/Scope.h"
#include "dto/AstNode.h"

class AbstractSyntaxTreeBuilder {
public:
    Scope build(std::string code);
private:
    Scope* parseScope();
    AstNode* parseStatement(Scope* scope);
    AstNode* parseArgument();
    AstNode* parseArithmeticExpression();
    AstNode* parseBooleanExpression();
    AstNode* parseForStatement(Scope* scope);
    AstNode* parseIfStatement(Scope* scope);
    AstNode* parseInputStatement();
    AstNode* parseIdentifier();
    AstNode* parsePrintStatement();
    AstNode* parseVariableDeclaration();
    AstNode* parseTerm();
    Lexeme* getCurrent();
    std::vector<AstNode> astNodes;
    std::vector<Lexeme> lexemes;
    int index = 0;
};


#endif //T7TP1_ABSTRACTSYNTAXTREEBUILDER_H
