//
// Created by Алексей Заузин on 13.11.2023.
//

#ifndef T7TP1_IDENTIFIERHANDLER_H
#define T7TP1_IDENTIFIERHANDLER_H

#include "AbstractOperationHandler.h"

class IdentifierHandler : AbstractOperationHandler {
public:
    using AbstractOperationHandler::AbstractOperationHandler;
    Lexeme* handle(Scope* scope, AstNode* node, AstNode* parentNode);
};


#endif //T7TP1_IDENTIFIERHANDLER_H
