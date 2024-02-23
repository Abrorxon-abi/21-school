// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// int dynamic(int ***a, int *n, int *m);
// void dynam(int ***a, int n, int m);
// int input(int ***a, int n, int m);
// void output(int **a, int n, int m);
// int symbolCorrect(char symbol);
// int sizeCorrect(int s);

// double matrixDet(int **matrix, int size);
// void getMatrixWithoutRowAndCol(int **matrix, int size, int row, int col,
//                                int ***newMatrix);
// int main() {
//   int **matrix;
//   int n, m;

//   if (dynamic(&matrix, &n, &m)) {
//     double d = matrixDet(matrix, n);
//     printf("%.6lf", d);
//     for (int i = 0; i < n; i++) free(matrix[i]);
//     free(matrix);
//   } else {
//     if (n != 0 && m != 0) {
//       for (int i = 0; i < n; i++) free(matrix[i]);
//       free(matrix);
//     }
//     printf("n/a");
//   }
// }

// int symbolCorrect(char symbol) {
//   return symbol == ' ' || symbol == '\n' || symbol == EOF ? 1 : 0;
// }
// int sizeCorrect(int s) { return s > 0 ? 1 : 0; }

// int dynamic(int ***a, int *n, int *m) {
//   char symbol;
//   int check = 1;
//   if (scanf("%d %d%c", n, m, &symbol) == 3 && sizeCorrect(*n) &&
//       sizeCorrect(*m) && symbolCorrect(symbol)) {
//     dynam(a, *n, *m);
//     check = input(a, *n, *m);
//   } else {
//     check = 0;
//   }
//   return check;
// }

// void dynam(int ***a, int n, int m) {
//   (*a) = malloc(n * sizeof(int *));
//   for (int i = 0; i < n; i++) {
//     (*a)[i] = malloc(m * sizeof(int));
//   }
// }

// int input(int ***a, int n, int m) {
//   char symbol;
//   int el;
//   int check = 1;
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       if (scanf("%d%c", &el, &symbol) == 2 && symbolCorrect(symbol)) {
//         (*a)[i][j] = el;
//       } else {
//         check = 0;
//         break;
//       }
//     }
//   }
//   return check;
// }

// void output(int **a, int n, int m) {
//   for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++) {
//       if (j != m - 1)
//         printf("%d ", a[i][j]);
//       else
//         printf("%d", a[i][j]);
//     }
//     if (i != n - 1) printf("\n");
//   }
// }

// void getMatrixWithoutRowAndCol(int **matrix, int size, int row, int col,
//                                int ***newMatrix) {
//   int offsetRow = 0;
//   int offsetCol = 0;
//   for (int i = 0; i < size - 1; i++) {
//     if (i == row) offsetRow = 1;
//     offsetCol = 0;
//     for (int j = 0; j < size - 1; j++) {
//       if (j == col) offsetCol = 1;
//       (*newMatrix)[i][j] = matrix[i + offsetRow][j + offsetCol];
//     }
//   }
// }

// double matrixDet(int **matrix, int size) {
//   int det = 0;
//   int degree = 1;
//   if (size == 1) {
//     return matrix[0][0];
//   } else if (size == 2) {
//     return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
//   } else {
//     int **newMatrix;
//     dynam(&newMatrix, size - 1, size - 1);

//     for (int j = 0; j < size; j++) {
//       getMatrixWithoutRowAndCol(matrix, size, 0, j, &newMatrix);
//       det = det + (degree * matrix[0][j] * matrixDet(newMatrix, size - 1));
//       degree *= -1;
//     }
//     for (int i = 0; i < size - 1; i++) free(newMatrix[i]);
//     free(newMatrix);
//   }

//   return det;
// }

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int dynamic(int ***a, int *n, int *m);
void dynam(int ***a, int n, int m);
int input(int ***a, int n, int m);
void output(int **a, int n, int m);
int symbolCorrect(char symbol);
int sizeCorrect(int s);

double matrixDet(int **matrix, int size);
void getMatrixWithoutRowAndCol(int **matrix, int size, int row, int col, int ***newMatrix);
int main() {
    int **matrix;
    int n, m;

    if (dynamic(&matrix, &n, &m)) {
        double d = matrixDet(matrix, n);
        printf("%.6lf", d);
        for (int i = 0; i < n; i++) free(matrix[i]);
        free(matrix);
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

int dynamic(int ***a, int *n, int *m) {
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

void dynam(int ***a, int n, int m) {
    (*a) = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        (*a)[i] = malloc(m * sizeof(int));
    }
}

int input(int ***a, int n, int m) {
    char symbol;
    int el;
    int check = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d%c", &el, &symbol) == 2 && symbolCorrect(symbol)) {
                (*a)[i][j] = el;
            } else {
                check = 0;
                break;
            }
        }
    }
    return check;
}

void output(int **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != m - 1)
                printf("%d ", a[i][j]);
            else
                printf("%d", a[i][j]);
        }
        if (i != n - 1) printf("\n");
    }
}

void getMatrixWithoutRowAndCol(int **matrix, int size, int row, int col, int ***newMatrix) {
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

double matrixDet(int **matrix, int size) {
    int det = 0;
    int degree = 1;
    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        int **newMatrix;
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