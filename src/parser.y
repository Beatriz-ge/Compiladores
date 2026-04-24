%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

/* 1. Aqui resolvemos o erro do 'val' e 'str' */
%union {
    float val;      /* Para o NUM */
    char* str;      /* Para o ID */
}

/* 2. Aqui definimos os nomes que o Lexer vai usar */
%token INT FLOAT
%token <val> NUM
%token <str> ID

%%

/* 3. Uma gramática simples só para o compilador aceitar algo por enquanto */
program:
    expressao { printf("Comando reconhecido com sucesso!\n"); }
    ;

expressao:
    INT ID          { printf("Declaração de inteiro: %s\n", $2); }
    | FLOAT ID      { printf("Declaração de float: %s\n", $2); }
    | ID '=' NUM    { printf("Atribuição: %s recebe %f\n", $1, $3); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático na linha: %s\n", s);
}