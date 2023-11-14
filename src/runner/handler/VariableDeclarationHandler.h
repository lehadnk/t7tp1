/**
 * @author Alexey Zauzin
 * VariableDeclarationHandler
 * Contains headers for VariableDeclarationHandler
 */

#ifndef T7TP1_VARIABLEDECLARATIONHANDLER_H
#define T7TP1_VARIABLEDECLARATIONHANDLER_H

#include "AbstractOperationHandler.h"

class VariableDeclarationHandler : AbstractOperationHandler {
public:
    using AbstractOperationHandler::AbstractOperationHandler;
    Lexeme* handle(Scope* scope, AstNode* node, AstNode *parentNode) override;
};


#endif //T7TP1_VARIABLEDECLARATIONHANDLER_H
