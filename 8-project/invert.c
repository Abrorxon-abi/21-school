#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int dynamic(double ***a, int *n, int *m);
void dynam(double ***a, int n, int m);
int input(double ***a, int n, int m);
void output(double **a, int n, int m);
int symbolCorrect(char symbol);
int sizeCorrect(int s);

void algDop(double **matrix, int n, double **res);
double matrixDet(double **matrix, int size);
void getMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double ***newMatrix);
void transp(double **a, int n, int m, double ***res);
void mul(double **a, int n, int m, double d);

int main() {
    double **matrix;
    int n, m;

    if (dynamic(&matrix, &n, &m)) {
        double d = matrixDet(matrix, n);
        if (d != 0) {
            double **res;
            dynam(&res, n, n);
            algDop(matrix, n, res);
            transp(res, n, n, &res);
            mul(res, n, n, 1 / d);
            output(res, n, n);

            for (int i = 0; i < n; i++) free(res[i]);
            free(res);

            for (int i = 0; i < n; i++) free(matrix[i]);
            free(matrix);
        } else {
            printf("n/a");
        }
    } else {
        if (n != 0 && m != 0) {
            for (int i = 0; i < n; i++) free(matrix[i]);
            free(matrix);
        }
        printf("n/a");
    }
}

int symbolCorrect(char symbol) { return symbol == ' ' || symbol == '\n' || symbol == EOF ? 1 : 0; }
int sizeCorrect(int s) { return s > 0 ? 1 : 0; }

int dynamic(double ***a, int *n, int *m) {
    char symbol;
    int check = 1;
    if (scanf("%d %d%c", n, m, &symbol) == 3 && sizeCorrect(*n) && sizeCorrect(*m) && symbolCorrect(symbol)) {
        dynam(a, *n, *m);
        check = input(a, *n, *m);
    } else {
        check = 0;
    }
    return check;
}

void dynam(double ***a, int n, int m) {
    (*a) = malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        (*a)[i] = malloc(m * sizeof(double));
    }
}

int input(double ***a, int n, int m) {
    double el;
    int check = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%lf", &el)) {
                (*a)[i][j] = el;
            } else {
                check = 0;
                break;
            }
        }
    }
    return check;
}

void output(double **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != m - 1)
                printf("%.6lf ", a[i][j]);
            else
                printf("%.6lf", a[i][j]);
        }
        if (i != n - 1) printf("\n");
    }
}

void algDop(double **matrix, int n, double **res) {
    double **newMatrix;
    dynam(&newMatrix, n - 1, n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            getMatrixWithoutRowAndCol(matrix, n, i, j, &newMatrix);
            res[i][j] = pow(-1, i + 2 + j) * matrixDet(newMatrix, n - 1);
        }
    }
    for (int i = 0; i < n - 1; i++) free(newMatrix[i]);
    free(newMatrix);
}

void getMatrixWithoutRowAndCol(double **matrix, int size, int row, int col, double ***newMatrix) {
    int offsetRow = 0;
    int offsetCol = 0;
    for (int i = 0; i < size - 1; i++) {
        if (i == row) offsetRow = 1;
        offsetCol = 0;
        for (int j = 0; j < size - 1; j++) {
            if (j == col) offsetCol = 1;
            (*newMatrix)[i][j] = matrix[i + offsetRow][j + offsetCol];
        }
    }
}

double matrixDet(double **matrix, int size) {
    int det = 0;
    int degree = 1;
    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        double **newMatrix;
        dynam(&newMatrix, size - 1, size - 1);

        for (int j = 0; j < size; j++) {
            getMatrixWithoutRowAndCol(matrix, size, 0, j, &newMatrix);
            det = det + (degree * matrix[0][j] * matrixDet(newMatrix, size - 1));
            degree *= -1;
        }
        for (int i = 0; i < size - 1; i++) free(newMatrix[i]);
        free(newMatrix);
    }

    return det;
}

void transp(double **a, int n, int m, double ***res) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            (*res)[j][i] = a[i][j];
        }
    }
}

void mul(double **a, int n, int m, double d) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] *= d;
        }
    }
}