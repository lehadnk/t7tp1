/**
 * @author Alexey Zauzin
 * InputHandler.h
 * Contains headers for InputHandler
 */

#ifndef T7TP1_INPUTHANDLER_H
#define T7TP1_INPUTHANDLER_H


#include "AbstractOperationHandler.h"

class InputHandler : AbstractOperationHandler {
public:
    using AbstractOperationHandler::AbstractOperationHandler;
    Lexeme* handle(Scope* scope, AstNode* node, AstNode *parentNode) override;
};


#endif //T7TP1_INPUTHANDLER_H
