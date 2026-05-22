%option noyywrap
%option yylineno
%option nounput
%option noinput

%{
#include "parser.tab.h"
#include "common.h"
#include "tabela.h"
%}

DIGITO      [0-9]
LETRA       [a-zA-Z_]
ID          {LETRA}({LETRA}|{DIGITO})*
NUM         {DIGITO}+(\.{DIGITO}+)?
ESCAPE      \\[ntr0"'\\]

%%

[ \t\r]+    { /* ignora */ }
\n          { /* ignora */ }
"//".* {
    yylval.str = strdup(yytext);
    return COMMENT_LINE;
}

\/\*([^*]|\*+[^*/])*\*\/ {
    yylval.str = strdup(yytext);
    return COMMENT_BLOCK;
}

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

"while"     { return WHILE; }
"for"       { return FOR; }
"do"        { return DO; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }

"struct"    { return STRUCT; }
"typedef"   { return TYPEDEF; }
"sizeof"    { return SIZEOF; }
"const"     { return CONST; }
"static"    { return STATIC; }

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
"!"         { return NOT; }
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

\"([^\"\\\n]|\\.)*\n {
    yylineno--;
    fprintf(stderr, "Erro Lexico na linha %d: string nao fechada\n", yylineno);
    exit(1);
}

\"([^\"\\\n]|{ESCAPE})*\\[^ntr0\"\'\\][^\"\n]*\" {

    fprintf(stderr, "Erro Lexico na linha %d: escape invalido em string\n", yylineno);
    exit(1);
}

\"([^\"\\\n]|{ESCAPE})*\" {
    int len = strlen(yytext);
    yylval.str = (char*) malloc(len - 1);
    memcpy(yylval.str, yytext + 1, len - 2);
    yylval.str[len - 2] = '\0';
    return STR_LITERAL;
}

\'([^\'\\]|\\.)?\n {
    yylineno--;
    fprintf(stderr, "Erro Lexico na linha %d: char nao fechado\n", yylineno);
    exit(1);
}

\'\\[^ntr0\'\\]\' {

    fprintf(stderr, "Erro Lexico na linha %d: escape invalido em char\n", yylineno);
    exit(1);
}

\'([^\'\\]|{ESCAPE})\' {
    int len = strlen(yytext);
    yylval.str = (char*) malloc(len - 1);
    memcpy(yylval.str, yytext + 1, len - 2);
    yylval.str[len - 2] = '\0';
    return CHAR_LITERAL;
}

\'([^\'\\]|\\.){2,}\' {
    fprintf(stderr, "Erro Lexico na linha %d: char invalido\n", yylineno);
    exit(1);
}


{NUM}       { yylval.str = strdup(yytext); return NUM; }
{ID}        { yylval.str = strdup(yytext); return ID; }

. {
    fprintf(stderr, "Erro lexico na linha %d: '%s'\n", yylineno, yytext);
    exit(1);
}

%%