#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

/* Find max & min probabilities */
int main() {
    int x, y, z;
    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        printf("n/a\n");
        return 1;
    }

    if (x == y && y == z) {
        printf("n/a\n");
        return 1;
    }

    int max, min;

    maxmin(x, y, z, &max, &min);

    printf("%d %d\n", max, min);

    return 0;
}

/* This function should be kept !!! (Your AI) */
/* But errors & bugs should be fixed         */
void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
    if (prob1 == prob2 && prob2 == prob3) {
        *max = *min = prob1;
    } else {
        *max = *min = prob1;

        if (prob2 > *max) *max = prob2;
        if (prob2 < *min) *min = prob2;

        if (prob3 > *max) *max = prob3;
        if (prob3 < *min) *min = prob3;
    }
}
