#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *n);
void bubble_sort(int *a, int n);
void output(int *a, int n);

int main() {
    int *data;
    int n;

    if (input(&data, &n)) {
        bubble_sort(data, n);
        output(data, n);
        free(data);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int **a, int *n) {
    if (scanf("%d", n) != 1) {
        return 0;
    }

    *a = (int *)malloc(*n * sizeof(int));
    if (*a == NULL) {
        return 0;
    }

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &(*a)[i]) != 1) {
            free(*a);
            return 0;
        }
    }

    return 1;
}

void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}