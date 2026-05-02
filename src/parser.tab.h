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

#ifndef YY_YY_SRC_PARSER_TAB_H_INCLUDED
# define YY_YY_SRC_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LOWER_THAN_ELSE = 258,         /* LOWER_THAN_ELSE  */
    ELSE = 259,                    /* ELSE  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    CHAR = 262,                    /* CHAR  */
    MAIN = 263,                    /* MAIN  */
    APARENTESE = 264,              /* APARENTESE  */
    FPARENTESE = 265,              /* FPARENTESE  */
    ACHAVE = 266,                  /* ACHAVE  */
    FCHAVE = 267,                  /* FCHAVE  */
    PONTO_VIRGULA = 268,           /* PONTO_VIRGULA  */
    ATRIB = 269,                   /* ATRIB  */
    SOMA = 270,                    /* SOMA  */
    SUB = 271,                     /* SUB  */
    MULT = 272,                    /* MULT  */
    DIV = 273,                     /* DIV  */
    MOD = 274,                     /* MOD  */
    SOMA_ATRIB = 275,              /* SOMA_ATRIB  */
    SUB_ATRIB = 276,               /* SUB_ATRIB  */
    MULT_ATRIB = 277,              /* MULT_ATRIB  */
    DIV_ATRIB = 278,               /* DIV_ATRIB  */
    MOD_ATRIB = 279,               /* MOD_ATRIB  */
    IF = 280,                      /* IF  */
    SWITCH = 281,                  /* SWITCH  */
    CASE = 282,                    /* CASE  */
    DEFAULT = 283,                 /* DEFAULT  */
    RETURN = 284,                  /* RETURN  */
    FOR = 285,                     /* FOR  */
    WHILE = 286,                   /* WHILE  */
    DO = 287,                      /* DO  */
    BREAK = 288,                   /* BREAK  */
    CONTINUE = 289,                /* CONTINUE  */
    DOIS_PONTOS = 290,             /* DOIS_PONTOS  */
    DOUBLE = 291,                  /* DOUBLE  */
    SHORT = 292,                   /* SHORT  */
    LONG = 293,                    /* LONG  */
    SIGNED = 294,                  /* SIGNED  */
    UNSIGNED = 295,                /* UNSIGNED  */
    VOID = 296,                    /* VOID  */
    STR_LITERAL = 297,             /* STR_LITERAL  */
    CHAR_LITERAL = 298,            /* CHAR_LITERAL  */
    NUM = 299,                     /* NUM  */
    ID = 300                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "src/parser.y"

    char* str;
    char  ch;

#line 114 "src/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_TAB_H_INCLUDED  */
