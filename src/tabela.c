#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

Simbolo *tabela_simbolos = NULL;

void inserir(char *nome, char *tipo, int escopo, int linha) {
    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->escopo = escopo;
    novo->linha = linha;
    
    novo->proximo = tabela_simbolos;
    tabela_simbolos = novo;
}

Simbolo* buscar(char *nome) {
    Simbolo *atual = tabela_simbolos;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual; 
        }
        atual = atual->proximo;
    }
    return NULL; 
}

void remover_escopo(int escopo) {
    while (tabela_simbolos != NULL && tabela_simbolos->escopo == escopo) {
        Simbolo *aux = tabela_simbolos;
        tabela_simbolos = tabela_simbolos->proximo;
        free(aux->nome);
        free(aux->tipo);
        free(aux);
    }
}