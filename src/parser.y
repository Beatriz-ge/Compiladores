%token INT FLOAT CHAR
%token PONTO_VIRGULA DIV ATRIB SOMA SUB MULT
%token MAIN APARENTESE FPARENTESE ACHAVE FCHAVE
%token <val> NUM
%token <str> ID

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

/* Regra 1: O ponto de entrada agora é o main */
program:
    MAIN APARENTESE FPARENTESE bloco
    ;

/* Regra 2: Um bloco é algo entre { } que tem comandos dentro */
bloco:
    ACHAVE lista_expressoes FCHAVE
    ;

lista_expressoes:
      /* vazio */
    | lista_expressoes expressao
    ;

expressao:
      INT ID PONTO_VIRGULA     { printf("Declarou int\n"); }
    | ID ATRIB NUM PONTO_VIRGULA { printf("Atribuiu valor\n"); }
    | bloco                    { /* Aqui permite { { } } */ }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático: %s\n", s);
}