int g_variavel = 10;
char x = 'A'; 

int testar_globais(int parametro) {
    g_variavel = g_variavel + parametro; 
    
    int x = 5; 
    x = x + 1;
    
    return x;
}

int main() {
    int resultado = 0;
    resultado = testar_globais(5);
    return 0;
}