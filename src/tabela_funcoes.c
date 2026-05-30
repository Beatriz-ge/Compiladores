#include "tabela_funcoes.h"

static FuncaoRegistrada* tabela_funcoes = NULL;

void registrar_funcao(char* nome, int num_params, int linha) {
    /* Ignora redeclaração — pode acontecer com funções built-in */
    if (buscar_funcao(nome) != NULL) return;

    FuncaoRegistrada* nova = (FuncaoRegistrada*)malloc(sizeof(FuncaoRegistrada));
    nova->nome       = strdup(nome);
    nova->num_params = num_params;
    nova->linha      = linha;
    nova->proximo    = tabela_funcoes;
    tabela_funcoes   = nova;
}

FuncaoRegistrada* buscar_funcao(char* nome) {
    FuncaoRegistrada* atual = tabela_funcoes;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void checar_chamada_funcao(char* nome, int num_args, int linha) {
    FuncaoRegistrada* f = buscar_funcao(nome);

    /* Função não registrada — pode ser externa (printf, etc.) */
    if (f == NULL) return;

    if (num_args != f->num_params) {
        fprintf(stderr,
            "Erro Semantico na linha %d: "
            "Funcao '%s' esperava %d argumento(s), mas recebeu %d.\n",
            linha, nome, f->num_params, num_args);
        exit(1);
    }
}

void imprimir_tabela_funcoes(void) {
    fprintf(stderr, "\n==================================================\n");
    fprintf(stderr, "     TABELA DE FUNCOES REGISTRADAS                \n");
    fprintf(stderr, "==================================================\n");
    fprintf(stderr, "%-20s | %-10s | %-5s\n", "NOME", "PARAMETROS", "LINHA");
    fprintf(stderr, "--------------------------------------------------\n");

    FuncaoRegistrada* atual = tabela_funcoes;
    if (atual == NULL) {
        fprintf(stderr, "Nenhuma funcao registrada.\n");
    }
    while (atual != NULL) {
        fprintf(stderr, "%-20s | %-10d | %-5d\n",
            atual->nome, atual->num_params, atual->linha);
        atual = atual->proximo;
    }
    fprintf(stderr, "--------------------------------------------------\n\n");
}

/* Conta o número de parâmetros a partir da string "a, b, c" */
int contar_params(const char* params_str) {
    if (params_str == NULL || strlen(params_str) == 0) return 0;
    int count = 1;
    for (const char* p = params_str; *p; p++) {
        if (*p == ',') count++;
    }
    return count;
}

/* Conta o número de argumentos a partir da string "a, b, c" */
int contar_args(const char* args_str) {
    if (args_str == NULL || strlen(args_str) == 0) return 0;
    int count = 1;
    for (const char* p = args_str; *p; p++) {
        if (*p == ',') count++;
    }
    return count;
}