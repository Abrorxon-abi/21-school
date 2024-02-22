#include <stdio.h>
#include <stdlib.h>
#define LEN 100

int inputN(int *n, int *row, int *colum);
int inputArry(int **a, int row, int colum);
int inputArryS(int *a, int row, int colum);
void output(int **a, int row, int colum, int n);
void outputS(int *a, int row, int colum);

int main() {
    int n, row, colum, **data, *dataI, dataS[LEN + LEN];
    if (inputN(&n, &row, &colum)) {
        switch (n) {
            case 1:
                if (inputArryS(dataS, row, colum)) {
                    outputS(dataS, row, colum);
                } else {
                    printf("n/a");
                }
                break;
            case 2:
                data = (int **)malloc(row * sizeof(int *));
                for (int i = 0; i < row; i++) data[i] = (int *)malloc(colum * sizeof(int));
                if (inputArry(data, row, colum)) {
                    output(data, row, colum, n);
                } else {
                    printf("n/a");
                }
                break;
            case 3:
                data = (int **)malloc(row * colum * sizeof(int) + sizeof(int *));
                dataI = (int *)(data + row);
                for (int i = 0; i < row; i++) data[i] = dataI + colum * i;
                if (inputArry(data, row, colum)) {
                    output(data, row, colum, n);
                } else {
                    printf("n/a");
                }
                break;
            case 4:
                data = (int **)malloc(row * sizeof(int *));
                dataI = (int *)malloc(row * colum * sizeof(int));
                for (int i = 0; i < row; i++) data[i] = dataI + colum * i;
                if (inputArry(data, row, colum)) {
                    output(data, row, colum, n);
                } else {
                    printf("n/a");
                }
                break;
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int inputN(int *n, int *row, int *colum) {
    if (!scanf("%d", n)) return 0;
    if ((int *)n != n) return 0;
    if (*n < 1 || *n > 4) return 0;
    if (getchar() != 10) return 0;

    if (!scanf("%d %d", row, colum)) return 0;
    if ((int *)row != row) return 0;
    if ((int *)colum != colum) return 0;
    if (*colum <= 0) return 0;
    if (*row <= 0) return 0;
    return 1;
}

int inputArry(int **a, int row, int colum) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colum; j++) {
            if (!scanf("%d", &a[i][j])) return 0;
            if ((int)a[i][j] != a[i][j]) return 0;
        }
        if (getchar() != 10) return 0;
    }
    return 1;
}

void output(int **a, int row, int colum, int n) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colum; j++) {
            if (i == row - 1 && j == colum - 1) {
                printf("%d", a[i][j]);
                if (n == 2) free(a[i]);
                free(a);
                return;
            }
            if (j == colum - 1) {
                printf("%d\n", a[i][j]);
                if (n == 2) free(a[i]);
                if (n == 4 && i == colum * i) free(a[i]);
                break;
            }
            printf("%d ", a[i][j]);
        }
    }
}

int inputArryS(int *a, int row, int colum) {
    for (int i = 0; i < row; i++) {
        for (int j = i * row; j < (i * row) + colum; j++) {
            if (!scanf("%d", &a[j])) return 0;
            if ((int)a[j] != a[j]) return 0;
        }
        if (getchar() != 10) return 0;
    }
    return 1;
}

void outputS(int *a, int row, int colum) {
    for (int i = 0; i < row; i++) {
        for (int j = i * row; j < (i * row) + colum; j++) {
            if (i == row - 1 && j == (i * row) + (colum - 1)) {
                printf("%d", a[j]);
                return;
            }
            if (j == (i * row) + colum - 1) {
                printf("%d\n", a[j]);
                break;
            }
            printf("%d ", a[j]);
        }
    }
}