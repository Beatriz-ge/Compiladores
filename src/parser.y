%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

void yyerror(const char *s);
int yylex();
extern int yylineno;
extern char *yytext;

int indent = 0;

void print_indent() {
    for (int i = 0; i < indent; i++) {
        printf("    ");
    }
}
%}

%union {
    char* str;
}

/* Ajuste: 'tipo' agora retorna string para podermos salvar na tabela */
%type <str> expressao lista_ids tipo 

%token INT FLOAT CHAR DOUBLE VOID
%token MAIN APARENTESE FPARENTESE ACHAVE FCHAVE A_COLCHETE F_COLCHETE
%token PONTO_VIRGULA ATRIB VIRGULA DOIS_PONTOS
%token SOMA_ATRIB SUB_ATRIB MULT_ATRIB DIV_ATRIB MOD_ATRIB

%token IF SWITCH CASE DEFAULT RETURN
%token FOR WHILE DO BREAK CONTINUE
%token ELSE

%token DOIS_PONTOS
%token DOUBLE SHORT LONG SIGNED UNSIGNED VOID

%token <str> STR_LITERAL
%token <str>  CHAR_LITERAL
%token TK_EQ TK_NE TK_LE TK_GE TK_LT TK_GT

%token <str> STR_LITERAL CHAR_LITERAL NUM ID

/* Precedência */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%left OR_LOGICO
%left AND_LOGICO
%left TK_EQ TK_NE
%left TK_LT TK_GT TK_LE TK_GE
%left SOMA SUB
%left MULT DIV MOD
%right INC DEC 

%start program

%%

program:
      MAIN APARENTESE FPARENTESE bloco
    | INT MAIN APARENTESE FPARENTESE bloco
    | tipo MAIN APARENTESE FPARENTESE bloco
;

bloco:
    ACHAVE { indent++; }
    lista_comandos
    FCHAVE { 
        remover_escopo(indent); 
        indent--; 
    }
;

lista_comandos:
    | lista_comandos comando
;

comando:
      declaracao
    | atribuicao
    | selecao
    | retorno
    | bloco
    | expressao PONTO_VIRGULA 
;

tipo: 
      INT    { $$ = "int"; }
    | FLOAT  { $$ = "float"; }
    | CHAR   { $$ = "char"; }
    | DOUBLE { $$ = "double"; }
    | VOID   { $$ = "void"; }
;

lista_ids:
      ID { 
        if (buscar($1) != NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' ja declarada.\n", yylineno, $1);
            exit(1);
        }
        inserir($1, "desconhecido", indent, yylineno); 
        print_indent();
        printf("%s = None\n", $1); 
      }
    | lista_ids VIRGULA ID { 
        if (buscar($3) != NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' ja declarada.\n", yylineno, $3);
            exit(1);
        }
        inserir($3, "desconhecido", indent, yylineno);
        print_indent();
        printf("%s = None\n", $3); 
      }
;

declaracao:
      tipo lista_ids PONTO_VIRGULA 
    | tipo ID ATRIB expressao PONTO_VIRGULA {
        if (buscar($2) != NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' ja declarada.\n", yylineno, $2);
            exit(1);
        }
        inserir($2, $1, indent, yylineno);
        print_indent();
        printf("%s = %s\n", $2, $4);
    }
;

atribuicao:
      ID ATRIB expressao PONTO_VIRGULA {
        if (buscar($1) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1);
            exit(1);
        }
        print_indent();
        printf("%s = %s\n", $1, $3);
    }
    | ID SOMA_ATRIB expressao PONTO_VIRGULA {
        if (buscar($1) == NULL) { 
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1); 
            exit(1); 
        }
        print_indent();
        printf("%s += %s\n", $1, $3);
    }
    | ID SUB_ATRIB expressao PONTO_VIRGULA { 
        if (buscar($1) == NULL) { 
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1); 
            exit(1); 
        }
        print_indent(); 
        printf("%s -= %s\n", $1, $3); 
    }
    | ID MULT_ATRIB expressao PONTO_VIRGULA { 
        if (buscar($1) == NULL) { 
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1); 
            exit(1); 
        }
        print_indent(); 
        printf("%s *= %s\n", $1, $3); 
    }
    | ID DIV_ATRIB expressao PONTO_VIRGULA { 
        if (buscar($1) == NULL) { 
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1); 
            exit(1); 
        }
        print_indent(); 
        printf("%s /= %s\n", $1, $3); 
    }
    | ID MOD_ATRIB expressao PONTO_VIRGULA { 
        if (buscar($1) == NULL) { 
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1); 
            exit(1); 
        }
        print_indent(); 
        printf("%s %%= %s\n", $1, $3); 
    }
    | ID INC PONTO_VIRGULA {
        if (buscar($1) == NULL) { 
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1); 
            exit(1); 
        }
        print_indent();
        printf("%s += 1\n", $1);
    }
    | ID DEC PONTO_VIRGULA {
        if (buscar($1) == NULL) { 
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1); 
            exit(1); 
        }
        print_indent();
        printf("%s -= 1\n", $1);
    }
;

selecao:
      if_header comando %prec LOWER_THAN_ELSE { indent--; }
    | if_header comando ELSE {
          indent--; 
          print_indent();
          printf("else:\n");
          indent++;
      } 
      comando { indent--; }
;

if_header:
    IF APARENTESE expressao FPARENTESE {
        print_indent();
        printf("if %s:\n", $3);
        indent++;
    };

retorno:
    RETURN expressao PONTO_VIRGULA {
        print_indent();
        printf("return %s\n", $2);
    }
;

expressao:
      NUM {
        $$ = strdup($1);
    }

    | ID {
        $$ = strdup($1);
    }


    | STR_LITERAL {
        asprintf(&$$, "\"%s\"", $1);
    }

    | CHAR_LITERAL {
        asprintf(&$$, "'%s'", $1);
    }

    | expressao SOMA expressao {
        asprintf(&$$, "%s + %s", $1, $3);
    }

    | expressao SUB expressao {
        asprintf(&$$, "%s - %s", $1, $3);
    }

    | expressao MULT expressao {
        asprintf(&$$, "%s * %s", $1, $3);
    }

    | expressao DIV expressao {
        asprintf(&$$, "%s / %s", $1, $3);
    }

    | expressao MOD expressao {
        asprintf(&$$, "%s %% %s", $1, $3);
    }

    | expressao TK_EQ expressao {
        asprintf(&$$, "%s == %s", $1, $3);
    }

    | expressao TK_NE expressao {
        asprintf(&$$, "%s != %s", $1, $3);
    }

    | expressao TK_LE expressao {
        asprintf(&$$, "%s <= %s", $1, $3);
    }

    | expressao TK_GE expressao {
        asprintf(&$$, "%s >= %s", $1, $3);
    }

    | expressao TK_LT expressao {
        asprintf(&$$, "%s < %s", $1, $3);
    }

    | expressao TK_GT expressao {
        asprintf(&$$, "%s > %s", $1, $3);
    }

    | APARENTESE expressao FPARENTESE {
        asprintf(&$$, "(%s)", $2);
    }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d perto de '%s'\n", yylineno, yytext);
    exit(1);
}