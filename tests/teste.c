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