%option noyywrap
%option yylineno
%option nounput
%option noinput

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
ID          {LETRA}({LETRA}|{DIGITO})*
NUM         {DIGITO}+(\.{DIGITO}+)?
ESCAPE      \\.

%%

[ \t\r]+    { /* ignora */ }
\n          { /* ignora */ }
"//".*      { /* ignora comentário */ }

"main"      { printf("[MAIN]\n"); }
"int"       { printf("[INT]\n"); }
"float"     { printf("[FLOAT]\n"); }
"char"      { printf("[CHAR]\n"); }
"("         { printf("[APARENTESE]\n"); }
")"         { printf("[FPARENTESE]\n"); }
"{"         { printf("[ACHAVE]\n"); }
"}"         { printf("[FCHAVE]\n"); }

\"([^\"\\\n]|{ESCAPE})*\" {
    printf("[STR_LITERAL] -> %s\n", yytext);
}

\"([^\"\\\n]|{ESCAPE})*\n {
    printf("[ERRO linha %d] string nao fechada\n", yylineno);
}

\'([^\'\\]|{ESCAPE})\' {
    printf("[CHAR_LITERAL] -> %s\n", yytext);
}

\'([^\'\\]|{ESCAPE})?\n {
    fprintf(stderr, "[ERRO linha %d] char nao fechado\n", yylineno);
}

\'([^\'\\]|{ESCAPE})+\' {
    printf("[ERRO linha %d] char invalido (mais de um caractere)\n", yylineno);
}

"+="    { printf("[SOMA_ATRIB]\n"); }
"-="    { printf("[SUB_ATRIB]\n"); }
"*="    { printf("[MULT_ATRIB]\n"); }
"/="    { printf("[DIV_ATRIB]\n"); }
"%="    { printf("[MOD_ATRIB]\n"); }

"="     { printf("[ATRIB]\n"); }
"+"     { printf("[SOMA]\n"); }
"-"     { printf("[SUB]\n"); }
"*"     { printf("[MULT]\n"); }
"/"     { printf("[DIV]\n"); }
"%"     { printf("[MOD]\n"); }
";"     { printf("[PONTO_VIRGULA]\n"); }

{NUM}   { printf("[NUM] -> %s\n", yytext); }
{ID}    { printf("[ID] -> %s\n", yytext); }

.       { printf("[ERRO linha %d] caractere invalido '%s'\n", yylineno, yytext); }

%%

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Erro ao abrir: %s\n", argv[1]);
            return 1;
        }
    }
    yylex();
    return 0;
}