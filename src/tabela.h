#ifndef TABELA_H
#define TABELA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Simbolo {
    char *nome;
    char *tipo;      
    int linha;       
    struct Simbolo *proximo;
} Simbolo;

typedef struct Escopo {
    Simbolo *lista_simbolos;     
    struct Escopo *escopo_pai;   
} Escopo;

void entrar_escopo();
void sair_escopo();

void inserir(char *nome, char *tipo, int linha);
Simbolo* buscar(char *nome);
Simbolo* buscar_local(char *nome); 

void imprimir_historico_completo();
void imprimir_tabela();

#endif