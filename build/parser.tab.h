/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_PARSER_TAB_H_INCLUDED
# define YY_YY_BUILD_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 27 "src/parser.y"

    #include "common.h"
    #include "ast/ast.h"
    #include "semantic.h"

#line 55 "build/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    FLOAT = 259,                   /* FLOAT  */
    CHAR = 260,                    /* CHAR  */
    DOUBLE = 261,                  /* DOUBLE  */
    VOID = 262,                    /* VOID  */
    COMMENT_LINE = 263,            /* COMMENT_LINE  */
    COMMENT_BLOCK = 264,           /* COMMENT_BLOCK  */
    SHORT = 265,                   /* SHORT  */
    LONG = 266,                    /* LONG  */
    SIGNED = 267,                  /* SIGNED  */
    UNSIGNED = 268,                /* UNSIGNED  */
    MAIN = 269,                    /* MAIN  */
    APARENTESE = 270,              /* APARENTESE  */
    FPARENTESE = 271,              /* FPARENTESE  */
    ACHAVE = 272,                  /* ACHAVE  */
    FCHAVE = 273,                  /* FCHAVE  */
    A_COLCHETE = 274,              /* A_COLCHETE  */
    F_COLCHETE = 275,              /* F_COLCHETE  */
    PONTO_VIRGULA = 276,           /* PONTO_VIRGULA  */
    ATRIB = 277,                   /* ATRIB  */
    VIRGULA = 278,                 /* VIRGULA  */
    DOIS_PONTOS = 279,             /* DOIS_PONTOS  */
    SOMA_ATRIB = 280,              /* SOMA_ATRIB  */
    SUB_ATRIB = 281,               /* SUB_ATRIB  */
    MULT_ATRIB = 282,              /* MULT_ATRIB  */
    DIV_ATRIB = 283,               /* DIV_ATRIB  */
    MOD_ATRIB = 284,               /* MOD_ATRIB  */
    IF = 285,                      /* IF  */
    SWITCH = 286,                  /* SWITCH  */
    CASE = 287,                    /* CASE  */
    DEFAULT = 288,                 /* DEFAULT  */
    RETURN = 289,                  /* RETURN  */
    FOR = 290,                     /* FOR  */
    WHILE = 291,                   /* WHILE  */
    DO = 292,                      /* DO  */
    BREAK = 293,                   /* BREAK  */
    CONTINUE = 294,                /* CONTINUE  */
    ELSE = 295,                    /* ELSE  */
    PRINTF = 296,                  /* PRINTF  */
    SCANF = 297,                   /* SCANF  */
    STRUCT = 298,                  /* STRUCT  */
    TYPEDEF = 299,                 /* TYPEDEF  */
    SIZEOF = 300,                  /* SIZEOF  */
    CONST = 301,                   /* CONST  */
    STATIC = 302,                  /* STATIC  */
    TK_EQ = 303,                   /* TK_EQ  */
    TK_NE = 304,                   /* TK_NE  */
    TK_LE = 305,                   /* TK_LE  */
    TK_GE = 306,                   /* TK_GE  */
    TK_LT = 307,                   /* TK_LT  */
    TK_GT = 308,                   /* TK_GT  */
    OR_LOGICO = 309,               /* OR_LOGICO  */
    AND_LOGICO = 310,              /* AND_LOGICO  */
    SOMA = 311,                    /* SOMA  */
    SUB = 312,                     /* SUB  */
    MULT = 313,                    /* MULT  */
    DIV = 314,                     /* DIV  */
    MOD = 315,                     /* MOD  */
    INC = 316,                     /* INC  */
    DEC = 317,                     /* DEC  */
    NOT = 318,                     /* NOT  */
    STR_LITERAL = 319,             /* STR_LITERAL  */
    CHAR_LITERAL = 320,            /* CHAR_LITERAL  */
    NUM = 321,                     /* NUM  */
    ID = 322,                      /* ID  */
    BIT_AND = 323,                 /* BIT_AND  */
    UMINUS = 324,                  /* UMINUS  */
    DEREF = 325,                   /* DEREF  */
    LOWER_THAN_ELSE = 326          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "src/parser.y"

    char* str;
    int   num;
    struct ASTNode* node;
    

#line 150 "build/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_TAB_H_INCLUDED  */
