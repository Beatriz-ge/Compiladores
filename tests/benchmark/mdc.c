int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a - (a / b) * b;
        a = temp;
    }
    return a;
}

int mmc(int a, int b) {
    return (a / mdc(a, b)) * b;
}

int main() {
    int r1 = mdc(48, 18);
    int r2 = mdc(100, 75);
    int r3 = mmc(4, 6);
    int r4 = mmc(12, 15);
    return 0;
}
