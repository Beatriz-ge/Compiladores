#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NODE_PROGRAM,
    NODE_FUNC,
    NODE_BLOCK,
    NODE_VAR_DECL,
    NODE_ASSIGN,
    NODE_IF,
    NODE_RETURN,
    NODE_LITERAL,
    NODE_ID,
    NODE_BINARY_OP
} NodeType;

typedef struct ASTNode {
    NodeType type;
    
    char* value;       
    char* var_type;    

    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* next;  
} ASTNode;

ASTNode* create_literal_node(char* value);
ASTNode* create_id_node(char* name);
ASTNode* create_binary_op_node(char* op, ASTNode* left, ASTNode* right);
ASTNode* create_assign_node(char* id, char* op, ASTNode* expr);
ASTNode* create_decl_node(char* var_type, char* id, ASTNode* init_expr);
ASTNode* create_if_node(ASTNode* condition, ASTNode* then_branch, ASTNode* else_branch);
ASTNode* create_return_node(ASTNode* expr);
ASTNode* create_block_node(ASTNode* commands);
ASTNode* create_func_node(char* ret_type, char* name, char* params, ASTNode* body);
ASTNode* create_program_node(ASTNode* child, ASTNode* next);

void generate_python(ASTNode* node, int indent_level);
void print_ast(ASTNode* node, int level);

#endif