%option noyywrap
%option yylineno
%option nounput
%option noinput

%{
#include "parser.tab.h"
#include "common.h"
#include "tabela.h"
#include "diagnostics.h"
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

"#include"[ \t]*"<string.h>"    { return INCLUDE_STRING_H; }

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

"printf"    { return PRINTF; }
"scanf"     { return SCANF; }

"for"       { return FOR; }
"while"     { return WHILE; }
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
"&"         { return BIT_AND; }


\"([^\"\\\n]|\\.)*\n {
    yylineno--;
    char msg[512];
    if (yytext[strlen(yytext)-1] == '\n') yytext[strlen(yytext)-1] = '\0';
    snprintf(msg, sizeof(msg), "String nao fechada com aspas antes do fim da linha.\nTexto encontrado: %s", yytext);
    emitir_erro_lexico(yylineno, msg);
    exit(1);
}

\"([^\"\\\n]|{ESCAPE})*\\[^ntr0\"\'\\][^\"\n]*\" {
    char msg[512];
    snprintf(msg, sizeof(msg), "Sequencia de escape invalida dentro da string.\nTexto encontrado: %s", yytext);
    emitir_erro_lexico(yylineno, msg);
    exit(1);
}

\"([^\"\\\n]|{ESCAPE})*\" {
    /* REGRA DE SUCESSO DA STRING - MANTIDA! */
    int len = strlen(yytext);
    yylval.str = (char*) malloc(len - 1);
    memcpy(yylval.str, yytext + 1, len - 2);
    yylval.str[len - 2] = '\0';
    return STR_LITERAL;
}

\'([^\'\\]|\\.)?\n {
    yylineno--;
    char msg[512];
    if (yytext[strlen(yytext)-1] == '\n') yytext[strlen(yytext)-1] = '\0';
    snprintf(msg, sizeof(msg), "Constante de caractere (char) nao fechada antes do fim da linha.\nTexto encontrado: %s", yytext);
    emitir_erro_lexico(yylineno, msg);
    exit(1);
}

\'\\[^ntr0\'\\]\' {
    char msg[512];
    snprintf(msg, sizeof(msg), "Sequencia de escape invalida dentro do char.\nTexto encontrado: %s", yytext);
    emitir_erro_lexico(yylineno, msg);
    exit(1);
}

\'([^\'\\]|{ESCAPE})\' {
    /* REGRA DE SUCESSO DO CHAR - MANTIDA! */
    int len = strlen(yytext);
    yylval.str = (char*) malloc(len - 1);
    memcpy(yylval.str, yytext + 1, len - 2);
    yylval.str[len - 2] = '\0';
    return CHAR_LITERAL;
}

\'([^\'\\]|\\.){2,}\' {
    char msg[512];
    snprintf(msg, sizeof(msg), "Constante de caractere invalida (char deve conter apenas 1 caractere).\nTexto encontrado: %s", yytext);
    emitir_erro_lexico(yylineno, msg);
    exit(1);
}


{NUM}       { yylval.str = strdup(yytext); return NUM; }
{ID}        { yylval.str = strdup(yytext); return ID; }

. {
    char msg[256];
    snprintf(msg, sizeof(msg), "Caractere desconhecido/invalido que nao pertence a linguagem C.\nTexto encontrado: %s", yytext);
    emitir_erro_lexico(yylineno, msg);
    exit(1);
}

%%