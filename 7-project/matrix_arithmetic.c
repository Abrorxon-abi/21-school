#include <stdio.h>
#include <stdlib.h>

int input(int *n, int *m);
int inputMatrix(int **matrix, int n, int m);
int inputChoose(int *choose);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);

int main() {
    int n_first, m_first, n_second, m_second, choose, n_result, m_result;

    if (!inputChoose(&choose)) {
        printf("n/a");
        return 0;
    }
    if (!input(&n_first, &m_first)) {
        printf("n/a");
        return 0;
    }
    int **matrix_first = malloc(n_first * m_first * sizeof(int) + n_first * sizeof(int *));
    if (!inputMatrix(matrix_first, n_first, m_first)) {
        printf("n/a");
        return 0;
    }
    switch (choose) {
        case 1:
            if (!input(&n_second, &m_second)) {
                printf("n/a");
                return 0;
            }
            int **matrix_second_sum = malloc(n_second * m_second * sizeof(int) + n_second * sizeof(int *));
            if (!inputMatrix(matrix_second_sum, n_second, m_second)) {
                printf("n/a");
                return 0;
            }

            int **matrix_result_sum = malloc(n_second * m_second * sizeof(int) + n_second * sizeof(int *));
            int *ptr_sum = (int *)(matrix_result_sum + n_second);
            for (int i = 0; i < n_second; i++) {
                matrix_result_sum[i] = ptr_sum + m_second * i;
            }
            if (!sum(matrix_first, n_first, m_first, matrix_second_sum, n_second, m_second, matrix_result_sum,
                     &n_result, &m_result)) {
                printf("n/a");
                return 0;
            }
            output(matrix_result_sum, n_result, m_result);
            free(matrix_second_sum);

            break;
        case 2:
            if (!input(&n_second, &m_second)) {
                printf("n/a");
                return 0;
            }
            int **matrix_second_mul = malloc(n_second * m_second * sizeof(int) + n_second * sizeof(int *));
            if (!inputMatrix(matrix_second_mul, n_second, m_second)) {
                printf("n/a");
                return 0;
            }

            int **matrix_result_mul = malloc(n_first * m_second * sizeof(int) + n_first * sizeof(int *));
            int *ptr_mul = (int *)(matrix_result_mul + n_first);
            for (int i = 0; i < n_first; i++) {
                matrix_result_mul[i] = ptr_mul + m_second * i;
            }
            if (!mul(matrix_first, n_first, m_first, matrix_second_mul, n_second, m_second, matrix_result_mul,
                     &n_result, &m_result)) {
                printf("n/a");
                return 0;
            }
            output(matrix_result_mul, n_result, m_result);
            free(matrix_second_mul);

            break;
        case 3:

            transpose(matrix_first, n_first, m_first);

            break;
        default:
            break;
    }
    free(matrix_first);
    return 0;
}

int input(int *n, int *m) {
    float fcol;
    if (scanf("%d%f", n, &fcol) != 2 || fcol != (float)((int)fcol)) {
        return 0;
    }
    *m = (int)fcol;
    return 1;
}

int inputMatrix(int **matrix, int n, int m) {
    int *ptr = (int *)(matrix + n);
    for (int i = 0; i < n; i++) {
        matrix[i] = ptr + m * i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 0;
            }
        }
    }
    if (getchar() != '\n') {
        return 0;
    }
    return 1;
}

int inputChoose(int *choose) {
    if (scanf("%d", choose) != 1 || *choose < 1 || *choose > 3) {
        return 0;
    }
    return 1;
}

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    if (n_first != n_second || m_first != m_second) {
        return 0;
    }
    *n_result = n_first;
    *m_result = m_first;
    for (int i = 0; i < *n_result; i++) {
        for (int j = 0; j < *m_result; j++) {
            matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
        }
    }
    return 1;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    if (m_first != n_second) {
        return 0;
    }
    *n_result = n_first;
    *m_result = m_second;
    for (int i = 0; i < *n_result; i++) {
        for (int j = 0; j < *m_result; j++) {
            matrix_result[i][j] = 0;
        }
    }
    for (int i = 0; i < n_first; i++) {
        for (int j = 0; j < m_second; j++) {
            for (int k = 0; k < m_first; k++) {
                matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }
    return 1;
}

int transpose(int **matrix, int n, int m) {
    int **matrix_result = (int **)calloc(m, sizeof(int *));

    for (int i = 0; i < m; i++) {
        matrix_result[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_result[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix_result[j][i] = matrix[i][j];
        }
    }
    output(matrix_result, m, n);
    for (int i = 0; i < n; i++) {
        free(matrix_result[i]);
    }
    free(matrix_result);
    return 0;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == m - 1) {
                printf("%d", matrix[i][j]);
            } else {
                printf("%d ", matrix[i][j]);
            }
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}