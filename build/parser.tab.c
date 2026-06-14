/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

#include "common.h"
#include "tabela.h"
#include "ast/ast.h"
#include "semantic.h"
#include "tabela_funcoes.h"

ASTNode* global_ast_root = NULL;

int indent = 0;

void print_indent(void) {
    for (int i = 0; i < indent; i++) {
        printf("    ");
    }
}

#line 89 "build/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_DOUBLE = 6,                     /* DOUBLE  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_COMMENT_LINE = 8,               /* COMMENT_LINE  */
  YYSYMBOL_COMMENT_BLOCK = 9,              /* COMMENT_BLOCK  */
  YYSYMBOL_SHORT = 10,                     /* SHORT  */
  YYSYMBOL_LONG = 11,                      /* LONG  */
  YYSYMBOL_SIGNED = 12,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 13,                  /* UNSIGNED  */
  YYSYMBOL_MAIN = 14,                      /* MAIN  */
  YYSYMBOL_APARENTESE = 15,                /* APARENTESE  */
  YYSYMBOL_FPARENTESE = 16,                /* FPARENTESE  */
  YYSYMBOL_ACHAVE = 17,                    /* ACHAVE  */
  YYSYMBOL_FCHAVE = 18,                    /* FCHAVE  */
  YYSYMBOL_A_COLCHETE = 19,                /* A_COLCHETE  */
  YYSYMBOL_F_COLCHETE = 20,                /* F_COLCHETE  */
  YYSYMBOL_PONTO_VIRGULA = 21,             /* PONTO_VIRGULA  */
  YYSYMBOL_ATRIB = 22,                     /* ATRIB  */
  YYSYMBOL_VIRGULA = 23,                   /* VIRGULA  */
  YYSYMBOL_DOIS_PONTOS = 24,               /* DOIS_PONTOS  */
  YYSYMBOL_SOMA_ATRIB = 25,                /* SOMA_ATRIB  */
  YYSYMBOL_SUB_ATRIB = 26,                 /* SUB_ATRIB  */
  YYSYMBOL_MULT_ATRIB = 27,                /* MULT_ATRIB  */
  YYSYMBOL_DIV_ATRIB = 28,                 /* DIV_ATRIB  */
  YYSYMBOL_MOD_ATRIB = 29,                 /* MOD_ATRIB  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_SWITCH = 31,                    /* SWITCH  */
  YYSYMBOL_CASE = 32,                      /* CASE  */
  YYSYMBOL_DEFAULT = 33,                   /* DEFAULT  */
  YYSYMBOL_RETURN = 34,                    /* RETURN  */
  YYSYMBOL_FOR = 35,                       /* FOR  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_DO = 37,                        /* DO  */
  YYSYMBOL_BREAK = 38,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 39,                  /* CONTINUE  */
  YYSYMBOL_ELSE = 40,                      /* ELSE  */
  YYSYMBOL_PRINTF = 41,                    /* PRINTF  */
  YYSYMBOL_SCANF = 42,                     /* SCANF  */
  YYSYMBOL_STRUCT = 43,                    /* STRUCT  */
  YYSYMBOL_TYPEDEF = 44,                   /* TYPEDEF  */
  YYSYMBOL_SIZEOF = 45,                    /* SIZEOF  */
  YYSYMBOL_CONST = 46,                     /* CONST  */
  YYSYMBOL_STATIC = 47,                    /* STATIC  */
  YYSYMBOL_TK_EQ = 48,                     /* TK_EQ  */
  YYSYMBOL_TK_NE = 49,                     /* TK_NE  */
  YYSYMBOL_TK_LE = 50,                     /* TK_LE  */
  YYSYMBOL_TK_GE = 51,                     /* TK_GE  */
  YYSYMBOL_TK_LT = 52,                     /* TK_LT  */
  YYSYMBOL_TK_GT = 53,                     /* TK_GT  */
  YYSYMBOL_OR_LOGICO = 54,                 /* OR_LOGICO  */
  YYSYMBOL_AND_LOGICO = 55,                /* AND_LOGICO  */
  YYSYMBOL_SOMA = 56,                      /* SOMA  */
  YYSYMBOL_SUB = 57,                       /* SUB  */
  YYSYMBOL_MULT = 58,                      /* MULT  */
  YYSYMBOL_DIV = 59,                       /* DIV  */
  YYSYMBOL_MOD = 60,                       /* MOD  */
  YYSYMBOL_INC = 61,                       /* INC  */
  YYSYMBOL_DEC = 62,                       /* DEC  */
  YYSYMBOL_NOT = 63,                       /* NOT  */
  YYSYMBOL_STR_LITERAL = 64,               /* STR_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 65,              /* CHAR_LITERAL  */
  YYSYMBOL_NUM = 66,                       /* NUM  */
  YYSYMBOL_ID = 67,                        /* ID  */
  YYSYMBOL_BIT_AND = 68,                   /* BIT_AND  */
  YYSYMBOL_UMINUS = 69,                    /* UMINUS  */
  YYSYMBOL_DEREF = 70,                     /* DEREF  */
  YYSYMBOL_LOWER_THAN_ELSE = 71,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 72,                  /* $accept  */
  YYSYMBOL_elemento_programa = 73,         /* elemento_programa  */
  YYSYMBOL_program = 74,                   /* program  */
  YYSYMBOL_funcao = 75,                    /* funcao  */
  YYSYMBOL_76_1 = 76,                      /* $@1  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_bloco_da_funcao = 78,           /* bloco_da_funcao  */
  YYSYMBOL_bloco = 79,                     /* bloco  */
  YYSYMBOL_80_3 = 80,                      /* $@3  */
  YYSYMBOL_lista_comandos = 81,            /* lista_comandos  */
  YYSYMBOL_comando = 82,                   /* comando  */
  YYSYMBOL_tipo = 83,                      /* tipo  */
  YYSYMBOL_parametros = 84,                /* parametros  */
  YYSYMBOL_parametro = 85,                 /* parametro  */
  YYSYMBOL_modificadores = 86,             /* modificadores  */
  YYSYMBOL_declaracao = 87,                /* declaracao  */
  YYSYMBOL_atribuicao = 88,                /* atribuicao  */
  YYSYMBOL_selecao = 89,                   /* selecao  */
  YYSYMBOL_comentario = 90,                /* comentario  */
  YYSYMBOL_definicao_struct = 91,          /* definicao_struct  */
  YYSYMBOL_retorno = 92,                   /* retorno  */
  YYSYMBOL_expressao = 93,                 /* expressao  */
  YYSYMBOL_chamada_funcao = 94,            /* chamada_funcao  */
  YYSYMBOL_argumentos = 95,                /* argumentos  */
  YYSYMBOL_for_init = 96,                  /* for_init  */
  YYSYMBOL_for_cond = 97,                  /* for_cond  */
  YYSYMBOL_for_incr = 98,                  /* for_incr  */
  YYSYMBOL_declaracao_array = 99,          /* declaracao_array  */
  YYSYMBOL_lista_dimensoes = 100,          /* lista_dimensoes  */
  YYSYMBOL_acesso_array = 101,             /* acesso_array  */
  YYSYMBOL_lista_indices = 102,            /* lista_indices  */
  YYSYMBOL_lista_init = 103                /* lista_init  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   839

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   326


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    92,    93,    97,   104,   108,   115,   115,
     119,   119,   126,   136,   136,   143,   144,   159,   160,   161,
     162,   166,   169,   170,   171,   172,   173,   174,   177,   180,
     183,   187,   193,   194,   195,   196,   197,   198,   205,   206,
     207,   211,   218,   219,   220,   221,   225,   229,   234,   238,
     243,   247,   252,   259,   271,   279,   286,   293,   300,   308,
     313,   318,   327,   330,   336,   337,   341,   347,   353,   354,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   386,   396,   397,   400,   406,   407,   411,   415,
     422,   423,   427,   428,   429,   430,   431,   432,   436,   440,
     447,   450,   460,   469,   472,   481,   482
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "CHAR",
  "DOUBLE", "VOID", "COMMENT_LINE", "COMMENT_BLOCK", "SHORT", "LONG",
  "SIGNED", "UNSIGNED", "MAIN", "APARENTESE", "FPARENTESE", "ACHAVE",
  "FCHAVE", "A_COLCHETE", "F_COLCHETE", "PONTO_VIRGULA", "ATRIB",
  "VIRGULA", "DOIS_PONTOS", "SOMA_ATRIB", "SUB_ATRIB", "MULT_ATRIB",
  "DIV_ATRIB", "MOD_ATRIB", "IF", "SWITCH", "CASE", "DEFAULT", "RETURN",
  "FOR", "WHILE", "DO", "BREAK", "CONTINUE", "ELSE", "PRINTF", "SCANF",
  "STRUCT", "TYPEDEF", "SIZEOF", "CONST", "STATIC", "TK_EQ", "TK_NE",
  "TK_LE", "TK_GE", "TK_LT", "TK_GT", "OR_LOGICO", "AND_LOGICO", "SOMA",
  "SUB", "MULT", "DIV", "MOD", "INC", "DEC", "NOT", "STR_LITERAL",
  "CHAR_LITERAL", "NUM", "ID", "BIT_AND", "UMINUS", "DEREF",
  "LOWER_THAN_ELSE", "$accept", "elemento_programa", "program", "funcao",
  "$@1", "$@2", "bloco_da_funcao", "bloco", "$@3", "lista_comandos",
  "comando", "tipo", "parametros", "parametro", "modificadores",
  "declaracao", "atribuicao", "selecao", "comentario", "definicao_struct",
  "retorno", "expressao", "chamada_funcao", "argumentos", "for_init",
  "for_cond", "for_incr", "declaracao_array", "lista_dimensoes",
  "acesso_array", "lista_indices", "lista_init", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-178)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     224,  -178,  -178,  -178,  -178,  -178,    -6,   -50,   -21,   -18,
    -178,    99,  -178,     5,    91,  -178,  -178,   101,  -178,  -178,
    -178,  -178,  -178,    19,    40,    93,    42,   102,   117,    43,
    -178,    77,  -178,    10,   151,   106,  -178,  -178,   102,  -178,
      85,    91,   134,    10,    10,    10,    10,  -178,  -178,  -178,
     116,    89,   515,  -178,  -178,    94,  -178,   144,  -178,  -178,
      10,  -178,  -178,    10,    97,   -15,  -178,  -178,   377,  -178,
    -178,  -178,    10,    10,   152,  -178,  -178,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
     154,    10,    91,   528,   179,   568,  -178,   158,    91,  -178,
     417,    20,   461,    10,   280,   280,    92,    92,    92,    92,
     475,   547,   145,   145,  -178,  -178,  -178,  -178,   417,    15,
     107,  -178,  -178,  -178,  -178,   162,    10,   165,   166,   169,
     174,   183,   184,   133,    22,   140,  -178,  -178,   -51,    91,
    -178,  -178,  -178,  -178,  -178,  -178,   581,   185,  -178,  -178,
    -178,  -178,  -178,    10,  -178,   502,   187,    10,   158,    10,
     594,    17,    10,  -178,  -178,    10,   142,   199,    47,    10,
      10,    10,    10,    10,    10,   198,   202,   170,   157,  -178,
      10,   245,   417,  -178,  -178,   417,  -178,   390,  -178,   210,
     167,   212,   435,   448,   216,  -178,    10,   634,   647,   660,
     700,   713,   726,  -178,  -178,    61,   766,  -178,   356,    10,
     213,    10,   356,   219,   173,   311,   779,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,   215,   417,    10,   417,   235,  -178,
    -178,   190,   237,  -178,   356,   417,   192,   248,  -178,  -178,
     -20,   249,   240,    10,    10,    10,  -178,  -178,   356,  -178,
     417,   417,   417,  -178
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    32,    33,    34,    35,    36,     0,     0,    42,    43,
       6,     0,     2,     0,     0,     3,    50,     0,    37,    44,
      45,     1,     7,     0,     0,     0,     0,     0,     0,     0,
       8,     0,    46,     0,     0,     0,    13,     4,     0,    51,
       0,    38,     0,     0,     0,     0,     0,    71,    72,    68,
      69,     0,     0,    70,    89,     0,   108,     0,    10,    48,
       0,    15,     5,     0,     0,     0,    39,   110,     0,    88,
      91,    87,    93,     0,   112,    90,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,    41,     0,     0,    86,
      94,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      85,    84,    73,    74,    75,    76,    77,   111,   115,     0,
       0,    49,    64,    65,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    23,    16,     0,     0,
      17,    18,    19,    25,    26,    22,     0,    89,    52,    15,
       9,    40,    92,     0,   113,     0,     0,     0,     0,     0,
       0,    96,     0,    28,    29,     0,     0,    37,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,    95,   114,   109,   116,    11,     0,    67,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,    59,    60,     0,     0,    12,     0,     0,
      97,   100,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    31,    62,    99,     0,   101,     0,    27,
      20,     0,     0,    61,     0,    98,   102,     0,    66,    63,
       0,     0,     0,     0,     0,     0,   106,   107,     0,    21,
     103,   104,   105,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,   255,  -178,  -178,  -178,  -178,   110,   -24,  -178,  -134,
    -177,    18,   177,   175,    81,   100,  -178,  -178,  -178,  -178,
    -178,   -33,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   -90,
    -178,  -178
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    41,    92,   150,   136,    61,    94,
     137,   138,    65,    66,   139,   140,   141,   142,   143,   144,
     145,   146,    53,   101,   191,   228,   241,    16,    34,    54,
      74,   119
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    97,   243,    37,   147,   244,   245,    24,    98,    17,
      68,    69,    70,    71,    62,   181,   177,    18,    13,    23,
       1,     2,     3,     4,     5,    43,    19,    93,    20,    13,
      95,   224,    26,   156,    28,   229,   152,    43,   157,   100,
     102,   246,   247,   153,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   239,   118,    64,
       7,   215,    72,    24,    39,    40,    73,    44,    45,   196,
     155,   253,    25,    46,    47,    48,    49,    50,    51,    44,
      45,    14,    59,    60,   189,    46,    47,    48,    49,   168,
      51,   147,    14,   160,     1,     2,     3,     4,     5,    21,
      15,    70,     1,     2,     3,     4,     5,    29,    30,    35,
      64,    15,    31,     6,    32,    33,    64,    27,   147,    36,
     182,    58,   147,   158,   185,   147,   187,    59,    60,   192,
      98,    72,   193,    38,     7,    73,   197,   198,   199,   200,
     201,   202,     7,    42,   147,     8,     9,   206,    85,    86,
      87,    88,    89,    63,    67,    72,    75,   178,   147,    73,
      90,    91,   169,   216,    96,   170,   171,   172,   173,   174,
      55,   103,    56,    57,   117,   149,   225,   159,   227,   190,
     161,   162,     1,     2,     3,     4,     5,   122,   123,    31,
     163,    32,    33,   235,    43,   164,    36,   124,   165,   166,
     167,   175,   176,    87,    88,    89,   194,   180,   184,   125,
     250,   251,   252,   126,   127,   128,   195,   129,   130,   203,
     131,   132,   133,   204,   205,     8,     9,     1,     2,     3,
       4,     5,   209,   211,   210,   226,    44,   134,     6,   214,
     230,   231,    46,    47,    48,    49,   135,    51,     1,     2,
       3,     4,     5,   122,   123,   234,   236,   237,   238,   240,
      43,   249,    36,   207,   242,   248,    22,     7,   186,   120,
       8,     9,     0,   151,     0,   125,     0,     0,     0,   126,
     127,   128,     0,   129,   130,     0,   131,   132,   133,     0,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,   134,     0,     0,     0,     0,    46,    47,
      48,    49,   135,    51,     1,     2,     3,     4,     5,   122,
     123,     0,     0,     0,     0,     0,    43,     0,    36,   232,
      79,    80,    81,    82,     0,     0,    85,    86,    87,    88,
      89,   125,     0,     0,     0,   126,   127,   128,     0,   129,
     130,     0,   131,   132,   133,     0,     0,     8,     9,     1,
       2,     3,     4,     5,   122,   123,     0,     0,    44,   134,
       0,    43,     0,    36,    46,    47,    48,    49,   135,    51,
       0,     0,     0,     0,     0,     0,   125,     0,     0,     0,
     126,   127,   128,    99,   129,   130,     0,   131,   132,   133,
       0,     0,     8,     9,     0,     0,   208,     0,     0,     0,
       0,     0,     0,    44,   134,     0,     0,     0,     0,    46,
      47,    48,    49,   135,    51,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,   154,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   183,    77,    78,    79,    80,    81,    82,     0,
      84,    85,    86,    87,    88,    89,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   148,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,     0,   179,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,   188,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,   220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   223,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89
};

static const yytype_int16 yycheck[] =
{
      33,    16,    22,    27,    94,    25,    26,    58,    23,    15,
      43,    44,    45,    46,    38,   149,    67,    67,     0,    14,
       3,     4,     5,     6,     7,    15,    47,    60,    46,    11,
      63,   208,    14,    18,    15,   212,    16,    15,    23,    72,
      73,    61,    62,    23,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   234,    91,    41,
      43,   195,    15,    58,    21,    22,    19,    57,    58,    22,
     103,   248,    67,    63,    64,    65,    66,    67,    68,    57,
      58,     0,    21,    22,    67,    63,    64,    65,    66,    67,
      68,   181,    11,   126,     3,     4,     5,     6,     7,     0,
       0,   134,     3,     4,     5,     6,     7,    67,    15,    67,
      92,    11,    19,    14,    21,    22,    98,    16,   208,    17,
     153,    15,   212,    16,   157,   215,   159,    21,    22,   162,
      23,    15,   165,    16,    43,    19,   169,   170,   171,   172,
     173,   174,    43,    66,   234,    46,    47,   180,    56,    57,
      58,    59,    60,    68,    20,    15,    67,   139,   248,    19,
      66,    17,    22,   196,    67,    25,    26,    27,    28,    29,
      19,    19,    21,    22,    20,    17,   209,    15,   211,   161,
      15,    15,     3,     4,     5,     6,     7,     8,     9,    19,
      21,    21,    22,   226,    15,    21,    17,    18,    15,    15,
      67,    61,    62,    58,    59,    60,    64,    22,    21,    30,
     243,   244,   245,    34,    35,    36,    17,    38,    39,    21,
      41,    42,    43,    21,    67,    46,    47,     3,     4,     5,
       6,     7,    22,    21,    67,    22,    57,    58,    14,    23,
      21,    68,    63,    64,    65,    66,    67,    68,     3,     4,
       5,     6,     7,     8,     9,    40,    21,    67,    21,    67,
      15,    21,    17,    18,    16,    16,    11,    43,   158,    92,
      46,    47,    -1,    98,    -1,    30,    -1,    -1,    -1,    34,
      35,    36,    -1,    38,    39,    -1,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    15,    -1,    17,    18,
      50,    51,    52,    53,    -1,    -1,    56,    57,    58,    59,
      60,    30,    -1,    -1,    -1,    34,    35,    36,    -1,    38,
      39,    -1,    41,    42,    43,    -1,    -1,    46,    47,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    57,    58,
      -1,    15,    -1,    17,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    36,    16,    38,    39,    -1,    41,    42,    43,
      -1,    -1,    46,    47,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    20,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    20,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    21,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    -1,    21,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    14,    43,    46,    47,
      73,    74,    75,    83,    86,    87,    99,    15,    67,    47,
      46,     0,    73,    14,    58,    67,    83,    16,    15,    67,
      15,    19,    21,    22,   100,    67,    17,    79,    16,    21,
      22,    76,    66,    15,    57,    58,    63,    64,    65,    66,
      67,    68,    93,    94,   101,    19,    21,    22,    15,    21,
      22,    80,    79,    68,    83,    84,    85,    20,    93,    93,
      93,    93,    15,    19,   102,    67,    21,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      66,    17,    77,    93,    81,    93,    67,    16,    23,    16,
      93,    95,    93,    19,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    20,    93,   103,
      84,    21,     8,     9,    18,    30,    34,    35,    36,    38,
      39,    41,    42,    43,    58,    67,    79,    82,    83,    86,
      87,    88,    89,    90,    91,    92,    93,   101,    21,    17,
      78,    85,    16,    23,    20,    93,    18,    23,    16,    15,
      93,    15,    15,    21,    21,    15,    15,    67,    67,    22,
      25,    26,    27,    28,    29,    61,    62,    67,    83,    21,
      22,    81,    93,    20,    21,    93,    78,    93,    21,    67,
      83,    96,    93,    93,    64,    17,    22,    93,    93,    93,
      93,    93,    93,    21,    21,    67,    93,    18,    16,    22,
      67,    21,    16,    16,    23,    81,    93,    21,    21,    21,
      21,    21,    21,    21,    82,    93,    22,    93,    97,    82,
      21,    68,    18,    21,    40,    93,    21,    67,    21,    82,
      67,    98,    16,    22,    25,    26,    61,    62,    16,    21,
      93,    93,    93,    82
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    73,    73,    73,    74,    74,    76,    75,
      77,    75,    78,    80,    79,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    83,    84,    84,
      84,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    90,    90,    91,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   100,   101,   102,   102,   103,   103
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     4,     5,     1,     2,     0,     7,
       0,     8,     3,     0,     4,     0,     2,     1,     1,     1,
       5,     8,     1,     1,     2,     1,     1,     5,     2,     2,
       9,     4,     1,     1,     1,     1,     1,     2,     0,     1,
       3,     2,     1,     1,     2,     2,     3,     5,     4,     6,
       1,     4,     7,     4,     4,     4,     4,     4,     4,     3,
       3,     5,     5,     7,     1,     1,     6,     3,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       2,     2,     4,     0,     1,     3,     0,     2,     4,     3,
       0,     1,     0,     3,     3,     3,     2,     2,     4,     8,
       3,     4,     2,     3,     4,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* elemento_programa: funcao  */
#line 91 "src/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1468 "build/parser.tab.c"
    break;

  case 3: /* elemento_programa: declaracao  */
#line 92 "src/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1474 "build/parser.tab.c"
    break;

  case 4: /* elemento_programa: MAIN APARENTESE FPARENTESE bloco  */
#line 93 "src/parser.y"
                                       { 
          inserir("main", "int", yylineno); 
          (yyval.node) = create_func_node("int", "main", "", (yyvsp[0].node)); 
      }
#line 1483 "build/parser.tab.c"
    break;

  case 5: /* elemento_programa: tipo MAIN APARENTESE FPARENTESE bloco  */
#line 97 "src/parser.y"
                                            { 
          inserir("main", (yyvsp[-4].str), yylineno); 
          (yyval.node) = create_func_node((yyvsp[-4].str), "main", "", (yyvsp[0].node)); 
      }
#line 1492 "build/parser.tab.c"
    break;

  case 6: /* program: elemento_programa  */
#line 104 "src/parser.y"
                        { 
          (yyval.node) = (yyvsp[0].node); 
          global_ast_root = (yyval.node); 
      }
#line 1501 "build/parser.tab.c"
    break;

  case 7: /* program: program elemento_programa  */
#line 108 "src/parser.y"
                                { 
          (yyval.node) = create_program_node((yyvsp[-1].node), (yyvsp[0].node)); 
          global_ast_root = (yyval.node); 
      }
#line 1510 "build/parser.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 115 "src/parser.y"
                         { entrar_escopo(); }
#line 1516 "build/parser.tab.c"
    break;

  case 9: /* funcao: tipo ID APARENTESE $@1 parametros FPARENTESE bloco_da_funcao  */
#line 115 "src/parser.y"
                                                                                    {
          registrar_funcao((yyvsp[-5].str), contar_params((yyvsp[-2].str)), yylineno);
          (yyval.node) = create_func_node((yyvsp[-6].str), (yyvsp[-5].str), (yyvsp[-2].str), (yyvsp[0].node));
      }
#line 1525 "build/parser.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 119 "src/parser.y"
                                       { entrar_escopo(); }
#line 1531 "build/parser.tab.c"
    break;

  case 11: /* funcao: modificadores tipo ID APARENTESE $@2 parametros FPARENTESE bloco_da_funcao  */
#line 119 "src/parser.y"
                                                                                                  {
          registrar_funcao((yyvsp[-5].str), contar_params((yyvsp[-2].str)), yylineno);
          (yyval.node) = create_func_node((yyvsp[-6].str), (yyvsp[-5].str), (yyvsp[-2].str), (yyvsp[0].node)); 
    }
#line 1540 "build/parser.tab.c"
    break;

  case 12: /* bloco_da_funcao: ACHAVE lista_comandos FCHAVE  */
#line 126 "src/parser.y"
                                 {
        /*fprintf(stderr, "\n=== TABELA DE SÍMBOLOS DA FUNÇÃO ===\n");*/
        /*imprimir_tabela();*/
        
        sair_escopo();
        (yyval.node) = create_block_node((yyvsp[-1].node));
    }
#line 1552 "build/parser.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 136 "src/parser.y"
           { entrar_escopo(); }
#line 1558 "build/parser.tab.c"
    break;

  case 14: /* bloco: ACHAVE $@3 lista_comandos FCHAVE  */
#line 136 "src/parser.y"
                                                      { 
        sair_escopo(); 
        (yyval.node) = create_block_node((yyvsp[-1].node));
    }
#line 1567 "build/parser.tab.c"
    break;

  case 15: /* lista_comandos: %empty  */
#line 143 "src/parser.y"
    { (yyval.node) = NULL; }
#line 1573 "build/parser.tab.c"
    break;

  case 16: /* lista_comandos: lista_comandos comando  */
#line 144 "src/parser.y"
                             {
          if ((yyvsp[-1].node) == NULL) {
              (yyval.node) = (yyvsp[0].node);
          } else {
              ASTNode* curr = (yyvsp[-1].node);
              while (curr->next != NULL) {
                  curr = curr->next;
              }
              curr->next = (yyvsp[0].node);
              (yyval.node) = (yyvsp[-1].node);
          }
      }
#line 1590 "build/parser.tab.c"
    break;

  case 17: /* comando: declaracao  */
#line 159 "src/parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1596 "build/parser.tab.c"
    break;

  case 18: /* comando: atribuicao  */
#line 160 "src/parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1602 "build/parser.tab.c"
    break;

  case 19: /* comando: selecao  */
#line 161 "src/parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1608 "build/parser.tab.c"
    break;

  case 20: /* comando: PRINTF APARENTESE expressao FPARENTESE PONTO_VIRGULA  */
#line 162 "src/parser.y"
                                                           {
          (yyval.node) = create_printf_node((yyvsp[-2].node));
      }
#line 1616 "build/parser.tab.c"
    break;

  case 21: /* comando: SCANF APARENTESE STR_LITERAL VIRGULA BIT_AND ID FPARENTESE PONTO_VIRGULA  */
#line 166 "src/parser.y"
                                                                               {
          (yyval.node) = create_scanf_node((yyvsp[-2].str));
      }
#line 1624 "build/parser.tab.c"
    break;

  case 22: /* comando: retorno  */
#line 169 "src/parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1630 "build/parser.tab.c"
    break;

  case 23: /* comando: bloco  */
#line 170 "src/parser.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1636 "build/parser.tab.c"
    break;

  case 24: /* comando: expressao PONTO_VIRGULA  */
#line 171 "src/parser.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 1642 "build/parser.tab.c"
    break;

  case 25: /* comando: comentario  */
#line 172 "src/parser.y"
                         { (yyval.node) = NULL; }
#line 1648 "build/parser.tab.c"
    break;

  case 26: /* comando: definicao_struct  */
#line 173 "src/parser.y"
                         { (yyval.node) = NULL; }
#line 1654 "build/parser.tab.c"
    break;

  case 27: /* comando: WHILE APARENTESE expressao FPARENTESE comando  */
#line 174 "src/parser.y"
                                                    {
          (yyval.node) = create_while_node((yyvsp[-2].node), (yyvsp[0].node));
      }
#line 1662 "build/parser.tab.c"
    break;

  case 28: /* comando: BREAK PONTO_VIRGULA  */
#line 177 "src/parser.y"
                          {
          (yyval.node) = create_break_node();
      }
#line 1670 "build/parser.tab.c"
    break;

  case 29: /* comando: CONTINUE PONTO_VIRGULA  */
#line 180 "src/parser.y"
                             {
          (yyval.node) = create_continue_node();
      }
#line 1678 "build/parser.tab.c"
    break;

  case 30: /* comando: FOR APARENTESE for_init PONTO_VIRGULA for_cond PONTO_VIRGULA for_incr FPARENTESE comando  */
#line 183 "src/parser.y"
                                                                                               {
        (yyval.node) = create_for_node((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1686 "build/parser.tab.c"
    break;

  case 31: /* comando: acesso_array ATRIB expressao PONTO_VIRGULA  */
#line 187 "src/parser.y"
                                                 {
         (yyval.node) = create_array_assign_node_v2((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 1694 "build/parser.tab.c"
    break;

  case 32: /* tipo: INT  */
#line 193 "src/parser.y"
             { (yyval.str) = "int"; }
#line 1700 "build/parser.tab.c"
    break;

  case 33: /* tipo: FLOAT  */
#line 194 "src/parser.y"
             { (yyval.str) = "float"; }
#line 1706 "build/parser.tab.c"
    break;

  case 34: /* tipo: CHAR  */
#line 195 "src/parser.y"
             { (yyval.str) = "char"; }
#line 1712 "build/parser.tab.c"
    break;

  case 35: /* tipo: DOUBLE  */
#line 196 "src/parser.y"
             { (yyval.str) = "double"; }
#line 1718 "build/parser.tab.c"
    break;

  case 36: /* tipo: VOID  */
#line 197 "src/parser.y"
             { (yyval.str) = "void"; }
#line 1724 "build/parser.tab.c"
    break;

  case 37: /* tipo: STRUCT ID  */
#line 198 "src/parser.y"
                {
        asprintf(&(yyval.str), "struct %s", (yyvsp[0].str));
    }
#line 1732 "build/parser.tab.c"
    break;

  case 38: /* parametros: %empty  */
#line 205 "src/parser.y"
    { (yyval.str) = strdup(""); }
#line 1738 "build/parser.tab.c"
    break;

  case 39: /* parametros: parametro  */
#line 206 "src/parser.y"
                  { (yyval.str) = (yyvsp[0].str); }
#line 1744 "build/parser.tab.c"
    break;

  case 40: /* parametros: parametros VIRGULA parametro  */
#line 207 "src/parser.y"
                                   { asprintf(&(yyval.str), "%s, %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1750 "build/parser.tab.c"
    break;

  case 41: /* parametro: tipo ID  */
#line 211 "src/parser.y"
            {
        inserir((yyvsp[0].str), (yyvsp[-1].str), yylineno);
        (yyval.str) = strdup((yyvsp[0].str));
    }
#line 1759 "build/parser.tab.c"
    break;

  case 46: /* declaracao: tipo ID PONTO_VIRGULA  */
#line 225 "src/parser.y"
                          {
          inserir((yyvsp[-1].str), (yyvsp[-2].str), yylineno);
          (yyval.node) = create_decl_node((yyvsp[-2].str), (yyvsp[-1].str), NULL);
      }
#line 1768 "build/parser.tab.c"
    break;

  case 47: /* declaracao: tipo ID ATRIB expressao PONTO_VIRGULA  */
#line 229 "src/parser.y"
                                            {
          inserir((yyvsp[-3].str), (yyvsp[-4].str), yylineno);
          (yyval.node) = create_decl_node((yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-1].node));
      }
#line 1777 "build/parser.tab.c"
    break;

  case 48: /* declaracao: modificadores tipo ID PONTO_VIRGULA  */
#line 234 "src/parser.y"
                                          {
          inserir((yyvsp[-1].str), (yyvsp[-2].str), yylineno); 
          (yyval.node) = create_decl_node((yyvsp[-2].str), (yyvsp[-1].str), NULL);
      }
#line 1786 "build/parser.tab.c"
    break;

  case 49: /* declaracao: modificadores tipo ID ATRIB expressao PONTO_VIRGULA  */
#line 238 "src/parser.y"
                                                          { 
          inserir((yyvsp[-3].str), (yyvsp[-4].str), yylineno); 
          (yyval.node) = create_decl_node((yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-1].node));
      }
#line 1795 "build/parser.tab.c"
    break;

  case 50: /* declaracao: declaracao_array  */
#line 243 "src/parser.y"
                       {
          (yyval.node) = (yyvsp[0].node);
      }
#line 1803 "build/parser.tab.c"
    break;

  case 51: /* declaracao: tipo MULT ID PONTO_VIRGULA  */
#line 247 "src/parser.y"
                                 {
        inserir_ponteiro((yyvsp[-1].str), (yyvsp[-3].str), yylineno);
        (yyval.node) = create_pointer_decl_node((yyvsp[-3].str), (yyvsp[-1].str), NULL);
      }
#line 1812 "build/parser.tab.c"
    break;

  case 52: /* declaracao: tipo MULT ID ATRIB BIT_AND expressao PONTO_VIRGULA  */
#line 252 "src/parser.y"
                                                         {
        inserir_ponteiro((yyvsp[-4].str), (yyvsp[-6].str), yylineno);
        (yyval.node) = create_pointer_decl_node((yyvsp[-6].str), (yyvsp[-4].str), create_address_node((yyvsp[-1].node)));
      }
#line 1821 "build/parser.tab.c"
    break;

  case 53: /* atribuicao: ID ATRIB expressao PONTO_VIRGULA  */
#line 259 "src/parser.y"
                                       {

        if (buscar((yyvsp[-3].str)) == NULL) {
            fprintf(stderr,
                "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n",
                yylineno,
                (yyvsp[-3].str));
            exit(1);
        }
        (yyval.node) = create_assign_node((yyvsp[-3].str), "=", (yyvsp[-1].node));
    }
#line 1837 "build/parser.tab.c"
    break;

  case 54: /* atribuicao: ID SOMA_ATRIB expressao PONTO_VIRGULA  */
#line 271 "src/parser.y"
                                            {

       if (buscar((yyvsp[-3].str)) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, (yyvsp[-3].str));
            exit(1);
        }
        (yyval.node) = create_assign_node((yyvsp[-3].str), "+=", (yyvsp[-1].node));
    }
#line 1850 "build/parser.tab.c"
    break;

  case 55: /* atribuicao: ID SUB_ATRIB expressao PONTO_VIRGULA  */
#line 279 "src/parser.y"
                                           { 
        if (buscar((yyvsp[-3].str)) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, (yyvsp[-3].str));
            exit(1);
        }
        (yyval.node) = create_assign_node((yyvsp[-3].str), "-=", (yyvsp[-1].node)); 
    }
#line 1862 "build/parser.tab.c"
    break;

  case 56: /* atribuicao: ID MULT_ATRIB expressao PONTO_VIRGULA  */
#line 286 "src/parser.y"
                                            {
        if (buscar((yyvsp[-3].str)) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, (yyvsp[-3].str));
            exit(1);
        }
        (yyval.node) = create_assign_node((yyvsp[-3].str), "*=", (yyvsp[-1].node));
    }
#line 1874 "build/parser.tab.c"
    break;

  case 57: /* atribuicao: ID DIV_ATRIB expressao PONTO_VIRGULA  */
#line 293 "src/parser.y"
                                           {
        if (buscar((yyvsp[-3].str)) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, (yyvsp[-3].str));
            exit(1);
        }
        (yyval.node) = create_assign_node((yyvsp[-3].str), "/=", (yyvsp[-1].node));
    }
#line 1886 "build/parser.tab.c"
    break;

  case 58: /* atribuicao: ID MOD_ATRIB expressao PONTO_VIRGULA  */
#line 300 "src/parser.y"
                                           {
        if (buscar((yyvsp[-3].str)) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, (yyvsp[-3].str));
            exit(1);
        }
        (yyval.node) = create_assign_node((yyvsp[-3].str), "%=", (yyvsp[-1].node));
    }
#line 1898 "build/parser.tab.c"
    break;

  case 59: /* atribuicao: ID INC PONTO_VIRGULA  */
#line 308 "src/parser.y"
                           {
        if (buscar((yyvsp[-2].str)) == NULL) { fprintf(stderr, "Erro Semantico...\n"); exit(1); }
        (yyval.node) = create_assign_node((yyvsp[-2].str), "+=", create_literal_node("1"));
    }
#line 1907 "build/parser.tab.c"
    break;

  case 60: /* atribuicao: ID DEC PONTO_VIRGULA  */
#line 313 "src/parser.y"
                           {
        if (buscar((yyvsp[-2].str)) == NULL) { fprintf(stderr, "Erro Semantico...\n"); exit(1); }
        (yyval.node) = create_assign_node((yyvsp[-2].str), "-=", create_literal_node("1"));
    }
#line 1916 "build/parser.tab.c"
    break;

  case 61: /* atribuicao: MULT ID ATRIB expressao PONTO_VIRGULA  */
#line 318 "src/parser.y"
                                            {
        Simbolo *s = buscar((yyvsp[-3].str));
        if (s == NULL) {fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, (yyvsp[-3].str)); exit(1);}
        if (s->categoria != SIM_PONTEIRO) {fprintf(stderr,"Erro Semantico na linha %d: '%s' nao e um ponteiro, nao pode ser desreferenciado.\n", yylineno, (yyvsp[-3].str)); exit(1);}
        (yyval.node) = create_pointer_assign_node(create_id_node((yyvsp[-3].str)), (yyvsp[-1].node));
    }
#line 1927 "build/parser.tab.c"
    break;

  case 62: /* selecao: IF APARENTESE expressao FPARENTESE comando  */
#line 327 "src/parser.y"
                                                                       {
          (yyval.node) = create_if_node((yyvsp[-2].node), (yyvsp[0].node), NULL);
      }
#line 1935 "build/parser.tab.c"
    break;

  case 63: /* selecao: IF APARENTESE expressao FPARENTESE comando ELSE comando  */
#line 330 "src/parser.y"
                                                              {
          (yyval.node) = create_if_node((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
      }
#line 1943 "build/parser.tab.c"
    break;

  case 66: /* definicao_struct: STRUCT ID ACHAVE lista_comandos FCHAVE PONTO_VIRGULA  */
#line 341 "src/parser.y"
                                                         {
        (yyval.node) = NULL; 
    }
#line 1951 "build/parser.tab.c"
    break;

  case 67: /* retorno: RETURN expressao PONTO_VIRGULA  */
#line 347 "src/parser.y"
                                   {
        (yyval.node) = create_return_node((yyvsp[-1].node));
    }
#line 1959 "build/parser.tab.c"
    break;

  case 68: /* expressao: NUM  */
#line 353 "src/parser.y"
                    { (yyval.node) = create_literal_node((yyvsp[0].str)); }
#line 1965 "build/parser.tab.c"
    break;

  case 69: /* expressao: ID  */
#line 354 "src/parser.y"
         {
        if (buscar((yyvsp[0].str)) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, (yyvsp[0].str));
            exit(1);
        }
        (yyval.node) = create_id_node((yyvsp[0].str));
    }
#line 1977 "build/parser.tab.c"
    break;

  case 70: /* expressao: chamada_funcao  */
#line 361 "src/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1983 "build/parser.tab.c"
    break;

  case 71: /* expressao: STR_LITERAL  */
#line 362 "src/parser.y"
                    { (yyval.node) = create_literal_node((yyvsp[0].str)); }
#line 1989 "build/parser.tab.c"
    break;

  case 72: /* expressao: CHAR_LITERAL  */
#line 363 "src/parser.y"
                    { (yyval.node) = create_literal_node((yyvsp[0].str)); }
#line 1995 "build/parser.tab.c"
    break;

  case 73: /* expressao: expressao SOMA expressao  */
#line 364 "src/parser.y"
                               { (yyval.node) = create_binary_op_node("+", (yyvsp[-2].node), (yyvsp[0].node)); checar_operacao_binaria_parser("+", (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 2001 "build/parser.tab.c"
    break;

  case 74: /* expressao: expressao SUB expressao  */
#line 365 "src/parser.y"
                               { (yyval.node) = create_binary_op_node("-", (yyvsp[-2].node), (yyvsp[0].node)); checar_operacao_binaria_parser("-", (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 2007 "build/parser.tab.c"
    break;

  case 75: /* expressao: expressao MULT expressao  */
#line 366 "src/parser.y"
                               { (yyval.node) = create_binary_op_node("*", (yyvsp[-2].node), (yyvsp[0].node)); checar_operacao_binaria_parser("*", (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 2013 "build/parser.tab.c"
    break;

  case 76: /* expressao: expressao DIV expressao  */
#line 367 "src/parser.y"
                               { (yyval.node) = create_binary_op_node("/", (yyvsp[-2].node), (yyvsp[0].node)); checar_operacao_binaria_parser("/", (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 2019 "build/parser.tab.c"
    break;

  case 77: /* expressao: expressao MOD expressao  */
#line 368 "src/parser.y"
                               { (yyval.node) = create_binary_op_node("%", (yyvsp[-2].node), (yyvsp[0].node)); checar_operacao_binaria_parser("%", (yyvsp[-2].node), (yyvsp[0].node), yylineno); }
#line 2025 "build/parser.tab.c"
    break;

  case 78: /* expressao: expressao TK_EQ expressao  */
#line 369 "src/parser.y"
                                { (yyval.node) = create_binary_op_node("==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2031 "build/parser.tab.c"
    break;

  case 79: /* expressao: expressao TK_NE expressao  */
#line 370 "src/parser.y"
                                { (yyval.node) = create_binary_op_node("!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2037 "build/parser.tab.c"
    break;

  case 80: /* expressao: expressao TK_LE expressao  */
#line 371 "src/parser.y"
                                { (yyval.node) = create_binary_op_node("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2043 "build/parser.tab.c"
    break;

  case 81: /* expressao: expressao TK_GE expressao  */
#line 372 "src/parser.y"
                                { (yyval.node) = create_binary_op_node(">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2049 "build/parser.tab.c"
    break;

  case 82: /* expressao: expressao TK_LT expressao  */
#line 373 "src/parser.y"
                                { (yyval.node) = create_binary_op_node("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2055 "build/parser.tab.c"
    break;

  case 83: /* expressao: expressao TK_GT expressao  */
#line 374 "src/parser.y"
                                { (yyval.node) = create_binary_op_node(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2061 "build/parser.tab.c"
    break;

  case 84: /* expressao: expressao AND_LOGICO expressao  */
#line 375 "src/parser.y"
                                     { (yyval.node) = create_binary_op_node("&&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2067 "build/parser.tab.c"
    break;

  case 85: /* expressao: expressao OR_LOGICO expressao  */
#line 376 "src/parser.y"
                                     { (yyval.node) = create_binary_op_node("||", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2073 "build/parser.tab.c"
    break;

  case 86: /* expressao: APARENTESE expressao FPARENTESE  */
#line 377 "src/parser.y"
                                      { (yyval.node) = (yyvsp[-1].node); }
#line 2079 "build/parser.tab.c"
    break;

  case 87: /* expressao: NOT expressao  */
#line 378 "src/parser.y"
                    { (yyval.node) = create_unary_op_node("!", (yyvsp[0].node)); }
#line 2085 "build/parser.tab.c"
    break;

  case 88: /* expressao: SUB expressao  */
#line 379 "src/parser.y"
                                 { (yyval.node) = create_unary_op_node("-", (yyvsp[0].node)); }
#line 2091 "build/parser.tab.c"
    break;

  case 89: /* expressao: acesso_array  */
#line 380 "src/parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 2097 "build/parser.tab.c"
    break;

  case 90: /* expressao: BIT_AND ID  */
#line 381 "src/parser.y"
                 { (yyval.node) = create_address_node(create_id_node((yyvsp[0].str))); }
#line 2103 "build/parser.tab.c"
    break;

  case 91: /* expressao: MULT expressao  */
#line 382 "src/parser.y"
                                 { (yyval.node) = create_deref_node((yyvsp[0].node)); }
#line 2109 "build/parser.tab.c"
    break;

  case 92: /* chamada_funcao: ID APARENTESE argumentos FPARENTESE  */
#line 386 "src/parser.y"
                                         {
        checar_chamada_funcao((yyvsp[-3].str), contar_args((yyvsp[-1].str)), yylineno);
        char* llamada_str;
        asprintf(&llamada_str, "%s(%s)", (yyvsp[-3].str), (yyvsp[-1].str));
        (yyval.node) = create_literal_node(llamada_str);
        free(llamada_str);
    }
#line 2121 "build/parser.tab.c"
    break;

  case 93: /* argumentos: %empty  */
#line 396 "src/parser.y"
    { (yyval.str) = strdup(""); }
#line 2127 "build/parser.tab.c"
    break;

  case 94: /* argumentos: expressao  */
#line 397 "src/parser.y"
                { 
          (yyval.str) = strdup((yyvsp[0].node) && (yyvsp[0].node)->value ? (yyvsp[0].node)->value : ""); 
      }
#line 2135 "build/parser.tab.c"
    break;

  case 95: /* argumentos: argumentos VIRGULA expressao  */
#line 400 "src/parser.y"
                                   { 
          asprintf(&(yyval.str), "%s, %s", (yyvsp[-2].str), ((yyvsp[0].node) && (yyvsp[0].node)->value ? (yyvsp[0].node)->value : "")); 
      }
#line 2143 "build/parser.tab.c"
    break;

  case 96: /* for_init: %empty  */
#line 406 "src/parser.y"
                  { (yyval.node) = NULL; }
#line 2149 "build/parser.tab.c"
    break;

  case 97: /* for_init: tipo ID  */
#line 407 "src/parser.y"
              {
          inserir((yyvsp[0].str), (yyvsp[-1].str), yylineno);
          (yyval.node) = create_decl_node((yyvsp[-1].str), (yyvsp[0].str), NULL);
      }
#line 2158 "build/parser.tab.c"
    break;

  case 98: /* for_init: tipo ID ATRIB expressao  */
#line 411 "src/parser.y"
                              {
          inserir((yyvsp[-2].str), (yyvsp[-3].str), yylineno);
          (yyval.node) = create_decl_node((yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[0].node));
      }
#line 2167 "build/parser.tab.c"
    break;

  case 99: /* for_init: ID ATRIB expressao  */
#line 415 "src/parser.y"
                         {
          if (buscar((yyvsp[-2].str)) == NULL) { fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, (yyvsp[-2].str)); exit(1); }
          (yyval.node) = create_assign_node((yyvsp[-2].str), "=", (yyvsp[0].node));
      }
#line 2176 "build/parser.tab.c"
    break;

  case 100: /* for_cond: %empty  */
#line 422 "src/parser.y"
    { (yyval.node) = NULL; }
#line 2182 "build/parser.tab.c"
    break;

  case 101: /* for_cond: expressao  */
#line 423 "src/parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2188 "build/parser.tab.c"
    break;

  case 102: /* for_incr: %empty  */
#line 427 "src/parser.y"
    { (yyval.node) = NULL; }
#line 2194 "build/parser.tab.c"
    break;

  case 103: /* for_incr: ID ATRIB expressao  */
#line 428 "src/parser.y"
                         { (yyval.node) = create_assign_node((yyvsp[-2].str), "=", (yyvsp[0].node)); }
#line 2200 "build/parser.tab.c"
    break;

  case 104: /* for_incr: ID SOMA_ATRIB expressao  */
#line 429 "src/parser.y"
                              { (yyval.node) = create_assign_node((yyvsp[-2].str), "+=", (yyvsp[0].node)); }
#line 2206 "build/parser.tab.c"
    break;

  case 105: /* for_incr: ID SUB_ATRIB expressao  */
#line 430 "src/parser.y"
                             { (yyval.node) = create_assign_node((yyvsp[-2].str), "-=", (yyvsp[0].node)); }
#line 2212 "build/parser.tab.c"
    break;

  case 106: /* for_incr: ID INC  */
#line 431 "src/parser.y"
             { (yyval.node) = create_assign_node((yyvsp[-1].str), "+=", create_literal_node("1")); }
#line 2218 "build/parser.tab.c"
    break;

  case 107: /* for_incr: ID DEC  */
#line 432 "src/parser.y"
             { (yyval.node) = create_assign_node((yyvsp[-1].str), "-=", create_literal_node("1")); }
#line 2224 "build/parser.tab.c"
    break;

  case 108: /* declaracao_array: tipo ID lista_dimensoes PONTO_VIRGULA  */
#line 436 "src/parser.y"
                                            {
          inserir_array((yyvsp[-2].str), (yyvsp[-3].str), 0, yylineno);;
          (yyval.node) = create_multi_array_decl_node((yyvsp[-3].str), (yyvsp[-2].str), (yyvsp[-1].node), NULL);
      }
#line 2233 "build/parser.tab.c"
    break;

  case 109: /* declaracao_array: tipo ID lista_dimensoes ATRIB ACHAVE lista_init FCHAVE PONTO_VIRGULA  */
#line 440 "src/parser.y"
                                                                           {
          inserir_array((yyvsp[-6].str), (yyvsp[-7].str), 0, yylineno);
          (yyval.node) = create_multi_array_decl_node((yyvsp[-7].str), (yyvsp[-6].str), (yyvsp[-5].node), (yyvsp[-2].node));
      }
#line 2242 "build/parser.tab.c"
    break;

  case 110: /* lista_dimensoes: A_COLCHETE NUM F_COLCHETE  */
#line 447 "src/parser.y"
                                {
          (yyval.node) = create_dimension_node(atoi((yyvsp[-1].str)), NULL);
      }
#line 2250 "build/parser.tab.c"
    break;

  case 111: /* lista_dimensoes: lista_dimensoes A_COLCHETE NUM F_COLCHETE  */
#line 450 "src/parser.y"
                                                {
          // Anexa a nova dimensão no final da lista de dimensões
          ASTNode* curr = (yyvsp[-3].node);
          while (curr->next != NULL) curr = curr->next;
          curr->next = create_dimension_node(atoi((yyvsp[-1].str)), NULL);
          (yyval.node) = (yyvsp[-3].node);
      }
#line 2262 "build/parser.tab.c"
    break;

  case 112: /* acesso_array: ID lista_indices  */
#line 460 "src/parser.y"
                       {
          if (buscar((yyvsp[-1].str)) == NULL) {fprintf(stderr, "Erro Semantico na linha %d: array '%s' nao declarado.\n", yylineno, (yyvsp[-1].str));
              exit(1);
          }
          (yyval.node) = create_multi_array_access_node((yyvsp[-1].str),(yyvsp[0].node));
      }
#line 2273 "build/parser.tab.c"
    break;

  case 113: /* lista_indices: A_COLCHETE expressao F_COLCHETE  */
#line 469 "src/parser.y"
                                      {
          (yyval.node) = create_index_node((yyvsp[-1].node), NULL);
      }
#line 2281 "build/parser.tab.c"
    break;

  case 114: /* lista_indices: lista_indices A_COLCHETE expressao F_COLCHETE  */
#line 472 "src/parser.y"
                                                    {
          ASTNode* curr = (yyvsp[-3].node);
          while (curr->next != NULL) curr = curr->next;
          curr->next = create_index_node((yyvsp[-1].node), NULL);
          (yyval.node) = (yyvsp[-3].node);
      }
#line 2292 "build/parser.tab.c"
    break;

  case 115: /* lista_init: expressao  */
#line 481 "src/parser.y"
                {(yyval.node) = (yyvsp[0].node);}
#line 2298 "build/parser.tab.c"
    break;

  case 116: /* lista_init: lista_init VIRGULA expressao  */
#line 482 "src/parser.y"
                                   {ASTNode* curr = (yyvsp[-2].node); while (curr->next != NULL) curr = curr->next; curr->next = (yyvsp[0].node); (yyval.node) = (yyvsp[-2].node);
      }
#line 2305 "build/parser.tab.c"
    break;


#line 2309 "build/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 486 "src/parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d perto de '%s'\n", yylineno, yytext);
    exit(1);
}
