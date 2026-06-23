float potencia(float base, int exp) {
    if (exp == 0) {
        return 1.0;
    }
    float resultado = 1.0;
    int i = 0;
    while (i < exp) {
        resultado = resultado * base;
        i = i + 1;
    }
    return resultado;
}

int main() {
    float r1 = potencia(2.0, 10);
    float r2 = potencia(3.0, 5);
    float r3 = potencia(1.5, 4);
    return 0;
}
