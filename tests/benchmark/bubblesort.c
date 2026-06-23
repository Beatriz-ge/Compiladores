int main() {
    int n = 8;
    int v[8];
    v[0] = 64;
    v[1] = 34;
    v[2] = 25;
    v[3] = 12;
    v[4] = 22;
    v[5] = 11;
    v[6] = 90;
    v[7] = 1;

    int i = 0;
    while (i < n - 1) {
        int j = 0;
        while (j < n - i - 1) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return 0;
}