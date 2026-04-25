%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

/* Tipos semânticos */
%union {
    float val;
    char* str;
}

/* Tokens */
%token INT FLOAT
%token <val> NUM
%token <str> ID

%start program
%%

/* Regra inicial (programa completo) */
program:
    lista_expressoes
    ;

lista_expressoes:
      /* vazio */
    | lista_expressoes expressao
    ;

expressao:
      INT ID ';'        { printf("Declaração de inteiro: %s\n", $2); }
    | FLOAT ID ';'      { printf("Declaração de float: %s\n", $2); }
    | ID '=' NUM ';'    { printf("Atribuição: %s recebe %f\n", $1, $3); }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}