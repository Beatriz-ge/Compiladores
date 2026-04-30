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
ESCAPE      \\.

%%

[ \t\r]+    { /* ignora */ }
\n          { /* ignora */ }
"//".* { /* ignora comentário */ }

"main"      { return MAIN; }
"int"       { return INT; }
"float"     { return FLOAT; }
"char"      { return CHAR; }
"if"        { return IF; }
"else"      { return ELSE; }
"switch"    { return SWITCH; }
"case"      { return CASE; }
"default"   { return DEFAULT; }
"return"    { return RETURN; }

"("         { return APARENTESE; }
")"         { return FPARENTESE; }
"{"         { return ACHAVE; }
"}"         { return FCHAVE; }
";"         { return PONTO_VIRGULA; }
":"         { return DOIS_PONTOS; }

\"([^\"\\\n]|{ESCAPE})*\" {
    int len = strlen(yytext) - 2;
    yylval.str = (char*) malloc(len + 1);
    memcpy(yylval.str, yytext + 1, len);
    yylval.str[len] = '\0';
    return STR_LITERAL;
}

\"([^\"\\\n]|{ESCAPE})*\n {
    fprintf(stderr, "Erro Lexico na linha %d: string nao fechada\n", yylineno);
}

\'([^\'\\]|{ESCAPE})\' {
    // Como no Python char e string são parecidos, vamos passar como string de 1 char
    char c;
    if (yytext[1] == '\\') {
        switch (yytext[2]) {
            case 'n':  c = '\n'; break;
            case 't':  c = '\t'; break;
            case 'r':  c = '\r'; break;
            case '\\': c = '\\'; break;
            case '\'': c = '\''; break;
            case '0':  c = '\0'; break;
            default:   c = yytext[2]; break;
        }
    } else {
        c = yytext[1];
    }
    yylval.str = (char*) malloc(2);
    yylval.str[0] = c;
    yylval.str[1] = '\0';
    return CHAR_LITERAL;
}

\'([^\'\\]|{ESCAPE})?\n {
    fprintf(stderr, "Erro Lexico na linha %d: char nao fechado\n", yylineno);
}

\'([^\'\\]|{ESCAPE})+\' {
    fprintf(stderr, "Erro Lexico na linha %d: char invalido\n", yylineno);
}

"+="        { return SOMA_ATRIB; }
"-="        { return SUB_ATRIB; }
"*="        { return MULT_ATRIB; }
"/="        { return DIV_ATRIB; }
"%="        { return MOD_ATRIB; }
"/"         { return DIV; }
"="         { return ATRIB; }
"+"         { return SOMA; }
"-"         { return SUB; }
"*"         { return MULT; }
"%"         { return MOD; }

{NUM}       { yylval.str = strdup(yytext); return NUM; }
{ID}        { yylval.str = strdup(yytext); return ID; }

. {
    fprintf(stderr, "Erro lexico na linha %d: '%s'\n", yylineno, yytext);
    exit(1);
}

%%