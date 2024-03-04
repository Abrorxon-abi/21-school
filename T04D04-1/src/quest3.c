#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("n/a\n");
        return 1;
    }

    int result = fibonacci(n);
    printf("%d\n", result);
    return 0;
}