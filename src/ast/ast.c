#define _GNU_SOURCE
#include "ast.h"

void print_python_indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
}

ASTNode* allocate_node(NodeType type) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Erro de alocação de memória para a AST.\n");
        exit(1);
    }
    node->type = type;
    node->value = NULL;
    node->var_type = NULL;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

ASTNode* create_literal_node(char* value) {
    ASTNode* node = allocate_node(NODE_LITERAL);
    node->value = strdup(value);
    return node;
}

ASTNode* create_id_node(char* name) {
    ASTNode* node = allocate_node(NODE_ID);
    node->value = strdup(name);
    return node;
}

ASTNode* create_binary_op_node(char* op, ASTNode* left, ASTNode* right) {
    ASTNode* node = allocate_node(NODE_BINARY_OP);
    node->value = strdup(op);
    node->left = left;
    node->right = right;
    return node;
}

ASTNode* create_assign_node(char* id, char* op, ASTNode* expr) {
    ASTNode* node = allocate_node(NODE_ASSIGN);
    node->value = strdup(id);
    node->var_type = strdup(op);
    node->left = expr;
    return node;
}

ASTNode* create_decl_node(char* var_type, char* id, ASTNode* init_expr) {
    ASTNode* node = allocate_node(NODE_VAR_DECL);
    node->var_type = strdup(var_type);
    node->value = strdup(id);
    node->left = init_expr; 
    return node;
}

ASTNode* create_if_node(ASTNode* condition, ASTNode* then_branch, ASTNode* else_branch) {
    ASTNode* node = allocate_node(NODE_IF);
    node->left = condition;
    
    ASTNode* branches = allocate_node(NODE_PROGRAM);
    branches->left = then_branch;
    branches->right = else_branch; 
    
    node->right = branches;
    return node;
}

ASTNode* create_return_node(ASTNode* expr) {
    ASTNode* node = allocate_node(NODE_RETURN);
    node->left = expr;
    return node;
}

ASTNode* create_block_node(ASTNode* commands) {
    ASTNode* node = allocate_node(NODE_BLOCK);
    node->left = commands;
    return node;
}

ASTNode* create_func_node(char* ret_type, char* name, char* params, ASTNode* body) {
    ASTNode* node = allocate_node(NODE_FUNC);
    node->var_type = strdup(ret_type);
    node->value = strdup(name);
    node->next = params ? (ASTNode*)strdup(params) : NULL; 
    node->left = body;
    return node;
}

ASTNode* create_program_node(ASTNode* child, ASTNode* next) {
    ASTNode* node = allocate_node(NODE_PROGRAM);
    node->left = child;
    node->next = next;
    return node;
}

void generate_python(ASTNode* node, int indent_level) {
    if (!node) return;

    switch (node->type) {
        case NODE_PROGRAM:
            generate_python(node->left, indent_level);
            generate_python(node->next, indent_level);
            break;

        case NODE_FUNC:
            print_python_indent(indent_level);
            printf("def %s(%s):\n", node->value, node->next ? (char*)node->next : "");
            generate_python(node->left, indent_level + 1); 
            break;

        case NODE_BLOCK:
            if (node->left == NULL) {
                print_python_indent(indent_level);
                printf("pass\n");
            } else {
                ASTNode* curr = node->left;
                while (curr) {
                    generate_python(curr, indent_level);
                    curr = curr->next;
                }
            }
            break;

        case NODE_VAR_DECL:
            print_python_indent(indent_level);
            if (node->left) { 
                printf("%s = ", node->value);
                generate_python(node->left, 0);
                printf("\n");
            } else { 
                printf("%s = None\n", node->value);
            }
            break;

        case NODE_ASSIGN:
            print_python_indent(indent_level);
            printf("%s %s ", node->value, node->var_type);
            generate_python(node->left, 0);
            printf("\n");
            break;

        case NODE_BINARY_OP:
            printf("(");
            generate_python(node->left, 0);
            printf(" %s ", node->value);
            generate_python(node->right, 0);
            printf(")");
            break;

        case NODE_LITERAL:
        case NODE_ID:
            printf("%s", node->value);
            break;

        case NODE_RETURN:
            print_python_indent(indent_level);
            printf("return ");
            generate_python(node->left, 0);
            printf("\n");
            break;

        case NODE_IF: {
            print_python_indent(indent_level);
            printf("if ");
            generate_python(node->left, 0); 
            printf(":\n");
            
            ASTNode* branches = node->right;
            if (branches) {
                generate_python(branches->left, indent_level + 1); 
                
                if (branches->right) { 
                    print_python_indent(indent_level);
                    printf("else:\n");
                    generate_python(branches->right, indent_level + 1); 
                }
            }
            break;
        }
    }
} 

const char* get_node_type_name(NodeType type) {
    switch (type) {
        case NODE_PROGRAM:  return "PROGRAM";
        case NODE_FUNC:     return "FUNCTION";
        case NODE_BLOCK:    return "BLOCK";
        case NODE_VAR_DECL: return "VAR_DECL";
        case NODE_ASSIGN:   return "ASSIGN";
        case NODE_IF:       return "IF_STATEMENT";
        case NODE_RETURN:   return "RETURN";
        case NODE_LITERAL:  return "LITERAL";
        case NODE_ID:       return "IDENTIFIER";
        case NODE_BINARY_OP:return "BINARY_OP";
        default:            return "UNKNOWN";
    }
}

void print_ast(ASTNode* node, int level) {
    if (!node) return;

    while (node != NULL) {
        for (int i = 0; i < level; i++) {
            printf(i == level - 1 ? "|-- " : "|   ");
        }

        printf("[%s]", get_node_type_name(node->type));
        if (node->value && strlen(node->value) > 0) {
            printf(" value: '%s'", node->value);
        }
        if (node->var_type && strlen(node->var_type) > 0) {
            printf(" (type: %s)", node->var_type);
        }
        printf("\n");

        if (node->type == NODE_IF) {
            if (node->left) {
                print_ast(node->left, level + 1);
            }
            ASTNode* branches = node->right;
            if (branches && branches->type == NODE_PROGRAM) {
                if (branches->left)  print_ast(branches->left, level + 1);
                if (branches->right) print_ast(branches->right, level + 1);
            }
        } 
        else if (node->type == NODE_FUNC) {
            if (node->left) {
                print_ast(node->left, level + 1);
            }
            return; 
        }
        else if (node->type == NODE_BLOCK) {
            if (node->left) {
                print_ast(node->left, level + 1);
            }
        } 
        else if (node->type == NODE_PROGRAM) {
            if (node->left)  print_ast(node->left, level + 1);
            if (node->right) print_ast(node->right, level + 1);
        } 
        else {
            if (node->left)  print_ast(node->left, level + 1);
            if (node->right) print_ast(node->right, level + 1);
        }

        node = node->next;
    }
}