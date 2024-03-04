/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>

#define NMAX 30

int input(int *a, int *n);
void find_desired_value(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        find_desired_value(data, n);
    } else {
        printf("n/a\n");
    }

    return 0;
}

int input(int *a, int *n) {
    if (scanf("%d", n) != 1 || *n <= 0 || *n > NMAX) {
        return 0;
    }

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 0;
        }
    }

    return 1;
}

void find_desired_value(int *a, int n) {
    double mean_value = 0.0;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    mean_value = sum / n;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] >= mean_value && a[i] <= mean_value + 3 * sqrt(variance(a, n)) &&
            a[i] != 0) {
            printf("%d\n", a[i]);
            return;
        }
    }

    printf("0\n");
}

double variance(int *a, int n) {
    double mean_value = 0.0;
    double sum_squared_diff = 0.0;

    for (int i = 0; i < n; i++) {
        mean_value += a[i];
    }

    mean_value /= n;

    for (int i = 0; i < n; i++) {
        sum_squared_diff += pow(a[i] - mean_value, 2);
    }

    return sum_squared_diff / n;
}