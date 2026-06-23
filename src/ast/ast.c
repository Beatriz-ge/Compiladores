#define _GNU_SOURCE
#include "ast.h"
#include "indent_manager.h"
#include "tabela.h"

static ASTNode* current_loop_incr = NULL;

//void indent_print(int level) {
//    for (int i = 0; i < level; i++) {
//        printf("    ");
//    }
// }

ASTNode* allocate_node(NodeType type) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        fprintf(stderr, "Erro de alocação de memória para a AST.\n");
        exit(1);
    }
    node->type = type;
    node->value = NULL;
    node->var_type = NULL;
    node->array_size = 0;
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

ASTNode* create_array_decl_node(char* var_type, char* name, int size, ASTNode* init) {
    ASTNode* node    = allocate_node(NODE_ARRAY_DECL);
    node->var_type   = strdup(var_type);
    node->value      = strdup(name);
    node->array_size = size;
    node->left       = init;
    return node;
}

ASTNode* create_array_access_node(char* name, ASTNode* index) {
    ASTNode* node = allocate_node(NODE_ARRAY_ACCESS);
    node->value   = strdup(name);
    node->left    = index;
    return node;
}

ASTNode* create_array_assign_node(char* name, ASTNode* index, ASTNode* expr) {
    ASTNode* node = allocate_node(NODE_ARRAY_ASSIGN);
    node->value   = strdup(name);
    node->left    = index;
    node->right   = expr;
    return node;
}

ASTNode* create_pointer_decl_node(char* var_type, char* name, ASTNode* init) {
    ASTNode* node  = allocate_node(NODE_PTR_DECL);
    node->var_type = strdup(var_type);
    node->value    = strdup(name);
    node->left     = init;
    return node;
}

ASTNode* create_pointer_assign_node(ASTNode* ptr_expr, ASTNode* val_expr) {
    ASTNode* node = allocate_node(NODE_PTR_ASSIGN);
    node->left    = ptr_expr;
    node->right   = val_expr;
    return node;
}

ASTNode* create_address_node(ASTNode* operand) {
    ASTNode* node = allocate_node(NODE_ADDRESS);
    node->left    = operand;
    return node;
}

ASTNode* create_deref_node(ASTNode* operand) {
    ASTNode* node = allocate_node(NODE_DEREF);
    node->left    = operand;
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
            indent_print(indent_level);
            printf("def %s(%s):\n", node->value,
                node->next ? (char*)node->next : "");
            generate_python(node->left, indent_level + 1);
            break;

        case NODE_BLOCK:
            if (node->left == NULL) {
                indent_print(indent_level);
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
            indent_print(indent_level);
            if (node->left) { 
                printf("%s = ", node->value);
                generate_python(node->left, 0);
                printf("\n");
            } else { 
                printf("%s = None\n", node->value);
            }
            break;

        case NODE_ASSIGN: {
            indent_print(indent_level);

            Simbolo *s = buscar(node->value);

            printf("%s %s ", node->value, node->var_type);

            if (s &&
                s->categoria == SIM_PONTEIRO &&
                node->left &&
                node->left->type != NODE_ADDRESS) {

                printf("[");
                generate_python(node->left, 0);
                printf("]");
            } else {
                generate_python(node->left, 0);
            }

            printf("\n");
            break;
        }

        case NODE_BINARY_OP:
            printf("(");
            generate_python(node->left, 0);
            if (strcmp(node->value, "&&") == 0) {
                printf(" and ");
            } else if (strcmp(node->value, "||") == 0) {
                printf(" or ");
            } else {
                printf(" %s ", node->value);
            }
            generate_python(node->right, 0);
            printf(")");
            break;

        case NODE_WHILE: {
            indent_print(indent_level);
            printf("while ");
            generate_python(node->left, 0);
            printf(":\n");

            ASTNode* prev_incr = current_loop_incr;
            current_loop_incr = NULL;

            generate_python(node->right, indent_level + 1);

            current_loop_incr = prev_incr;
            break;
        }

        case NODE_BREAK:
            indent_print(indent_level);
            printf("break\n");
            break;

        case NODE_CONTINUE:
            if (current_loop_incr) {
                generate_python(current_loop_incr, indent_level);
            }
            indent_print(indent_level);
            printf("continue\n");
            break;

        case NODE_FOR: {
            ASTNode* header = node->left;
            ASTNode* execution = node->right;
            ASTNode* init = header ? header->left : NULL;
            ASTNode* cond = header ? header->right : NULL;
            ASTNode* incr = execution ? execution->left : NULL;
            ASTNode* body = execution ? execution->right : NULL;

            if (init) {
                generate_python(init, indent_level);
            }
            
            indent_print(indent_level);
            printf("while ");
            if (cond) {
                generate_python(cond, 0);
            } else {
                printf("True");
            }
            printf(":\n");

            ASTNode* prev_incr = current_loop_incr;
            current_loop_incr = incr;

            if (body) {
                generate_python(body, indent_level + 1);
            }
            
            current_loop_incr = prev_incr;

            if (incr) {
                generate_python(incr, indent_level + 1);
            }
            
            if (!body && !incr) {
                indent_print(indent_level + 1);
                printf("pass\n");
            }
            break;
        }

        case NODE_LITERAL:
        case NODE_ID:
            if (indent_level > 0) {
                indent_print(indent_level);
                printf("%s\n", node->value);
            } else {
                printf("%s", node->value);
            }
            break;

        case NODE_RETURN:
            indent_print(indent_level);
            printf("return ");
            generate_python(node->left, 0);
            printf("\n");
            break;

        case NODE_UNARY_OP:
            if (strcmp(node->value, "!") == 0) {
                printf("not "); 
            } else {
                printf("%s", node->value); 
            }
            generate_python(node->left, 0);
            break;

        case NODE_IF: {

            indent_print(indent_level);
            printf("if ");
            generate_python(node->left, 0);
            printf(":\n");

            ASTNode* branches = node->right;
            if (branches) {
                generate_python(branches->left, indent_level + 1);

                ASTNode* else_branch = branches->right;
                while (else_branch != NULL) {
                    if (else_branch->type == NODE_IF) {
                        /* else if -> elif */
                        indent_print(indent_level);
                        printf("elif ");
                        generate_python(else_branch->left, 0);
                        printf(":\n");

                        ASTNode* elif_branches = else_branch->right;
                        if (elif_branches) {
                            generate_python(elif_branches->left, indent_level + 1);
                            else_branch = elif_branches->right;
                        } else {
                            else_branch = NULL;
                        }
                    } else {
                        
                        indent_print(indent_level);
                        printf("else:\n");
                        generate_python(else_branch, indent_level + 1);
                        else_branch = NULL;
                    }
                }
            }
            break;
        }

        case NODE_ARRAY_DECL:
            indent_print(indent_level);
            if (!node->left) {
                printf("%s = [None] * %d\n", node->value, node->array_size);
            } else if (node->left->next == NULL && node->left->type != NODE_LITERAL
                       && node->left->type != NODE_ID) {
                printf("%s = ", node->value);
                generate_python(node->left, 0);
                printf("\n");
            } else {
                printf("%s = [", node->value);
                ASTNode* elem = node->left;
                while (elem) {
                    generate_python(elem, 0);
                    if (elem->next) printf(", ");
                    elem = elem->next;
                }
                printf("]\n");
            }
            break;
        
        case NODE_ARRAY_ACCESS:
            printf("%s[", node->value);
            generate_python(node->left, 0);
            printf("]");
            break;   

        case NODE_ARRAY_ASSIGN:
            indent_print(indent_level);
            printf("%s[", node->value);
            generate_python(node->left, 0);
            printf("] = ");
            generate_python(node->right, 0);
            printf("\n");
            break;
        
        case NODE_PTR_DECL:
            indent_print(indent_level);
            if (!node->left) {
                printf("%s = None  # ponteiro %s*\n", node->value, node->var_type);
            } else {
                printf("%s = ", node->value);
                generate_python(node->left, 0);
                printf("  # ponteiro %s*\n", node->var_type);
            }
            break;

        case NODE_PTR_ASSIGN:
            indent_print(indent_level);
            if (node->left && node->left->type == NODE_ID) {
                printf("%s[0] = ", node->left->value);
            } else {
                generate_python(node->left, 0);
                printf("[0] = ");
            }
            generate_python(node->right, 0);
            printf("\n");
            break;

        case NODE_ADDRESS:
            printf("[");
            generate_python(node->left, 0);
            printf("]");
            break;

        case NODE_DEREF:
            generate_python(node->left, 0);
            printf("[0]");
            break;

        case NODE_MULTI_ARRAY_DECL: {
            indent_print(indent_level);
            printf("%s = ", node->value);
            ASTNode* dim = node->left;
            int dim_counts = 0;
            int tam_dimensoes[10];
            while (dim && dim_counts < 10) {
                tam_dimensoes[dim_counts++] = atoi(dim->value);
                dim = dim->next;
            }
            if (node->right) {
                printf("[");
                ASTNode* elem = node->right;
                while (elem) {
                    generate_python(elem, 0);
                    if (elem->next) printf(", ");
                    elem = elem->next;
                }
                printf("]\n");
            } else {
                for (int i = 0; i < dim_counts; i++) {
                    printf("[");
                }
                printf("0");
                for (int i = dim_counts - 1; i >= 0; i--) {
                    printf(" for _ in range(%d)]", tam_dimensoes[i]);
                }
                printf("\n");
            }
            break;
        }

        case NODE_MULTI_ARRAY_ACCESS:
            printf("%s", node->value);
            ASTNode* idx = node->left;
            while (idx) {
                printf("[");
                generate_python(idx->left, 0);
                printf("]");
                idx = idx->next;
            }
            break;

        case NODE_ARRAY_ASSIGN_V2:
            indent_print(indent_level);
            generate_python(node->left, 0); 
            printf(" = ");
            generate_python(node->right, 0);
            printf("\n");
            break;

        case NODE_DIMENSION:
            if (node->value) printf("%s", node->value);
            break;

        case NODE_INDEX:
            if (node->left) generate_python(node->left, 0);
            break;

        case NODE_PRINTF:
            indent_print(indent_level);
            printf("print(");
            generate_python(node->left, 0);
            printf(")\n");
            break;

                case NODE_SCANF:
            indent_print(indent_level);
            printf("%s = input()\n", node->value);
            break;

        case NODE_STRUCT: {
            indent_print(indent_level);
            printf("class %s:\n", node->value);

            indent_print(indent_level + 1);
            printf("def __init__(self):\n");

            if (node->var_type == NULL || strlen(node->var_type) == 0) {
                indent_print(indent_level + 2);
                printf("pass\n");
            } else {
                char* campos = strdup(node->var_type);
                char* campo = strtok(campos, "\n");

                while (campo != NULL) {
                    indent_print(indent_level + 2);
                    printf("self.%s = None\n", campo);
                    campo = strtok(NULL, "\n");
                }

                free(campos);
            }

            printf("\n");
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
        case NODE_WHILE:    return "WHILE_LOOP";
        case NODE_BREAK:    return "BREAK";
        case NODE_CONTINUE: return "CONTINUE";
        case NODE_FOR:      return "FOR_LOOP";
        case NODE_UNARY_OP: return "UNARY_OP";
        case NODE_ARRAY_DECL:   return "ARRAY_DECL";
        case NODE_ARRAY_ACCESS: return "ARRAY_ACCESS";
        case NODE_ARRAY_ASSIGN: return "ARRAY_ASSIGN";
        case NODE_PTR_DECL:     return "PTR_DECL";
        case NODE_PTR_ASSIGN:   return "PTR_ASSIGN";
        case NODE_ADDRESS:      return "ADDRESS";
        case NODE_DEREF:        return "DEREF";
        case NODE_MULTI_ARRAY_DECL:   return "MULTI_ARRAY_DECL";
        case NODE_MULTI_ARRAY_ACCESS: return "MULTI_ARRAY_ACCESS";
        case NODE_DIMENSION:          return "DIMENSION";
        case NODE_INDEX:              return "INDEX";
        case NODE_ARRAY_ASSIGN_V2:    return "MULTI_ARRAY_ASSIGN";
        case NODE_PRINTF: return "PRINTF";
        case NODE_SCANF:  return "SCANF";
        case NODE_STRUCT: return "STRUCT";
        default:          return "UNKNOWN";
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
        else if (node->type == NODE_MULTI_ARRAY_DECL) {
            if (node->left)  print_ast(node->left, level + 1);
            if (node->right) print_ast(node->right, level + 1);
        }
        else if (node->type == NODE_MULTI_ARRAY_ACCESS) {
            if (node->left)  print_ast(node->left, level + 1);
        }
        else if (node->type == NODE_INDEX) {
            if (node->left)  print_ast(node->left, level + 1);
        }
        else {
            if (node->left)  print_ast(node->left, level + 1);
            if (node->right) print_ast(node->right, level + 1);
        }

        node = node->next;
    }
}

ASTNode* create_while_node(ASTNode* condition, ASTNode* body) {
    ASTNode* node = allocate_node(NODE_WHILE);
    node->left = condition;
    node->right = body;
    return node;
}

ASTNode* create_break_node(void) {
    return allocate_node(NODE_BREAK);
}

ASTNode* create_continue_node(void) {
    return allocate_node(NODE_CONTINUE);
}

ASTNode* create_for_node(ASTNode* init, ASTNode* cond, ASTNode* incr, ASTNode* body) {
    ASTNode* node = allocate_node(NODE_FOR);
    
    ASTNode* header = allocate_node(NODE_PROGRAM);
    header->left = init;
    header->right = cond;
    
    ASTNode* execution = allocate_node(NODE_PROGRAM);
    execution->left = incr;
    execution->right = body;
    
    node->left = header;
    node->right = execution;
    return node;
}

ASTNode* create_unary_op_node(char* op, ASTNode* expr) {
    ASTNode* node = allocate_node(NODE_UNARY_OP);
    node->value = strdup(op);
    node->left = expr;
    return node;
}

ASTNode* create_dimension_node(int size, ASTNode* next) {
    ASTNode* node = allocate_node(NODE_DIMENSION);
    char buffer[32];
    sprintf(buffer, "%d", size);
    node->value = strdup(buffer);
    node->next = next;
    return node;
}

ASTNode* create_index_node(ASTNode* expr, ASTNode* next) {
    ASTNode* node = allocate_node(NODE_INDEX);
    node->left = expr;
    node->next = next;
    return node;
}

ASTNode* create_multi_array_decl_node(char* tipo, char* id, ASTNode* dim_list, ASTNode* init_list) {
    ASTNode* node = allocate_node(NODE_MULTI_ARRAY_DECL);
    node->value = strdup(id);
    node->var_type = strdup(tipo);
    node->left = dim_list;
    node->right = init_list;
    return node;
}

ASTNode* create_multi_array_access_node(char* id, ASTNode* idx_list) {
    ASTNode* node = allocate_node(NODE_MULTI_ARRAY_ACCESS);
    node->value = strdup(id);
    node->left = idx_list;
    return node;
}

ASTNode* create_array_assign_node_v2(ASTNode* array_access, ASTNode* expr) {
    ASTNode* node = allocate_node(NODE_ARRAY_ASSIGN_V2);
    node->left = array_access;
    node->right = expr;
    return node;
}

ASTNode* create_printf_node(ASTNode* expr) {
    ASTNode* node = allocate_node(NODE_PRINTF);
    node->left = expr;
    return node;
}

ASTNode* create_scanf_node(char* var) {
    ASTNode* node = allocate_node(NODE_SCANF);
    node->value = strdup(var);
    return node;
}

ASTNode* create_struct_node(char* nome, char* campos) {
    ASTNode* node = allocate_node(NODE_STRUCT);

    node->value = nome ? strdup(nome) : NULL;
    node->var_type = campos ? strdup(campos) : NULL;

    return node;
}
