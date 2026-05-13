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
}

%type <str> expressao lista_ids

%token INT FLOAT CHAR DOUBLE VOID
%token MAIN APARENTESE FPARENTESE ACHAVE FCHAVE A_COLCHETE F_COLCHETE
%token PONTO_VIRGULA ATRIB VIRGULA DOIS_PONTOS
%token SOMA_ATRIB SUB_ATRIB MULT_ATRIB DIV_ATRIB MOD_ATRIB
%token IF ELSE SWITCH CASE DEFAULT RETURN
%token AND_LOGICO OR_LOGICO INC DEC
%token TK_EQ TK_NE TK_LE TK_GE TK_LT TK_GT

%token <str> STR_LITERAL CHAR_LITERAL NUM ID

/* Precedência (da menor para a maior) */
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
    FCHAVE { indent--; }
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
      INT | FLOAT | CHAR | DOUBLE | VOID
;

/* Suporte para int a, b, c; */
lista_ids:
      ID { 
        print_indent();
        printf("%s = None\n", $1); 
      }
    | lista_ids VIRGULA ID { 
        print_indent();
        printf("%s = None\n", $3); 
      }
;

declaracao:
      tipo lista_ids PONTO_VIRGULA 
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
    | ID INC PONTO_VIRGULA {
        print_indent();
        printf("%s += 1\n", $1);
    }
    | ID DEC PONTO_VIRGULA {
        print_indent();
        printf("%s -= 1\n", $1);
    }
    | ID SUB_ATRIB expressao PONTO_VIRGULA { print_indent(); printf("%s -= %s\n", $1, $3); }
    | ID MULT_ATRIB expressao PONTO_VIRGULA { print_indent(); printf("%s *= %s\n", $1, $3); }
    | ID DIV_ATRIB expressao PONTO_VIRGULA { print_indent(); printf("%s /= %s\n", $1, $3); }
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
      NUM                { $$ = strdup($1); }
    | ID                 { $$ = strdup($1); }
    | STR_LITERAL        { asprintf(&$$, "\"%s\"", $1); }
    | CHAR_LITERAL       { asprintf(&$$, "'%s'", $1); }
    
    /* Acesso a Array */
    | ID A_COLCHETE expressao F_COLCHETE {
        asprintf(&$$, "%s[%s]", $1, $3);
    }

    /* Operadores Lógicos traduzidos para Python */
    | expressao AND_LOGICO expressao { asprintf(&$$, "%s and %s", $1, $3); }
    | expressao OR_LOGICO expressao  { asprintf(&$$, "%s or %s", $1, $3); }
    
    /* Operadores Relacionais */
    | expressao TK_EQ expressao { asprintf(&$$, "%s == %s", $1, $3); }
    | expressao TK_LT expressao { asprintf(&$$, "%s < %s", $1, $3); }
    | expressao TK_GT expressao { asprintf(&$$, "%s > %s", $1, $3); }

    /* Aritmética */
    | expressao SOMA expressao { asprintf(&$$, "%s + %s", $1, $3); }
    | expressao SUB expressao  { asprintf(&$$, "%s - %s", $1, $3); }
    | expressao MULT expressao { asprintf(&$$, "%s * %s", $1, $3); }
    | expressao DIV expressao  { asprintf(&$$, "%s / %s", $1, $3); }
    
    /* Unários em Expressões (Tradução aproximada) */
    | ID INC { asprintf(&$$, "(%s + 1)", $1); }
    | ID DEC { asprintf(&$$, "(%s - 1)", $1); }

    | APARENTESE expressao FPARENTESE { asprintf(&$$, "(%s)", $2); }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d perto de '%s'\n", yylineno, yytext);
    exit(1);
}

int main() {
    yyparse();
    return 0;
}