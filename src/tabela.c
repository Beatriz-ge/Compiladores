#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

// Esta variável global agora controla o escopo que está ativo no momento
Escopo *escopo_atual = NULL;

// Cria um novo escopo (chamado ao abrir uma chave '{')
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

// Insere um símbolo APENAS no escopo que está ativo no momento
void inserir(char *nome, char *tipo, int linha) {
    // Se por acaso não houver escopo ativo (ex: variáveis globais antes de qualquer função),
    // criamos o escopo global automaticamente.
    if (escopo_atual == NULL) {
        entrar_escopo();
    }

    // Opcional: Validar se a variável já existe NO MESMO ESCOPO (Erro de redeclaração)
    if (buscar_local(nome) != NULL) {
        fprintf(stderr, "Erro Semantico na linha %d: Redeclaracao de '%s' no mesmo escopo.\n", linha, nome);
        exit(1);
    }

    Simbolo *novo = (Simbolo*) malloc(sizeof(Simbolo));
    novo->nome = strdup(nome);
    novo->tipo = strdup(tipo);
    novo->linha = linha;
    
    // Insere no topo da lista de símbolos do escopo atual
    novo->proximo = escopo_atual->lista_simbolos;
    escopo_atual->lista_simbolos = novo;
}

// Busca um símbolo do escopo atual subindo até o escopo global (Regra de Escopo do C)
Simbolo* buscar(char *nome) {
    Escopo *escopo_varredura = escopo_atual;
    
    // Navega subindo pelos escopos pais
    while (escopo_varredura != NULL) {
        Simbolo *atual = escopo_varredura->lista_simbolos;
        
        // Procura na lista de símbolos do escopo que está sendo analisado no laço
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) {
                return atual; // Achou! Pode ser local ou de um pai/global
            }
            atual = atual->proximo;
        }
        
        // Se não achou neste escopo, sobe para o pai
        escopo_varredura = escopo_varredura->escopo_pai;
    }
    
    return NULL; // Não achou em escopo nenhum (variável não declarada)
}

// Busca uma variável APENAS no escopo atual (útil para detectar redeclarações legítimas)
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

// Imprime os símbolos pertencentes APENAS ao escopo atual
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