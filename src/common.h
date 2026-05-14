#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Variáveis globais do Flex/Bison */
extern int yylineno;
extern char *yytext;
extern FILE *yyin;

/* Funções do parser/lexer */
int yylex(void);
void yyerror(const char *s);

/* Controle de indentação */
extern int indent;
void print_indent(void);

#endif