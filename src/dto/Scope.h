/**
 * @author Alexey Zauzin
 * Scope.h
 * Contains scope definition
 */

#ifndef T7TP1_SCOPE_H
#define T7TP1_SCOPE_H
#include <vector>
#include <map>
#include "dto/Variable.h"
#include "dto/AstNode.h"

struct Scope
{
    std::vector<AstNode> ast;
    std::map<std::string, Variable> variables;
    std::vector<Scope> subscopes;
};
#endif //T7TP1_SCOPE_H