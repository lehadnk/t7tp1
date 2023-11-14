/**
 * @author Alexey Zauzin
 * ComparisonOperatorHandler.h
 * Contains the implementation for ComparisonOperatorHandler
 */

#ifndef T7TP1_COMPARISONOPERATORHANDLER_H
#define T7TP1_COMPARISONOPERATORHANDLER_H

#include "AbstractOperationHandler.h"

class ComparisonOperatorHandler : AbstractOperationHandler {
public:
    using AbstractOperationHandler::AbstractOperationHandler;
    Lexeme* handle(Scope* scope, AstNode* node, AstNode *parentNode) override;
};


#endif //T7TP1_COMPARISONOPERATORHANDLER_H
