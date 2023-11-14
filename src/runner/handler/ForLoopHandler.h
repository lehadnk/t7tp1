/**
 * @author Alexey Zauzin
 * ForLoopHandler.h
 * Contains headers for ForLoopHandler
 */

#ifndef T7TP1_FORLOOPHANDLER_H
#define T7TP1_FORLOOPHANDLER_H


#include "AbstractOperationHandler.h"

class ForLoopHandler : public AbstractOperationHandler {
public:
    using AbstractOperationHandler::AbstractOperationHandler;
    Lexeme* handle(Scope* scope, AstNode* node, AstNode *parentNode) override;
};


#endif //T7TP1_FORLOOPHANDLER_H
