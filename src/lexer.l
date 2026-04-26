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

[ \t\r]+    { /* ignora */ }
\n          { /* ignora */ }

"//".* { /* ignora comentário */ }

"main"      { return MAIN; }
"("         { return APARENTESE; }
")"         { return FPARENTESE; }
"{"         { return ACHAVE; }
"}"         { return FCHAVE; }

"int"       { return INT; }
"float"     { return FLOAT; }
"char"      { return CHAR; }

"+="        { return SOMA_ATRIB; }
"-="        { return SUB_ATRIB; }
"*="        { return MULT_ATRIB; }
"/="        { return DIV_ATRIB; }
"%="        { return MOD_ATRIB; }

";"         { return PONTO_VIRGULA; }
"/"         { return DIV; }
"="         { return ATRIB; }
"+"         { return SOMA; }
"-"         { return SUB; }
"*"         { return MULT; }
"%"         { return MOD; }

{NUM}       { 
                yylval.val = atof(yytext); 
                return NUM; 
            }

{ID}        { 
                yylval.str = strdup(yytext); 
                return ID; 
            }

.           { 
                fprintf(stderr, "Erro Lexico na linha %d: caractere '%s' invalido\n", yylineno, yytext); 
            }

%%