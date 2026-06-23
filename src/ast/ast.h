#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

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
    NODE_BINARY_OP,
    NODE_WHILE,
    NODE_BREAK,
    NODE_CONTINUE,
    NODE_FOR,
    NODE_UNARY_OP,
    NODE_ARRAY_DECL,
    NODE_ARRAY_ACCESS,
    NODE_ARRAY_ASSIGN,
    NODE_PTR_DECL,
    NODE_PTR_ASSIGN,
    NODE_ADDRESS,
    NODE_DEREF,
    NODE_MULTI_ARRAY_DECL,
    NODE_MULTI_ARRAY_ACCESS,
    NODE_DIMENSION,
    NODE_INDEX,
    NODE_PRINTF,
    NODE_SCANF,
    NODE_ARRAY_ASSIGN_V2,
    NODE_STRUCT
} NodeType;

typedef struct ASTNode {
    NodeType type;
    
    char* value;       
    char* var_type;    
    int   array_size;

    Simbolo *simbolo;
    int eh_global;

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
ASTNode* create_while_node(ASTNode* condition, ASTNode* body);
ASTNode* create_break_node(void);
ASTNode* create_continue_node(void);
ASTNode* create_for_node(ASTNode* init, ASTNode* cond, ASTNode* incr, ASTNode* body);
ASTNode* create_unary_op_node(char* op, ASTNode* expr);
ASTNode* create_array_decl_node(char* var_type, char* name, int size, ASTNode* init);
ASTNode* create_array_access_node(char* name, ASTNode* index);
ASTNode* create_array_assign_node(char* name, ASTNode* index, ASTNode* expr);
ASTNode* create_pointer_decl_node(char* var_type, char* name, ASTNode* init);
ASTNode* create_pointer_assign_node(ASTNode* ptr_expr, ASTNode* val_expr);
ASTNode* create_address_node(ASTNode* operand);
ASTNode* create_deref_node(ASTNode* operand);
ASTNode* create_dimension_node(int size, ASTNode* next);
ASTNode* create_index_node(ASTNode* expr, ASTNode* next);
ASTNode* create_multi_array_decl_node(char* tipo, char* id, ASTNode* dim_list, ASTNode* init_list);
ASTNode* create_multi_array_access_node(char* id, ASTNode* idx_list);
ASTNode* create_array_assign_node_v2(ASTNode* array_access, ASTNode* expr);
ASTNode* create_printf_node(ASTNode* expr);
ASTNode* create_scanf_node(char* var);
ASTNode* create_struct_node(char* nome, char* campos);
void generate_python(ASTNode* node, int indent_level);
void print_ast(ASTNode* node, int level);

#endif
