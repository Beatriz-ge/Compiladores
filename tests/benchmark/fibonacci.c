int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0;
    int b = 1;
    int i = 2;
    while (i <= n) {
        int temp = b;
        b = a + b;
        a = temp;
        i = i + 1;
    }
    return b;
}

int main() {
    int i = 0;
    while (i < 10) {
        int r = fibonacci(i);
        i = i + 1;
    }
    return 0;
}