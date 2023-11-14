/**
 * @author Alexey Zauzin
 * AssignmentHandler.h
 * Contains headers for AssignmentHandler
 */

#ifndef T7TP1_ASSIGNMENTHANDLER_H
#define T7TP1_ASSIGNMENTHANDLER_H


#include "AbstractOperationHandler.h"

class AssignmentHandler : AbstractOperationHandler {
public:
    using AbstractOperationHandler::AbstractOperationHandler;
    Lexeme* handle(Scope* scope, AstNode* node, AstNode *parentNode) override;
};


#endif //T7TP1_ASSIGNMENTHANDLER_H
