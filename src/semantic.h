#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast/ast.h"
#include "tabela.h"

typedef enum {
    TIPO_INVALIDO = 0,
    TIPO_CHAR     = 1,
    TIPO_INT      = 2,
    TIPO_LONG     = 3,
    TIPO_FLOAT    = 4,
    TIPO_DOUBLE   = 5,
    TIPO_PONTEIRO = 6,
    TIPO_VOID     = 7
} TipoRank;

void analisar_semantico(ASTNode* node);
const char* inferir_tipo(ASTNode* node);
const char* promover_tipos(const char* tipo_esq, const char* tipo_dir);
void checar_operacao_binaria(const char* op, const char* tipo_esq, const char* tipo_dir, int linha);
void checar_operacao_binaria_parser(const char* op, ASTNode* esq, ASTNode* dir, int linha);
void checar_atribuicao_parser(char* nome, ASTNode* expr, int linha);

#endif
