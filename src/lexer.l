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
"double"    { return DOUBLE; }
"void"      { return VOID; }

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
"["         { return A_COLCHETE; }
"]"         { return F_COLCHETE; }
";"         { return PONTO_VIRGULA; }
":"         { return DOIS_PONTOS; }
","         { return VIRGULA; }

"&&"        { return AND_LOGICO; }
"||"        { return OR_LOGICO; }
"++"        { return INC; }
"--"        { return DEC; }

"=="        { return TK_EQ; }
"!="        { return TK_NE; }
"<="        { return TK_LE; }
">="        { return TK_GE; }
"<"         { return TK_LT; }
">"         { return TK_GT; }

"+="        { return SOMA_ATRIB; }
"-="        { return SUB_ATRIB; }
"*="        { return MULT_ATRIB; }
"/="        { return DIV_ATRIB; }
"%="        { return MOD_ATRIB; }
"="         { return ATRIB; }
"+"         { return SOMA; }
"-"         { return SUB; }
"*"         { return MULT; }
"/"         { return DIV; }
"%"         { return MOD; }

\"([^\"\\\n]|{ESCAPE})*\" {
    int len = strlen(yytext) - 2;
    yylval.str = (char*) malloc(len + 1);
    memcpy(yylval.str, yytext + 1, len);
    yylval.str[len] = '\0';
    return STR_LITERAL;
}

\'([^\'\\]|{ESCAPE})\' {
    char c;
    if (yytext[1] == '\\') {
        switch (yytext[2]) {
            case 'n':  c = '\n'; break;
            case 't':  c = '\t'; break;
            case 'r':  c = '\r'; break;
            case '\\': c = '\\'; break;
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

{NUM}       { yylval.str = strdup(yytext); return NUM; }
{ID}        { yylval.str = strdup(yytext); return ID; }

. {
    fprintf(stderr, "Erro lexico na linha %d: '%s'\n", yylineno, yytext);
    exit(1);
}

%%