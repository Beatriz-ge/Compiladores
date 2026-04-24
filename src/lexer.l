%option noyywrap
%option yylineno

%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h" 
%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
ID          {LETRA}({LETRA}|{DIGITO})*
NUM         {DIGITO}+(\.{DIGITO}+)?

%%

[ \t\r]+    
\n          

"//".* 

"int"       { return INT; }
"float"     { return FLOAT; }

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