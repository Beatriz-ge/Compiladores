%{
#include <stdio.h>
#include <stdlib.h>
%}

DIGITO      [0-9]
LETRA       [a-zA-Z]
ID          {LETRA}({LETRA}|{DIGITO})*
NUM         {DIGITO}+

%%
[ \t\n]+            ;

"=" { printf("ATRIBUICAO (=)\n"); }
"+" { printf("SOMA (+)\n"); }
"-" { printf("SUBTRACAO (-)\n"); }
"*" { printf("MULTIPLICACAO (*)\n"); }
"/" { printf("DIVISAO (/)\n"); }

{NUM} { printf("NUMERO: %s\n", yytext); }
{ID}  { printf("IDENTIFICADOR: %s\n", yytext); }

. { printf("INVÁLIDO: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}