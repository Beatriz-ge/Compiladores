#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "diagnostics.h"

static int total_erros = 0;
static int total_avisos = 0;

void emitir_diagnostico(TipoDiagnostico tipo, int linha, const char *mensagem) {
    switch(tipo) {
        case DIAG_LEXICO:
            fprintf(stderr, "[ERRO LEXICO] \nLinha %d\n%s\n\n", linha, mensagem);
            total_erros++;
            break;
        case DIAG_SINTATICO:
            fprintf(stderr, "[ERRO SINTATICO] \nLinha %d\n%s\n\n", linha, mensagem);
            total_erros++;
            break;
        case DIAG_SEMANTICO:
            fprintf(stderr, "[ERRO SEMANTICO] \nLinha %d\n%s\n\n", linha, mensagem);
            total_erros++;
            break;
        case DIAG_AVISO:
            fprintf(stderr, "[AVISO] \nLinha %d\n%s\n\n", linha, mensagem);
            total_avisos++;
            break;
    }
}

void emitir_erro_lexico(int linha, const char *msg) {
    emitir_diagnostico(DIAG_LEXICO, linha, msg);
}

void emitir_erro_sintatico(int linha, const char *token, const char *msg) {
    char buffer[512];
    snprintf(buffer, sizeof(buffer), "Mensagem: %s\nToken encontrado: '%s'", msg, token);
    emitir_diagnostico(DIAG_SINTATICO, linha, buffer);
}

void emitir_erro_semantico(int linha, const char *msg) {
    emitir_diagnostico(DIAG_SEMANTICO, linha, msg);
}

void emitir_aviso(int linha, const char *msg) {
    emitir_diagnostico(DIAG_AVISO, linha, msg);
}