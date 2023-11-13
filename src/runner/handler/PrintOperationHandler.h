//
// Created by Алексей Заузин on 13.11.2023.
//

#ifndef T7TP1_PRINTOPERATIONHANDLER_H
#define T7TP1_PRINTOPERATIONHANDLER_H

#include "AbstractOperationHandler.h"

class PrintOperationHandler : AbstractOperationHandler {
public:
    using AbstractOperationHandler::AbstractOperationHandler;
    Lexeme* handle(Scope* scope, AstNode* node, AstNode *parentNode) override;
};


#endif //T7TP1_PRINTOPERATIONHANDLER_H
