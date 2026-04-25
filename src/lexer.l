%option noyywrap
%option yylineno
%option nounput
%option noinput

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.tab.h" 
%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
ID          {LETRA}({LETRA}|{DIGITO})*
NUM         {DIGITO}+(\.{DIGITO}+)?

%%

[ \t\r]+    
\n          

"//".* { /* ignora comentário */ }

/* Tipos e Palavras Reservadas */
"int"       { return INT; }
"float"     { return FLOAT; }
"char"      { return CHAR; }

/* Operadores e Pontuação */
";"         { return PONTO_VIRGULA; }
"/"         { return DIV; }

"="         { return ATRIB; }
"+"         { return SOMA; }
"-"         { return SUB; }
"*"         { return MULT; }

{NUM}       { 
                yylval.val = atof(yytext); 
                return NUM; 
            }

{ID}        { 
                yylval.str = strdup(yytext); 
                return ID; 
            }

.           { 
                fprintf(stderr, "Erro Léxico na linha %d: caractere '%s' inválido\n", yylineno, yytext); 
            }

%%
