#include <stdio.h>
#include <stdlib.h>
#include "tabela.h"

extern int yyparse();
extern FILE* yyin;

int main(int argc, char** argv) {
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
        fprintf(stderr, "\n[SUCESSO] O código é sintaticamente válido.\n");
    } else {
        fprintf(stderr, "\n[ERRO] Falha na análise sintática.\n");
    }

    return result;
}