%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
extern int yylineno;
extern char *yytext;
%}

%union {
    float val;
    char* str;
    char  ch;
}

%token INT FLOAT CHAR
%token MAIN APARENTESE FPARENTESE ACHAVE FCHAVE
%token PONTO_VIRGULA ATRIB 
%token SOMA_ATRIB SUB_ATRIB MULT_ATRIB DIV_ATRIB MOD_ATRIB
%token IF ELSE SWITCH CASE DEFAULT RETURN
%token DOIS_PONTOS

%token <str>  STR_LITERAL
%token <ch>   CHAR_LITERAL
%token <val>  NUM
%token <str>  ID

%left SOMA SUB
%left MULT DIV MOD

%start program

%%

program:
      MAIN APARENTESE FPARENTESE bloco
    | INT MAIN APARENTESE FPARENTESE bloco
;

bloco:
    ACHAVE lista_comandos FCHAVE
;

lista_comandos:
      /* vazio */
    | lista_comandos comando
;

comando:
      declaracao
    | atribuicao
    | selecao
    | retorno
    | bloco
;

tipo: 
      INT 
    | FLOAT 
    | CHAR
;

declaracao:
      tipo ID PONTO_VIRGULA 
    | tipo ID ATRIB expressao PONTO_VIRGULA 
;

atribuicao:
      ID ATRIB expressao PONTO_VIRGULA
    | ID SOMA_ATRIB expressao PONTO_VIRGULA
    | ID SUB_ATRIB expressao PONTO_VIRGULA
    | ID MULT_ATRIB expressao PONTO_VIRGULA
    | ID DIV_ATRIB expressao PONTO_VIRGULA
    | ID MOD_ATRIB expressao PONTO_VIRGULA
;

selecao:
      IF APARENTESE expressao FPARENTESE comando
    | IF APARENTESE expressao FPARENTESE comando ELSE comando
    | SWITCH APARENTESE expressao FPARENTESE ACHAVE lista_cases FCHAVE
;

lista_cases:
      lista_cases case
    | case
;

case:
      CASE NUM DOIS_PONTOS lista_comandos
    | DEFAULT DOIS_PONTOS lista_comandos
;

retorno:
    RETURN expressao PONTO_VIRGULA
;

expressao:
      NUM
    | ID
    | CHAR_LITERAL
    | STR_LITERAL
    | expressao SOMA expressao
    | expressao SUB expressao
    | expressao MULT expressao
    | expressao DIV expressao
    | expressao MOD expressao
    | APARENTESE expressao FPARENTESE
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d perto de '%s'\n", yylineno, yytext);
    exit(1);
}