%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char  ch;
}

%type <str> expressao

/* Precedência para resolver o "Dangling Else" */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%token INT FLOAT CHAR
%token MAIN APARENTESE FPARENTESE ACHAVE FCHAVE
%token PONTO_VIRGULA ATRIB 
%token SOMA_ATRIB SUB_ATRIB MULT_ATRIB DIV_ATRIB MOD_ATRIB
%token IF SWITCH CASE DEFAULT RETURN
%token DOIS_PONTOS
%token DOUBLE SHORT LONG SIGNED UNSIGNED VOID

%token <str> STR_LITERAL
%token <ch>  CHAR_LITERAL
%token <str> NUM
%token <str> ID

%left SOMA SUB
%left MULT DIV MOD

%start program

%%

program:
      MAIN APARENTESE FPARENTESE bloco
    | INT MAIN APARENTESE FPARENTESE bloco
    | VOID MAIN APARENTESE FPARENTESE bloco
;

bloco:
    ACHAVE {
        indent++;
    }
    lista_comandos
    FCHAVE {
        indent--;
    }
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
      tipo_base
    | qualificador tipo_base
    | qualificador
;

tipo_base:
      INT 
    | FLOAT 
    | CHAR
    | DOUBLE
    | VOID
    | SHORT
    | LONG
;

qualificador:
    | SIGNED
    | UNSIGNED
;

declaracao:
      tipo ID PONTO_VIRGULA {
        print_indent();
        printf("%s = None\n", $2);
    }

    | tipo ID ATRIB expressao PONTO_VIRGULA {
        print_indent();
        printf("%s = %s\n", $2, $4);
    }
;

atribuicao:
      ID ATRIB expressao PONTO_VIRGULA {
        print_indent();
        printf("%s = %s\n", $1, $3);
    }

    | ID SOMA_ATRIB expressao PONTO_VIRGULA {
        print_indent();
        printf("%s += %s\n", $1, $3);
    }

    | ID SUB_ATRIB expressao PONTO_VIRGULA {
        print_indent();
        printf("%s -= %s\n", $1, $3);
    }

    | ID MULT_ATRIB expressao PONTO_VIRGULA {
        print_indent();
        printf("%s *= %s\n", $1, $3);
    }

    | ID DIV_ATRIB expressao PONTO_VIRGULA {
        print_indent();
        printf("%s /= %s\n", $1, $3);
    }

    | ID MOD_ATRIB expressao PONTO_VIRGULA {
        print_indent();
        printf("%s %%= %s\n", $1, $3);
    }
;

selecao:
      /* Caso: if sem else */
      if_header comando %prec LOWER_THAN_ELSE {
          indent--;
      }
      /* Caso: if com else */
    | if_header comando ELSE {
          indent--; 
          print_indent();
          printf("else:\n");
          indent++;
      } 
      comando {
          indent--;
      }
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
      NUM                { $$ = strdup($1); }
    | ID                 { $$ = strdup($1); }

    | CHAR_LITERAL {
        char temp[2];
        temp[0] = $1;
        temp[1] = '\0';
        $$ = strdup(temp);
    }

    | STR_LITERAL      { $$ = strdup($1); }

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

    | APARENTESE expressao FPARENTESE {
        asprintf(&$$, "(%s)", $2);
    }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d perto de '%s'\n", yylineno, yytext);
    exit(1);
}