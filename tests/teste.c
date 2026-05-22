int calcular_desconto(int valor) {
    int resultado = 0;
    
    if (valor > 100) {
        resultado = valor - 20;
    } else {
        resultado = valor - 5;
    }
    
    return resultado;
}

int main() {
    int preco = 150;
    int preco_final = 0;
    
    preco_final = calcular_desconto(preco);
    
    return 0;
}