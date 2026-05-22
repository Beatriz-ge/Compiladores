#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast/ast.h" 

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

extern ASTNode* global_ast_root; 

int yylex(void);
void yyerror(const char *s);

extern int indent;
void print_indent(void);

#endif