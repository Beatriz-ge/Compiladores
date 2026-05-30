// Caso negativo: redeclaração de variável no mesmo escopo
// Esperado: Erro Semantico — redeclaração

int main() {
    int x = 1;
    int x = 2;
    return 0;
}