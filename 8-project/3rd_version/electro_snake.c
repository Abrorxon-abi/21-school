#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);
void input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);

int main() {
    int **matrix;
    int n, m;

    input(&matrix, &n, &m);
    if (m != -1) {
        int **result;
        result = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            result[i] = (int *)malloc(m * sizeof(int));
        }

        sort_vertical(matrix, n, m, result);
        output(result, n, m);

        printf("\n\n");

        sort_horizontal(matrix, n, m, result);
        output(result, n, m);

        for (int i = 0; i < n; i++) {
            free(matrix[i]);
            free(result[i]);
        }
        free(result);
        free(matrix);
    }

    return 0;
}

void sort(int *a, int n) {
    int i = 0;
    int j = n - 1;

    int mid = a[n / 2];

    do {
        while (a[i] < mid) {
            i++;
        }
        while (a[j] > mid) {
            j--;
        }
        if (i <= j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        sort(a, j + 1);
    }
    if (i < n) {
        sort(&a[i], n - i);
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int *temp = (int *)malloc(n * m * sizeof(int));
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[index++] = matrix[i][j];
        }
    }
    sort(temp, n * m);
    index = 0;
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                result_matrix[i][j] = temp[index++];
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                result_matrix[i][j] = temp[index++];
            }
        }
    }
    free(temp);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int *temp = (int *)malloc(n * m * sizeof(int));
    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[index++] = matrix[i][j];
        }
    }

    sort(temp, n * m);
    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = temp[index++];
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                result_matrix[i][j] = temp[index++];
            }
        }
    }

    free(temp);
}

void input(int ***matrix, int *n, int *m) {
    scanf("%d %d", n, m);

    if (*n <= 0 || *m <= 0) {
        printf("n/a");
        *m = -1;
    }
    if (*m != -1) {
        *matrix = (int **)malloc(*n * sizeof(int *));
        for (int i = 0; i < *n; i++) {
            (*matrix)[i] = (int *)malloc(*m * sizeof(int));
            for (int j = 0; j < *m; j++) {
                scanf("%d", &((*matrix)[i][j]));
            }
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j != m - 1) printf(" ");
        }
        if (i != n - 1) printf("\n");
    }
}