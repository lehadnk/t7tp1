//
// Created by Алексей Заузин on 07.11.2023.
//

#ifndef T7TP1_ASTNODE_H
#define T7TP1_ASTNODE_H

#include "Lexeme.h"

struct AstNode {
private:
    void dump(const std::string &prefix, const AstNode* node, bool is_left)
    {
        if (node == nullptr) {
            return;
        }

        std::cout << prefix;
        std::cout << (is_left ? "├──" : "└──");
        std::cout << node->root->token << std::endl;

        this->dump(prefix + (is_left ? "│   " : "    "), node->left, true);
        this->dump(prefix + (is_left ? "│   " : "    "), node->right, false);
    }
public:
    Lexeme* root;
    struct AstNode* left;
    struct AstNode* right;

    AstNode() = default;

    AstNode(Lexeme *lexeme) {
        this->root = lexeme;
    }

    AstNode(Lexeme *lexeme, AstNode* left) {
        this->root = lexeme;
        this->left = left;
    }

    AstNode(Lexeme *lexeme, AstNode* left, AstNode* right) {
        this->root = lexeme;
        this->left = left;
        this->right = right;
    }

    void dump() {
        this->dump("", this, false);
    }

};

#endif //T7TP1_ASTNODE_H
