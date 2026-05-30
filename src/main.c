#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include "tabela.h"
#include "common.h"
#include "ast.h"
#include "semantic.h"

extern int yyparse();
extern FILE* yyin;
extern ASTNode* global_ast_root; 

int main(int argc, char** argv) {
    inicializar_tabela_simbolos();
    if (argc > 1) {
        FILE* file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Erro ao abrir o arquivo: %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    } else {
        fprintf(stderr, "Aguardando entrada (Ctrl+D para finalizar):\n");
    }

    int result = yyparse();
    fflush(stdout);

    if (result == 0) {        
        fprintf(stderr, "\n=== VISUALIZAÇÃO GRÁFICA DA AST ===\n");
        
        fflush(stdout);
        int stdout_backup = dup(1); 
        dup2(2, 1);                

        print_ast(global_ast_root, 0);
        fflush(stdout); 

        fprintf(stderr, "===================================\n\n");
       
        imprimir_historico_completo();
        
        fflush(stdout);
        dup2(stdout_backup, 1);     
        close(stdout_backup);

        fprintf(stderr, "===================================\n\n");

        /* ---- Análise Semântica de Tipos ---- */
        analisar_semantico(global_ast_root);

        generate_python(global_ast_root, 0);
        
    } else {
        fprintf(stderr, "\n[ERRO] Falha na análise.\n");
    }

    if (argc > 1 && yyin) {
        fclose(yyin);
    }

    return result;
}