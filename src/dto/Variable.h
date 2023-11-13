//
// Created by Алексей Заузин on 31.10.2023.
//

#ifndef T7TP1_VARIABLE_H
#define T7TP1_VARIABLE_H
#include <string>
#include "enum/VariableType.h"

struct Variable {
    std::string name;
    VariableType type;
    std::string value;

    explicit Variable(
            VariableType type
    ) {
        this->type = type;
    }

    Variable(
            std::string name,
            VariableType type
    ) {
        this->name = name;
        this->type = type;
    }

    Variable(
            VariableType type,
            std::string value
    ) {
        this->type = type;
        this->value = value;
    }

    Variable(
            std::string name,
            VariableType type,
            std::string value
    ) {
        this->name = name;
        this->type = type;
        this->value = value;
    }
};
#endif //T7TP1_VARIABLE_H