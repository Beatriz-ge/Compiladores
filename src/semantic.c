#include "semantic.h"
#include "diagnostics.h" /* <- ADICIONADO PARA USAR O SISTEMA DE DIAGNÓSTICO */

static TipoRank obter_rank(const char* tipo) {
    if (tipo == NULL)             return TIPO_INVALIDO;
    if (strcmp(tipo, "char")   == 0) return TIPO_CHAR;
    if (strcmp(tipo, "int")    == 0) return TIPO_INT;
    if (strcmp(tipo, "long")   == 0) return TIPO_LONG;
    if (strcmp(tipo, "float")  == 0) return TIPO_FLOAT;
    if (strcmp(tipo, "double") == 0) return TIPO_DOUBLE;
    if (strcmp(tipo, "void")   == 0) return TIPO_VOID;
    if (strstr(tipo, "*") != NULL)   return TIPO_PONTEIRO;
    if (strncmp(tipo, "struct", 6) == 0) return TIPO_INVALIDO;
    return TIPO_INVALIDO;
}

static const char* rank_para_str(TipoRank rank) {
    switch (rank) {
        case TIPO_CHAR:     return "char";
        case TIPO_INT:      return "int";
        case TIPO_LONG:     return "long";
        case TIPO_FLOAT:    return "float";
        case TIPO_DOUBLE:   return "double";
        case TIPO_PONTEIRO: return "ponteiro";
        case TIPO_VOID:     return "void";
        default:            return "invalido";
    }
}

static const char* inferir_tipo_literal(const char* value) {
    if (value == NULL) return "int";
    if (value[0] == '\'') return "char";
    if (value[0] == '"') return "char";
    size_t len = strlen(value);
    if (len > 0 && (value[len-1] == 'f' || value[len-1] == 'F')) return "float";
    if (strchr(value, '.') != NULL) return "double";
    return "int";
}

const char* inferir_tipo(ASTNode* node) {
    if (node == NULL) return "invalido";
    if (node->var_type != NULL && strlen(node->var_type) > 0)
        return node->var_type;

    switch (node->type) {
        case NODE_LITERAL: {
            const char* t = inferir_tipo_literal(node->value);
            node->var_type = strdup(t);
            return node->var_type;
        }
        case NODE_ID: {
            Simbolo* s = buscar(node->value);
            if (s == NULL) { node->var_type = strdup("invalido"); return node->var_type; }
            node->var_type = strdup(s->tipo);
            return node->var_type;
        }
        case NODE_ARRAY_ACCESS: {
            Simbolo* s = buscar(node->value);
            if (s == NULL) { node->var_type = strdup("invalido"); return node->var_type; }
            node->var_type = strdup(s->tipo);
            return node->var_type;
        }
        case NODE_DEREF: {
            const char* t_inner = inferir_tipo(node->left);
            node->var_type = strdup(t_inner);
            return node->var_type;
        }
        case NODE_ADDRESS:
            node->var_type = strdup("ponteiro");
            return node->var_type;
        case NODE_BINARY_OP: {
            const char* t_esq = inferir_tipo(node->left);
            const char* t_dir = inferir_tipo(node->right);
            const char* op = node->value;
            if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0 ||
                strcmp(op, "<")  == 0 || strcmp(op, ">")  == 0 ||
                strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0 ||
                strcmp(op, "&&") == 0 || strcmp(op, "||") == 0) {
                node->var_type = strdup("int");
                return node->var_type;
            }
            const char* t_result = promover_tipos(t_esq, t_dir);
            if (t_result == NULL) t_result = "invalido";
            node->var_type = strdup(t_result);
            return node->var_type;
        }
        case NODE_UNARY_OP:
            if (node->value && strcmp(node->value, "!") == 0)
                node->var_type = strdup("int");
            else {
                const char* t = inferir_tipo(node->left);
                node->var_type = strdup(t);
            }
            return node->var_type;
        default:
            return "invalido";
    }
}

const char* promover_tipos(const char* tipo_esq, const char* tipo_dir) {
    if (tipo_esq == NULL || tipo_dir == NULL) return NULL;
    TipoRank rank_esq = obter_rank(tipo_esq);
    TipoRank rank_dir = obter_rank(tipo_dir);
    if (rank_esq == TIPO_INVALIDO || rank_dir == TIPO_INVALIDO) return NULL;
    if (rank_esq == TIPO_VOID     || rank_dir == TIPO_VOID)     return NULL;
    if (rank_esq == TIPO_PONTEIRO || rank_dir == TIPO_PONTEIRO) {
        int outro_esq = (rank_esq != TIPO_PONTEIRO) ? rank_esq : -1;
        int outro_dir = (rank_dir != TIPO_PONTEIRO) ? rank_dir : -1;
        int outro = (outro_esq != -1) ? outro_esq : outro_dir;
        if (outro == TIPO_INT || outro == TIPO_CHAR || outro == TIPO_LONG)
            return "ponteiro";
        return NULL;
    }
    TipoRank resultado = (rank_esq >= rank_dir) ? rank_esq : rank_dir;
    return rank_para_str(resultado);
}

static int e_tipo_inteiro(const char* tipo) {
    return (strcmp(tipo, "int")  == 0 ||
            strcmp(tipo, "char") == 0 ||
            strcmp(tipo, "long") == 0);
}

static int e_tipo_escalar(const char* tipo) {
    TipoRank r = obter_rank(tipo);
    return (r >= TIPO_CHAR && r <= TIPO_DOUBLE) || r == TIPO_PONTEIRO;
}

void checar_operacao_binaria(const char* op,
                             const char* tipo_esq,
                             const char* tipo_dir,
                             int linha) {
    char msg[512];

    if (strcmp(op, "&&") == 0 || strcmp(op, "||") == 0) {
        if (!e_tipo_escalar(tipo_esq) || !e_tipo_escalar(tipo_dir)) {
            snprintf(msg, sizeof(msg), "Operador '%s' nao pode ser aplicado entre '%s' e '%s'.", op, tipo_esq, tipo_dir);
            emitir_erro_semantico(linha, msg);
            exit(1);
        }
        return;
    }
    if (strcmp(op, "==") == 0 || strcmp(op, "!=") == 0 ||
        strcmp(op, "<")  == 0 || strcmp(op, ">")  == 0 ||
        strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0) {
        if (!e_tipo_escalar(tipo_esq) || !e_tipo_escalar(tipo_dir)) {
            snprintf(msg, sizeof(msg), "Comparacao '%s' invalida entre '%s' e '%s'.", op, tipo_esq, tipo_dir);
            emitir_erro_semantico(linha, msg);
            exit(1);
        }
        return;
    }
    if (strcmp(op, "%") == 0) {
        if (!e_tipo_inteiro(tipo_esq) || !e_tipo_inteiro(tipo_dir)) {
            snprintf(msg, sizeof(msg), "Operador '%%' requer operandos inteiros, mas recebeu '%s' e '%s'.", tipo_esq, tipo_dir);
            emitir_erro_semantico(linha, msg);
            exit(1);
        }
        return;
    }
    const char* tipo_result = promover_tipos(tipo_esq, tipo_dir);
    if (tipo_result == NULL) {
        if (strncmp(tipo_esq, "struct", 6) == 0 || strncmp(tipo_dir, "struct", 6) == 0)
            snprintf(msg, sizeof(msg), "Operacao aritmetica '%s' invalida: tipo struct nao suporta aritmetica.", op);
        else if (strcmp(tipo_esq, "void") == 0 || strcmp(tipo_dir, "void") == 0)
            snprintf(msg, sizeof(msg), "Operacao '%s' invalida: tipo 'void' nao pode ser operando.", op);
        else
            snprintf(msg, sizeof(msg), "Operacao '%s' invalida entre os tipos '%s' e '%s'.", op, tipo_esq, tipo_dir);
        
        emitir_erro_semantico(linha, msg);
        exit(1);
    }
    if (strcmp(tipo_esq, tipo_dir) != 0 && strcmp(tipo_result, "ponteiro") != 0) {
        snprintf(msg, sizeof(msg), "Coercao implicita em '%s': '%s' promovido para '%s'.",
            op,
            (obter_rank(tipo_esq) < obter_rank(tipo_dir)) ? tipo_esq : tipo_dir,
            tipo_result);
        emitir_aviso(linha, msg);
    }
}

extern int yylineno;

void analisar_semantico(ASTNode* node) {
    if (node == NULL) return;
    switch (node->type) {
        case NODE_PROGRAM:
            analisar_semantico(node->left);
            analisar_semantico(node->right);
            return;
        case NODE_FUNC:
            analisar_semantico(node->left);
            return;
        case NODE_BLOCK:
            analisar_semantico(node->left);
            return;
        
        case NODE_BINARY_OP:
            analisar_semantico(node->left);
            analisar_semantico(node->right);
            inferir_tipo(node);
            break;
        case NODE_UNARY_OP:
            analisar_semantico(node->left);
            inferir_tipo(node);
            break;
        case NODE_IF:
            analisar_semantico(node->left);
            analisar_semantico(node->right);
            if (node->right && node->right->next)
                analisar_semantico(node->right->next);
            break;
        case NODE_WHILE:
            analisar_semantico(node->left);
            analisar_semantico(node->right);
            break;
        case NODE_FOR:
            analisar_semantico(node->left);
            if (node->left) analisar_semantico(node->left->next);
            analisar_semantico(node->right);
            break;
        case NODE_RETURN:
            analisar_semantico(node->left);
            inferir_tipo(node->left);
            break;
        case NODE_ARRAY_DECL:
        case NODE_ARRAY_ASSIGN:
            analisar_semantico(node->left);
            analisar_semantico(node->right);
            break;
        case NODE_ARRAY_ACCESS:
            analisar_semantico(node->left);
            break;
        case NODE_PTR_DECL:
        case NODE_PTR_ASSIGN:
            analisar_semantico(node->right);
            break;
        case NODE_ADDRESS:
        case NODE_DEREF:
            analisar_semantico(node->left);
            inferir_tipo(node);
            break;
        case NODE_LITERAL:
        case NODE_ID:
            inferir_tipo(node);
            break;
        default:
            analisar_semantico(node->left);
            analisar_semantico(node->right);
            break;
    }
    if (node->next != NULL) analisar_semantico(node->next);
}

static const char* inferir_tipo_live(ASTNode* node) {
    if (node == NULL) return "invalido";
    if (node->var_type != NULL && strlen(node->var_type) > 0)
        return node->var_type;
    switch (node->type) {
        case NODE_LITERAL:
            return inferir_tipo_literal(node->value);
        case NODE_ID: {
            Simbolo* s = buscar(node->value);
            if (s == NULL) return "invalido";
            return s->tipo;
        }
        case NODE_BINARY_OP: {
            const char* t_esq = inferir_tipo_live(node->left);
            const char* t_dir = inferir_tipo_live(node->right);
            const char* t_res = promover_tipos(t_esq, t_dir);
            return t_res ? t_res : "invalido";
        }
        case NODE_UNARY_OP:
            return inferir_tipo_live(node->left);
        default:
            return "invalido";
    }
}

void checar_operacao_binaria_parser(const char* op,
                                    ASTNode* esq,
                                    ASTNode* dir,
                                    int linha) {
    if (esq == NULL || dir == NULL) return;
    const char* t_esq = inferir_tipo_live(esq);
    const char* t_dir = inferir_tipo_live(dir);
    if (strcmp(t_esq, "invalido") == 0 || strcmp(t_dir, "invalido") == 0)
        return;
    checar_operacao_binaria(op, t_esq, t_dir, linha);
}

void checar_atribuicao_parser(char* nome, ASTNode* expr, int linha) {
    if (nome == NULL || expr == NULL) return;

    Simbolo* s = buscar(nome);
    if (s == NULL) return;

    const char* t_var  = s->tipo;
    const char* t_expr = inferir_tipo_live(expr);
    if (t_var == NULL || t_expr == NULL || strcmp(t_expr, "invalido") == 0)
        return;

    TipoRank r_var  = obter_rank(t_var);
    TipoRank r_expr = obter_rank(t_expr);
    if (r_expr > r_var && r_var != TIPO_INVALIDO) {
        char msg[256];
        snprintf(msg, sizeof(msg), "Atribuicao com possivel perda de precisao: '%s' atribuido a variavel '%s' do tipo '%s'.", t_expr, nome, t_var);
        emitir_aviso(linha, msg);
    }
}