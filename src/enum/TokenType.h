//
// Created by Алексей Заузин on 05.11.2023.
//

#ifndef T7TP1_TOKENTYPE_H
#define T7TP1_TOKENTYPE_H
enum TokenType {
    tt_unknown,
    tt_identifier,
    tt_integer,
    tt_string,
    tt_arithmetic_operator,
    tt_start_of_block,
    tt_end_of_block,
    tt_semicolon,
    tt_parentheses_open,
    tt_parentheses_close,
    tt_variable_declaration,
    tt_print,
    tt_input,
    tt_if,
    tt_assignment,
    tt_comparison_operator,
    tt_for
};
#endif //T7TP1_TOKENTYPE_H
