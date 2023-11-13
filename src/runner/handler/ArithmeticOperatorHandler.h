//
// Created by Алексей Заузин on 13.11.2023.
//

#ifndef T7TP1_ARITHMETICOPERATORHANDLER_H
#define T7TP1_ARITHMETICOPERATORHANDLER_H


#include "AbstractOperationHandler.h"

class ArithmeticOperatorHandler : AbstractOperationHandler {
public:
    using AbstractOperationHandler::AbstractOperationHandler;
    Lexeme* handle(Scope* scope, AstNode* node, AstNode *parentNode) override;
};


#endif //T7TP1_ARITHMETICOPERATORHANDLER_H
