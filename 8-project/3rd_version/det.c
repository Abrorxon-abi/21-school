#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
void input(double ***matrix, int *n);
void output(double det, int n);

int main() {
    int n;
    double **matrix;
    double determinant = 0;

    input(&matrix, &n);
    if (n != 1) {
        determinant = det(matrix, n);

        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }
    output(determinant, n);
    return 0;
}

double det(double **matrix, int n) {
    int i, j, k;
    double det = 1.0;
    double temp;

    for (i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            int found = 0;
            for (j = i + 1; j < n; j++) {
                if (matrix[j][i] != 0) {
                    found = 1;
                    for (k = i; k < n; k++) {
                        temp = matrix[i][k];
                        matrix[i][k] = matrix[j][k];
                        matrix[j][k] = temp;
                    }
                    det *= -1.0;
                    break;
                }
            }
            if (found == 0) {
                return 0.0;
            }
        }
        for (j = i + 1; j < n; j++) {
            temp = matrix[j][i] / matrix[i][i];
            for (k = i; k < n; k++) {
                matrix[j][k] -= matrix[i][k] * temp;
            }
        }
        det *= matrix[i][i];
    }

    return det;
}

void input(double ***matrix, int *n) {
    int m;
    scanf("%d %d", n, &m);
    if (m != *n && *n < 0) *n = -1;
    if (*n != -1) {
        int i, j;
        *matrix = (double **)malloc(*n * sizeof(double *));
        for (i = 0; i < *n; i++) {
            (*matrix)[i] = (double *)malloc(*n * sizeof(double));
        }

        for (i = 0; i < *n; i++) {
            for (j = 0; j < *n; j++) {
                scanf("%lf", &(*matrix)[i][j]);
            }
        }
    }
}

void output(double det, int n) {
    if (n == -1) {
        printf("n/a");
    } else {
        printf("%.6lf", det);
    }
}