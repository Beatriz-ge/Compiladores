int main() {
    int x = 10;
    int *p = &x;
    *p = 20;
    printf(*p);
    return 0;
}
