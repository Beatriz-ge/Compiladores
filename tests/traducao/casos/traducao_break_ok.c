int main() {
    int i = 0;
    while (i < 10) {
        if (i == 3) {
            break;
        }
        i = i + 1;
    }
    printf(i);
    return 0;
}