#include <stdio.h>

#define N 10

int input(int *a, int n);
void bubble_sort(int *a, int n);
void output(int *a, int n);

int main() {
    int data[N];

    if (input(data, N)) {
        bubble_sort(data, N);
        output(data, N);
    } else {
        printf("n/a\n");
    }

    return 0;
}

int input(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 0;  // Invalid input
        }
    }

    return 1;  // Input successfully read
}

void bubble_sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap a[j] and a[j + 1]
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
    printf("\n");
}
