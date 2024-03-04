#include <stdio.h>

int sum(int a, int b);
int difference(int a, int b);
int product(int a, int b);
int quotient(int a, int b);

int main() {
    int num1, num2;

    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("n/a\n");
        return 0;
    }

    printf("%d %d %d ", sum(num1, num2), difference(num1, num2), product(num1, num2));
    if (num2 == 0) {
        printf("n/a\n");
    } else {
        printf("%d\n", quotient(num1, num2));
    }

    return 0;
}

int sum(int a, int b) {
    return a + b;
}

int difference(int a, int b) {
    return a - b;
}

int product(int a, int b) {
    return a * b;
}

int quotient(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        return 0;
    }
}