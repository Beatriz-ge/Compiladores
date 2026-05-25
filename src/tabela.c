#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

typedef struct SímboloHistórico {
    char* nome;       
    char* tipo;       
    int linha;
    struct SímboloHistórico* proximo;
} SimboloHistorico;

static SimboloHistorico* historico_inicio = NULL;
static SimboloHistorico* historico_fim = NULL;

Escopo *escopo_atual = NULL;

void entrar_escopo() {
    Escopo *novo_escopo = (Escopo*) malloc(sizeof(Escopo));
    novo_escopo->lista_simbolos = NULL;
    
    // O pai do novo escopo é o escopo que estava ativo até agora
    novo_escopo->escopo_pai = escopo_atual;
    
    // O novo escopo se torna o escopo atual
    escopo_atual = novo_escopo;
}

// Destrói o escopo atual e volta para o pai (chamado ao fechar uma chave '}')
void sair_escopo() {
    if (escopo_atual == NULL) return;

    Escopo *escopo_antigo = escopo_atual;
    
    // Primeiro, liberamos todos os símbolos que foram criados neste escopo
    Simbolo *atual = escopo_antigo->lista_simbolos;
    while (atual != NULL) {
        Simbolo *aux = atual;
        atual = atual->proximo;
        free(aux->nome);
        free(aux->tipo);
        free(aux);
    }
    
    // O escopo atual volta a ser o escopo pai
    escopo_atual = escopo_antigo->escopo_pai;
    
    // Liberamos a estrutura do escopo em si
    free(escopo_antigo);
}

void inserir(char* nome, char *tipo, int linha) {
    
    if (escopo_atual == NULL) {
        entrar_escopo();
    }

    if (buscar_local(nome) != NULL) {
        fprintf(stderr, "Erro Semantico na linha %d: Redeclaracao de '%s' no mesmo escopo.\n", linha, nome);
        exit(1);
    }

    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->linha = linha;
    novo->proximo = escopo_atual->lista_simbolos;
    escopo_atual->lista_simbolos = novo;

    SimboloHistorico* novo_historico = (SimboloHistorico*)malloc(sizeof(SimboloHistorico));
    novo_historico->nome = strdup(nome); 
    novo_historico->tipo = strdup(tipo);
    novo_historico->linha = linha;
    novo_historico->proximo = NULL;

    if (historico_inicio == NULL) {
        historico_inicio = novo_historico;
        historico_fim = novo_historico;
    } else {
        historico_fim->proximo = novo_historico;
        historico_fim = novo_historico;
    }
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

void imprimir_tabela() {
    if (escopo_atual == NULL) {
        fprintf(stderr, "\n--- TABELA DE SÍMBOLOS VAZIA (NENHUM ESCOPO ATIVO) ---\n");
        return;
    }
    
    Simbolo *atual = escopo_atual->lista_simbolos;
    fprintf(stderr, "\n--- CONTEÚDO DO ESCOPO ATUAL ---\n");
    fprintf(stderr, "%-15s | %-15s | %-5s\n", "NOME", "TIPO", "LINHA");
    fprintf(stderr, "--------------------------------------------------\n");
    
    while (atual != NULL) {
        fprintf(stderr, "%-15s | %-15s | %-5d\n", 
               atual->nome, atual->tipo, atual->linha);
        atual = atual->proximo;
    }
    fprintf(stderr, "--------------------------------------------------\n\n");
}

void imprimir_historico_completo() {
    SimboloHistorico* atual = historico_inicio;
    
    fprintf(stderr, "\n==================================================\n");
    fprintf(stderr, "     HISTÓRICO DE TODOS OS SÍMBOLOS PROCESSADOS   \n");
    fprintf(stderr, "==================================================\n");
    fprintf(stderr, "%-20s | %-15s | %-5s\n", "NOME", "TIPO", "LINHA");
    fprintf(stderr, "--------------------------------------------------\n");
    
    if (atual == NULL) {
        fprintf(stderr, "Nenhum símbolo foi processado.\n");
    }

    while (atual != NULL) {
        fprintf(stderr, "%-20s | %-15s | %-5d\n", atual->nome, atual->tipo, atual->linha);
        atual = atual->proximo;
    }
    
    fprintf(stderr, "--------------------------------------------------\n\n");
}