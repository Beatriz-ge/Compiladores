#ifndef TABELA_FUNCOES_H
#define TABELA_FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FuncaoRegistrada {
    char* nome;
    int   num_params;
    int   linha;
    struct FuncaoRegistrada* proximo;
} FuncaoRegistrada;

void        registrar_funcao(char* nome, int num_params, int linha);
FuncaoRegistrada* buscar_funcao(char* nome);
void        checar_chamada_funcao(char* nome, int num_args, int linha);
void        imprimir_tabela_funcoes(void);

#endif

int contar_params(const char* params_str);
int contar_args(const char* args_str);