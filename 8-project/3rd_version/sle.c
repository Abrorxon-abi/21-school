#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR 1

double** alloc(int row, int column) {
    double** arr = (double**)malloc(row * column * sizeof(double) + row * sizeof(double*));
    double* ptr = (double*)(arr + row);
    for (int r = 0; r < row; r++) {
        arr[r] = ptr + column * r;
    }
    return arr;
}

int main() {
    int STATUS = OK;
    int n, m;
    scanf("%d%d", &n, &m);
    if (n != m - 1) STATUS = ERROR;
    double** A = alloc(n + 1, m + 1);
    if (STATUS == OK) {
        double c, x[n];
        int i, j, k;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= (n + 1); j++) {
                scanf("%lf", &A[i][j]);
            }
        }
        for (j = 1; j <= n; j++) {
            for (i = 1; i <= n; i++) {
                if (i > j) {
                    c = A[i][j] / A[j][j];
                    for (k = 1; k <= n + 1; k++) {
                        A[i][k] = A[i][k] - c * A[j][k];
                    }
                }
            }
        }
        if (A[n][n] == 0) STATUS = ERROR;
        if (STATUS == OK) {
            x[n] = A[n][n + 1] / A[n][n];
            for (i = n - 1; i >= 1; i--) {
                double sum = 0;
                for (j = i + 1; j <= n; j++) {
                    sum = sum + A[i][j] * x[j];
                }
                if (A[i][i] == 0)
                    STATUS = ERROR;
                else
                    x[i] = (A[i][n + 1] - sum) / A[i][i];
            }
            if (STATUS == OK) {
                for (i = 1; i <= n; i++) {
                    printf("%.6lf", x[i]);
                    if (i != n) printf(" ");
                }
            }
        }
    }
    free(A);
    if (STATUS == ERROR) printf("n/a");
    return 0;
}