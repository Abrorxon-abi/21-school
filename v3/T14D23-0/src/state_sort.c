#include "date.h"
#include <stdio.h>
#include <stdlib.h>

int is_empty(FILE *file);
void sort(date *d, int n);
void swap(date *d1, date *d2);

int main() {
    char path[1024];
    scanf("%s", path);
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a");
    } else {
        int n = 0;
        if (scanf("%d", &n) != 1) {
            printf("n/a");
        } else {
            if (n < 0 || n > 2) {
                printf("n/a");
            } else {
                int a[8];
                date d[100000];
                int n1 = 0;
                while (!feof(file)) {
                    fread(a, 8*sizeof(int), 1, file);
                    fill(&d[n1++], a);
                }
                if (n == 0) {
                    if (!is_empty(file)) {
                        print_all(d, n1);
                    } else {
                        printf("n/a");
                    }
                } else if (n == 1) {
                    if (!is_empty(file)) {
                        sort(d, n1);
                        print_all(d, n1);
                        FILE *file = fopen(path, "wb");
                        for (int i = 0; i < n1; i++) {
                            fwrite(&d[i], sizeof(date), 1, file);
                        }
                    } else {
                        printf("n/a");
                    }
                } else if (n == 2) {
                    scanf("%d%d%d%d%d%d%d%d", &(d[n1].year), &(d[n1].month), &(d[n1].day),
                    &(d[n1].hour), &(d[n1].minute),
                    &(d[n1].second), &(d[n1].status), &(d[n1].code));
                    n1++;
                    sort(d, n1);
                    print_all(d, n1);
                    FILE *file = fopen(path, "wb");
                    for (int i = 0; i < n1; i++) {
                        fwrite(&d[i], sizeof(date), 1, file);
                    }
                }
            }
        }
    }
    if (file == NULL) {
        fclose(file);
    }
    return 0;
}

void sort(date *d, int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i; j < n; j++) {
            if (date_min(&d[j], &d[min])) min = j;
        }
        swap(&d[i], &d[min]);
    }
}

void swap(date *d1, date *d2) {
    date temp;
    clone(&temp, d1);
    clone(d1, d2);
    clone(d2, &temp);
}

int is_empty(FILE *file) {
    char c = 0;
    int f = 0;
    c = fgetc(file);
    if (c == '\0') {
        f = 1;
    } else {
        ungetc(c, file);
    }
    return f;
}
