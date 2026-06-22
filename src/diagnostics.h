#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

typedef enum {
    DIAG_LEXICO,
    DIAG_SINTATICO,
    DIAG_SEMANTICO,
    DIAG_AVISO
} TipoDiagnostico;

void emitir_diagnostico(
    TipoDiagnostico tipo,
    int linha,
    const char *mensagem
);

void emitir_erro_lexico(
    int linha,
    const char *mensagem
);

void emitir_erro_sintatico(
    int linha,
    const char *token,
    const char *mensagem
);

void emitir_erro_semantico(
    int linha,
    const char *mensagem
);

void emitir_aviso(
    int linha,
    const char *mensagem
);

#endif