#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int largestPrimeDivisor(int a) {
    if (a < 0) {
        a = -a;
    }

    for (int i = a / 2; i >= 2; i--) {
        if (a % i == 0 && isPrime(i)) {
            return i;
        }
    }

    return 0;
}

int main() {
    int a;
    scanf("%d", &a);

    int result = largestPrimeDivisor(a);

    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("n/a\n");
    };

    return 0;
}