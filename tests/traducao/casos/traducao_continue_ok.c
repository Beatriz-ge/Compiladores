int main() {
    int i = 0;
    int soma = 0;
    while (i < 5) {
        i = i + 1;
        if (i == 3) {
            continue;
        }
        soma = soma + i;
    }
    printf(soma);
    return 0;
}