%{
#include "common.h"
#include "tabela.h"
#include "ast/ast.h"

ASTNode* global_ast_root = NULL;

int indent = 0;

void print_indent(void) {
    for (int i = 0; i < indent; i++) {
        printf("    ");
    }
}
%}

/* 1. O %union vem primeiro */
%union {
    char* str;
    struct ASTNode* node;
}

%code requires {
    #include "common.h"
    #include "ast/ast.h"
}



%token INT FLOAT CHAR DOUBLE VOID
%token <str> COMMENT_LINE COMMENT_BLOCK
%token SHORT LONG SIGNED UNSIGNED

%token MAIN APARENTESE FPARENTESE ACHAVE FCHAVE A_COLCHETE F_COLCHETE
%token PONTO_VIRGULA ATRIB VIRGULA DOIS_PONTOS


%token SOMA_ATRIB SUB_ATRIB MULT_ATRIB DIV_ATRIB MOD_ATRIB

%token IF SWITCH CASE DEFAULT RETURN
%token FOR WHILE DO BREAK CONTINUE
%token ELSE


%token STRUCT TYPEDEF SIZEOF CONST STATIC

%token TK_EQ TK_NE TK_LE TK_GE TK_LT TK_GT

%token OR_LOGICO AND_LOGICO
%token SOMA SUB MULT DIV MOD
%token INC DEC
%token NOT

/* Tokens com valor de string */
%token <str> STR_LITERAL CHAR_LITERAL NUM ID

%token BIT_AND

%type <str> comentario argumentos tipo parametro parametros
%type <node> program funcao bloco bloco_da_funcao lista_comandos comando declaracao atribuicao selecao retorno expressao definicao_struct elemento_programa chamada_funcao
%type <node> for_init for_cond for_incr
%type <node> lista_init declaracao_array acesso_array
%type <node> lista_dimensoes lista_indices

/* Precedências */
%left OR_LOGICO
%left AND_LOGICO
%left TK_EQ TK_NE
%left TK_LT TK_GT TK_LE TK_GE
%left SOMA SUB
%left MULT DIV MOD
%right INC DEC 
%right NOT UMINUS DEREF


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start program

%%

elemento_programa:
      funcao { $$ = $1; }
    | declaracao { $$ = $1; }
    | MAIN APARENTESE FPARENTESE bloco { 
          inserir("main", "int", yylineno); 
          $$ = create_func_node("int", "main", "", $4); 
      }
    | tipo MAIN APARENTESE FPARENTESE bloco { 
          inserir("main", $1, yylineno); 
          $$ = create_func_node($1, "main", "", $5); 
      }
;

program:
      elemento_programa { 
          $$ = $1; 
          global_ast_root = $$; 
      }
    | program elemento_programa { 
          $$ = create_program_node($1, $2); 
          global_ast_root = $$; 
      }
;

funcao:
      tipo ID APARENTESE { entrar_escopo(); } parametros FPARENTESE bloco_da_funcao {
          $$ = create_func_node($1, $2, $5, $7);
      }
    | modificadores tipo ID APARENTESE { entrar_escopo(); } parametros FPARENTESE bloco_da_funcao {
        $$ = create_func_node($2, $3, $6, $8); 
    }
;

bloco_da_funcao:
    ACHAVE lista_comandos FCHAVE {
        /*fprintf(stderr, "\n=== TABELA DE SÍMBOLOS DA FUNÇÃO ===\n");*/
        /*imprimir_tabela();*/
        
        sair_escopo();
        $$ = create_block_node($2);
    }
;

bloco:
    ACHAVE { entrar_escopo(); } lista_comandos FCHAVE { 
        sair_escopo(); 
        $$ = create_block_node($3);
    }
;

lista_comandos:
    { $$ = NULL; }
    | lista_comandos comando {
          if ($1 == NULL) {
              $$ = $2;
          } else {
              ASTNode* curr = $1;
              while (curr->next != NULL) {
                  curr = curr->next;
              }
              curr->next = $2;
              $$ = $1;
          }
      }
;

comando:
      declaracao         { $$ = $1; }
    | atribuicao         { $$ = $1; }
    | selecao            { $$ = $1; }
    | retorno            { $$ = $1; }
    | bloco              { $$ = $1; }
    | expressao PONTO_VIRGULA { $$ = $1; }
    | comentario         { $$ = NULL; } 
    | definicao_struct   { $$ = NULL; }
    | WHILE APARENTESE expressao FPARENTESE comando {
          $$ = create_while_node($3, $5);
      }
    | BREAK PONTO_VIRGULA {
          $$ = create_break_node();
      }
    | CONTINUE PONTO_VIRGULA {
          $$ = create_continue_node();
      }
    | FOR APARENTESE for_init PONTO_VIRGULA for_cond PONTO_VIRGULA for_incr FPARENTESE comando {
        $$ = create_for_node($3, $5, $7, $9);
    }

    | acesso_array ATRIB expressao PONTO_VIRGULA {
         $$ = create_array_assign_node_v2($1, $3);
    }
;

tipo:
      INT    { $$ = "int"; }
    | FLOAT  { $$ = "float"; }
    | CHAR   { $$ = "char"; }
    | DOUBLE { $$ = "double"; }
    | VOID   { $$ = "void"; }
    | STRUCT ID {
        asprintf(&$$, "struct %s", $2);
    }
;


parametros:
    { $$ = strdup(""); }
    | parametro   { $$ = $1; }
    | parametros VIRGULA parametro { asprintf(&$$, "%s, %s", $1, $3); }
;

parametro:
    tipo ID {
        inserir($2, $1, yylineno);
        $$ = strdup($2);
    }

modificadores:
      CONST
    | STATIC
    | CONST STATIC
    | STATIC CONST
;

declaracao:
    tipo ID PONTO_VIRGULA {
          inserir($2, $1, yylineno);
          $$ = create_decl_node($1, $2, NULL);
      }
    | tipo ID ATRIB expressao PONTO_VIRGULA {
          inserir($2, $1, yylineno);
          $$ = create_decl_node($1, $2, $4);
      }
      
    | modificadores tipo ID PONTO_VIRGULA {
          inserir($3, $2, yylineno); 
          $$ = create_decl_node($2, $3, NULL);
      }
    | modificadores tipo ID ATRIB expressao PONTO_VIRGULA { 
          inserir($3, $2, yylineno); 
          $$ = create_decl_node($2, $3, $5);
      }

    | declaracao_array {
          $$ = $1;
      }

    | tipo MULT ID PONTO_VIRGULA {
        inserir_ponteiro($3, $1, yylineno);
        $$ = create_pointer_decl_node($1, $3, NULL);
      }

    | tipo MULT ID ATRIB BIT_AND expressao PONTO_VIRGULA {
        inserir_ponteiro($3, $1, yylineno);
        $$ = create_pointer_decl_node($1, $3, create_address_node($6));
      }
;

atribuicao:
      ID ATRIB expressao PONTO_VIRGULA {

        if (buscar($1) == NULL) {
            fprintf(stderr,
                "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n",
                yylineno,
                $1);
            exit(1);
        }
        $$ = create_assign_node($1, "=", $3);
    }

    | ID SOMA_ATRIB expressao PONTO_VIRGULA {

       if (buscar($1) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1);
            exit(1);
        }
        $$ = create_assign_node($1, "+=", $3);
    }
    | ID SUB_ATRIB expressao PONTO_VIRGULA { 
        if (buscar($1) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1);
            exit(1);
        }
        $$ = create_assign_node($1, "-=", $3); 
    }
    | ID MULT_ATRIB expressao PONTO_VIRGULA {
        if (buscar($1) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1);
            exit(1);
        }
        $$ = create_assign_node($1, "*=", $3);
    }
    | ID DIV_ATRIB expressao PONTO_VIRGULA {
        if (buscar($1) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1);
            exit(1);
        }
        $$ = create_assign_node($1, "/=", $3);
    }
    | ID MOD_ATRIB expressao PONTO_VIRGULA {
        if (buscar($1) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1);
            exit(1);
        }
        $$ = create_assign_node($1, "%=", $3);
    }

    | ID INC PONTO_VIRGULA {
        if (buscar($1) == NULL) { fprintf(stderr, "Erro Semantico...\n"); exit(1); }
        $$ = create_assign_node($1, "+=", create_literal_node("1"));
    }

    | ID DEC PONTO_VIRGULA {
        if (buscar($1) == NULL) { fprintf(stderr, "Erro Semantico...\n"); exit(1); }
        $$ = create_assign_node($1, "-=", create_literal_node("1"));
    }

    | MULT ID ATRIB expressao PONTO_VIRGULA {
        Simbolo *s = buscar($2);
        if (s == NULL) {fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $2); exit(1);}
        if (s->categoria != SIM_PONTEIRO) {fprintf(stderr,"Erro Semantico na linha %d: '%s' nao e um ponteiro, nao pode ser desreferenciado.\n", yylineno, $2); exit(1);}
        $$ = create_pointer_assign_node(create_id_node($2), $4);
    }
;

selecao:
      IF APARENTESE expressao FPARENTESE comando %prec LOWER_THAN_ELSE {
          $$ = create_if_node($3, $5, NULL);
      }
    | IF APARENTESE expressao FPARENTESE comando ELSE comando {
          $$ = create_if_node($3, $5, $7);
      }
;

comentario:
      COMMENT_LINE
    | COMMENT_BLOCK
;

definicao_struct:
    STRUCT ID ACHAVE lista_comandos FCHAVE PONTO_VIRGULA {
        $$ = NULL; 
    }
;

retorno:
    RETURN expressao PONTO_VIRGULA {
        $$ = create_return_node($2);
    }
;

expressao:
      NUM           { $$ = create_literal_node($1); }
    | ID {
        if (buscar($1) == NULL) {
            fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1);
            exit(1);
        }
        $$ = create_id_node($1);
    }
    | chamada_funcao { $$ = $1; } 
    | STR_LITERAL   { $$ = create_literal_node($1); }
    | CHAR_LITERAL  { $$ = create_literal_node($1); }
    | expressao SOMA expressao { $$ = create_binary_op_node("+", $1, $3); }
    | expressao SUB expressao  { $$ = create_binary_op_node("-", $1, $3); }
    | expressao MULT expressao { $$ = create_binary_op_node("*", $1, $3); }
    | expressao DIV expressao  { $$ = create_binary_op_node("/", $1, $3); }
    | expressao MOD expressao  { $$ = create_binary_op_node("%", $1, $3); }
    | expressao TK_EQ expressao { $$ = create_binary_op_node("==", $1, $3); }
    | expressao TK_NE expressao { $$ = create_binary_op_node("!=", $1, $3); }
    | expressao TK_LE expressao { $$ = create_binary_op_node("<=", $1, $3); }
    | expressao TK_GE expressao { $$ = create_binary_op_node(">=", $1, $3); }
    | expressao TK_LT expressao { $$ = create_binary_op_node("<", $1, $3); }
    | expressao TK_GT expressao { $$ = create_binary_op_node(">", $1, $3); }
    | expressao AND_LOGICO expressao { $$ = create_binary_op_node("&&", $1, $3); }
    | expressao OR_LOGICO expressao  { $$ = create_binary_op_node("||", $1, $3); }
    | APARENTESE expressao FPARENTESE { $$ = $2; }
    | NOT expressao { $$ = create_unary_op_node("!", $2); }
    | SUB expressao %prec UMINUS { $$ = create_unary_op_node("-", $2); }
    | acesso_array { $$ = $1; }
    | BIT_AND ID { $$ = create_address_node(create_id_node($2)); }
    | MULT expressao %prec DEREF { $$ = create_deref_node($2); }
;

chamada_funcao:
    ID APARENTESE argumentos FPARENTESE {
        char* llamada_str;
        asprintf(&llamada_str, "%s(%s)", $1, $3);
        $$ = create_literal_node(llamada_str);
        free(llamada_str);
    }
;

argumentos:
    { $$ = strdup(""); }
    | expressao { 
          $$ = strdup($1 && $1->value ? $1->value : ""); 
      }
    | argumentos VIRGULA expressao { 
          asprintf(&$$, "%s, %s", $1, ($3 && $3->value ? $3->value : "")); 
      }
;

for_init:
      /* vazio */ { $$ = NULL; }
    | tipo ID {
          inserir($2, $1, yylineno);
          $$ = create_decl_node($1, $2, NULL);
      }
    | tipo ID ATRIB expressao {
          inserir($2, $1, yylineno);
          $$ = create_decl_node($1, $2, $4);
      }
    | ID ATRIB expressao {
          if (buscar($1) == NULL) { fprintf(stderr, "Erro Semantico na linha %d: Variavel '%s' nao declarada.\n", yylineno, $1); exit(1); }
          $$ = create_assign_node($1, "=", $3);
      }
;

for_cond:
    { $$ = NULL; }
    | expressao   { $$ = $1; }
;

for_incr:
    { $$ = NULL; }
    | ID ATRIB expressao { $$ = create_assign_node($1, "=", $3); }
    | ID SOMA_ATRIB expressao { $$ = create_assign_node($1, "+=", $3); }
    | ID SUB_ATRIB expressao { $$ = create_assign_node($1, "-=", $3); }
    | ID INC { $$ = create_assign_node($1, "+=", create_literal_node("1")); }
    | ID DEC { $$ = create_assign_node($1, "-=", create_literal_node("1")); }
;

declaracao_array:
      tipo ID lista_dimensoes PONTO_VIRGULA {
          inserir_array($2, $1, 0, yylineno);;
          $$ = create_multi_array_decl_node($1, $2, $3, NULL);
      }
    | tipo ID lista_dimensoes ATRIB ACHAVE lista_init FCHAVE PONTO_VIRGULA {
          inserir_array($2, $1, 0, yylineno);
          $$ = create_multi_array_decl_node($1, $2, $3, $6);
      }
;

lista_dimensoes:
      A_COLCHETE NUM F_COLCHETE {
          $$ = create_dimension_node(atoi($2), NULL);
      }
    | lista_dimensoes A_COLCHETE NUM F_COLCHETE {
          // Anexa a nova dimensão no final da lista de dimensões
          ASTNode* curr = $1;
          while (curr->next != NULL) curr = curr->next;
          curr->next = create_dimension_node(atoi($3), NULL);
          $$ = $1;
      }
;

acesso_array:
      ID lista_indices {
          if (buscar($1) == NULL) {fprintf(stderr, "Erro Semantico na linha %d: array '%s' nao declarado.\n", yylineno, $1);
              exit(1);
          }
          $$ = create_multi_array_access_node($1,$2);
      }
;

lista_indices:
      A_COLCHETE expressao F_COLCHETE {
          $$ = create_index_node($2, NULL);
      }
    | lista_indices A_COLCHETE expressao F_COLCHETE {
          ASTNode* curr = $1;
          while (curr->next != NULL) curr = curr->next;
          curr->next = create_index_node($3, NULL);
          $$ = $1;
      }
;

lista_init:
      expressao {$$ = $1;}
    | lista_init VIRGULA expressao {ASTNode* curr = $1; while (curr->next != NULL) curr = curr->next; curr->next = $3; $$ = $1;
      }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d perto de '%s'\n", yylineno, yytext);
    exit(1);
}
