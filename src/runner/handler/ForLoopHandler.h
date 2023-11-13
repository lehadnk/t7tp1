//
// Created by Алексей Заузин on 12.11.2023.
//

#ifndef T7TP1_FORLOOPHANDLER_H
#define T7TP1_FORLOOPHANDLER_H


#include "AbstractOperationHandler.h"

class ForLoopHandler : public AbstractOperationHandler {
public:
    using AbstractOperationHandler::AbstractOperationHandler;
    Lexeme* handle(Scope* scope, AstNode* node, AstNode *parentNode) override;
};


#endif //T7TP1_FORLOOPHANDLER_H
