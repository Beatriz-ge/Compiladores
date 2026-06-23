int eh_espaco(char c) {
    if (c == ' ') {
        return 1;
    }
    return 0;
}

int contar_palavras(char s[], int n) {
    int count = 0;
    int dentro = 0;
    int i = 0;
    while (i < n) {
        if (eh_espaco(s[i])) {
            dentro = 0;
        } else {
            if (dentro == 0) {
                count = count + 1;
                dentro = 1;
            }
        }
        i = i + 1;
    }
    return count;
}

int main() {
    char frase[20];
    frase[0]  = 'o';
    frase[1]  = 'l';
    frase[2]  = 'a';
    frase[3]  = ' ';
    frase[4]  = 'm';
    frase[5]  = 'u';
    frase[6]  = 'n';
    frase[7]  = 'd';
    frase[8]  = 'o';
    frase[9]  = ' ';
    frase[10] = 'c';
    frase[11] = ' ';
    frase[12] = '\0';

    int r = contar_palavras(frase, 12);
    return 0;
}