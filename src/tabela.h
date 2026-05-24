#ifndef TABELA_H
#define TABELA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um símbolo individual
typedef struct Simbolo {
    char *nome;
    char *tipo;      
    int linha;       
    struct Simbolo *proximo;
} Simbolo;

// Estrutura de um Escopo (uma tabela local que aponta para o seu escopo pai)
typedef struct Escopo {
    Simbolo *lista_simbolos;     // Lista ligada de símbolos DESTE escopo
    struct Escopo *escopo_pai;   // Ponteiro para o escopo que engloba este
} Escopo;

// Funções de gerenciamento de escopo
void entrar_escopo();
void sair_escopo();

// Funções de manipulação de símbolos
void inserir(char *nome, char *tipo, int linha);
Simbolo* buscar(char *nome);
Simbolo* buscar_local(char *nome); // Auxiliar para evitar redeclaração no mesmo bloco

void imprimir_tabela();

#endif