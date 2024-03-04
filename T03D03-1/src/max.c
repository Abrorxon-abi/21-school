#include <stdio.h>

int max(int a, int b);

int main() {
    int num1, num2;

    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("n/a\n");
        return 0;
    }

    printf("%d\n", max(num1, num2));

    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
