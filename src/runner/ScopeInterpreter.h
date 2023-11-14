/**
 * @author Alexey Zauzin
 * ScopeInterpreter.h
 * Contains headers for ScopeInterpreter
 */

#ifndef T7TP1_SCOPEINTERPRETER_H
#define T7TP1_SCOPEINTERPRETER_H


#include "dto/Scope.h"

class ScopeInterpreter {
    public:
        void run(Scope* scope);
        Lexeme* processNode(Scope* scope, AstNode* node, AstNode* parentNode);
};


#endif //T7TP1_SCOPEINTERPRETER_H
