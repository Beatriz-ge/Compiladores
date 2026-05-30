int soma(int a, int b) {
    int resultado = a + b;

    if (resultado > 10) {
        resultado = resultado + 1;

        if (resultado > 20) {
            resultado = resultado + 2;
        } else {
            resultado = resultado - 2;
        }
    }

    while (resultado < 30) {
        resultado = resultado + 1;
    }

    return resultado;
}

int main() {
    int i = 0;

    for (i = 0; i < 3; i = i + 1) {
        i = i + 2;
    }

    int valor = soma(5, 10);

    if (valor > 0) {
        valor = valor + 100;
    }

    return valor;
}