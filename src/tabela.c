#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

typedef struct SímboloHistórico {
    char* nome;       
    char* tipo;       
    int linha;
    TipoSimbolo categoria;
    int tamanho_array;
    struct SímboloHistórico* proximo;
} SimboloHistorico;

static SimboloHistorico* historico_inicio = NULL;
static SimboloHistorico* historico_fim = NULL;

Escopo *escopo_atual = NULL;

void inicializar_tabela_simbolos() {
    if (escopo_atual == NULL) {
        escopo_atual = (Escopo*) malloc(sizeof(Escopo));
        escopo_atual->lista_simbolos = NULL;
        escopo_atual->escopo_pai = NULL; 
    }
}

void entrar_escopo() {
    if (escopo_atual == NULL) {
        inicializar_tabela_simbolos();
    }
    
    Escopo *novo_escopo = (Escopo*) malloc(sizeof(Escopo));
    novo_escopo->lista_simbolos = NULL;
    novo_escopo->escopo_pai = escopo_atual;
    escopo_atual = novo_escopo;
}

void sair_escopo() {
    if (escopo_atual == NULL) return;

    Escopo *escopo_antigo = escopo_atual;
    
    Simbolo *atual = escopo_antigo->lista_simbolos;
    while (atual != NULL) {
        Simbolo *aux = atual;
        atual = atual->proximo;
        free(aux->nome);
        free(aux->tipo);
        free(aux);
    }
    
    escopo_atual = escopo_antigo->escopo_pai;
    
    free(escopo_antigo);
}

static void inserir_simbolo(char* nome, char *tipo, TipoSimbolo cat, int tamanho, int linha) {
    
    if (escopo_atual == NULL) {
        inicializar_tabela_simbolos();
    }

    if (buscar_local(nome) != NULL) {
        fprintf(stderr, "Erro Semantico na linha %d: Redeclaracao de '%s' no mesmo escopo.\n", linha, nome);
        exit(1);
    }

    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->linha = linha;
    novo->categoria     = cat;
    novo->tamanho_array = tamanho;
    novo->proximo = escopo_atual->lista_simbolos;
    escopo_atual->lista_simbolos = novo;

    SimboloHistorico* novo_historico = (SimboloHistorico*)malloc(sizeof(SimboloHistorico));
    novo_historico->nome = strdup(nome); 
    novo_historico->tipo = strdup(tipo);
    novo_historico->linha = linha;
    novo_historico->categoria     = cat;
    novo_historico->tamanho_array = tamanho;
    novo_historico->proximo = NULL;

    if (historico_inicio == NULL) {
        historico_inicio = novo_historico;
        historico_fim = novo_historico;
    } else {
        historico_fim->proximo = novo_historico;
        historico_fim = novo_historico;
    }
}

void inserir(char *nome, char *tipo, int linha) {
    inserir_simbolo(nome, tipo, SIM_VAR, 0, linha);
}

void inserir_array(char *nome, char *tipo, int tamanho, int linha) {
    inserir_simbolo(nome, tipo, SIM_ARRAY, tamanho, linha);
}

void inserir_ponteiro(char *nome, char *tipo, int linha) {
    inserir_simbolo(nome, tipo, SIM_PONTEIRO, 0, linha);
}

Simbolo* buscar(char *nome) {
    Escopo *escopo_varredura = escopo_atual;
    
    
    while (escopo_varredura != NULL) {
        Simbolo *atual = escopo_varredura->lista_simbolos;
        
       
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) {
                return atual; 
            }
            atual = atual->proximo;
        }
        
        escopo_varredura = escopo_varredura->escopo_pai;
    }
    
    return NULL; 
}

Simbolo* buscar_local(char *nome) {
    if (escopo_atual == NULL) return NULL;
    
    Simbolo *atual = escopo_atual->lista_simbolos;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

int simbolo_e_global(char *nome)
{
    if (escopo_atual == NULL)
        return 0;

    Escopo *global = escopo_atual;

    while (global->escopo_pai != NULL)
        global = global->escopo_pai;

    Simbolo *s = global->lista_simbolos;

    while (s)
    {
        if (strcmp(s->nome, nome) == 0)
            return 1;

        s = s->proximo;
    }

    return 0;
}

static const char *categoria_str(TipoSimbolo cat, int tamanho, char *buf, int buf_sz) {
    switch (cat) {
        case SIM_VAR:     return "variavel"; 
        case SIM_PONTEIRO: return "ponteiro"; 
        case SIM_ARRAY: {
            snprintf(buf, buf_sz, "array[%d]", tamanho);
            return buf;
        }
        default: snprintf(buf, buf_sz, "?"); return buf;
    }
    return "?";
}

void imprimir_tabela() {
    if (escopo_atual == NULL) {
        fprintf(stderr, "\n--- TABELA DE SÍMBOLOS VAZIA (NENHUM ESCOPO ATIVO) ---\n");
        return;
    }
    
    Simbolo *atual = escopo_atual->lista_simbolos;
    fprintf(stderr, "\n--- CONTEÚDO DO ESCOPO ATUAL ---\n");
    fprintf(stderr, "%-15s | %-15s | %-12s | %-5s\n", "NOME", "TIPO", "CATEGORIA", "LINHA");
    fprintf(stderr, "--------------------------------------------------\n");
    
    while (atual != NULL) {
        char cat_buf[32];
        const char* cat_nome = categoria_str(atual->categoria, atual->tamanho_array, cat_buf, sizeof(cat_buf));
        fprintf(stderr, "%-15s | %-15s | %-12s | %-5d\n", 
               atual->nome, atual->tipo, cat_nome, atual->linha);
        atual = atual->proximo;
    }
    fprintf(stderr, "--------------------------------------------------\n\n");
}

void imprimir_historico_completo() {
    SimboloHistorico* atual = historico_inicio;
    
    fprintf(stderr, "\n==================================================\n");
    fprintf(stderr, "     HISTÓRICO DE TODOS OS SÍMBOLOS PROCESSADOS   \n");
    fprintf(stderr, "==================================================\n");
    fprintf(stderr, "%-20s | %-15s | %-12s | %-5s\n", "NOME", "TIPO", "CATEGORIA", "LINHA");
    fprintf(stderr, "--------------------------------------------------\n");
    
    if (atual == NULL) {
        fprintf(stderr, "Nenhum símbolo foi processado.\n");
    }

    while (atual != NULL) {
        char cat_buf[32];
        const char* cat_nome = categoria_str(atual->categoria, atual->tamanho_array, cat_buf, sizeof(cat_buf));
        fprintf(stderr, "%-20s | %-15s | %-12s | %-5d\n", 
               atual->nome, atual->tipo, cat_nome, atual->linha);
        atual = atual->proximo;
    }
    
    fprintf(stderr, "--------------------------------------------------\n\n");
}