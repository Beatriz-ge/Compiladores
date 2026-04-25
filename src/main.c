#include <stdio.h>
#include <stdlib.h>

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
        printf("Aguardando entrada (Ctrl+D para finalizar):\n");
    }

    int result = yyparse();

    if (result == 0) {
        printf("\n[SUCESSO] O código é sintaticamente válido.\n");
    } else {
        printf("\n[ERRO] Falha na análise sintática.\n");
    }

    return result;
}