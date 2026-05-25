static int testar_escopos(int parametro_a) {
    int x;
    x = 5;
    
    {
        char x; 
        x = 'G';
        int interno_bloco;
        interno_bloco = 42;
    } 
    parametro_a = parametro_a + 1;
}

int main() {
    int i = 0;
    int parado = 0;
    
    for (i = 0; i < 5; i++) {
        if (i == 2 && !parado) {
            continue; 
        }
        int inverso = -i;
        
    }
    return 0;
}
