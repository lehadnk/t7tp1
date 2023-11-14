/**
 * @author Alexey Zauzin
 * AbstractOperationHandler.h
 * Contains header files for AbstractOperationHandler
 */

#ifndef T7TP1_ABSTRACTOPERATIONHANDLER_H
#define T7TP1_ABSTRACTOPERATIONHANDLER_H


#include "runner/ScopeInterpreter.h"

class AbstractOperationHandler {
public:
    explicit AbstractOperationHandler(ScopeInterpreter* scopeRunner)
    {
        this->scope_runner = scopeRunner;
    }
    virtual Lexeme* handle(Scope* scope, AstNode* node, AstNode* parentNode) = 0;
private:
protected:
    ScopeInterpreter* scope_runner;
};


#endif //T7TP1_ABSTRACTOPERATIONHANDLER_H
