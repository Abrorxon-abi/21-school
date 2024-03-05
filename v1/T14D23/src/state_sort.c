#include "state_sort.h"

int main(void) {
    int n, trash;
    if ((scanf("%d.%d", &n, &trash)) != 1) {
        printf("n/a\n");
    } else {
        menu(n);
    }

    return (0);
}

void menu(int n) {
    int flag = 0;
    char *path = input(&flag);
    FILE *fp;
    int fl = 0;
    if ((fp = fopen(path, "r")) == NULL) {
        fl = 1;
    }
    if (!fl) {
        fclose(fp);
        switch (n) {
            case 0:
                scanFile(path);
                break;
            case 1:
                sortFile(path);
                scanFile(path);
                break;
            case 2:
                addLine(path);
                sortFile(path);
                scanFile(path);
                break;
        }
        free(path);
    } else {
        printf("n/a");
        if (!flag) {
            free(path);
        }
    }
    fclose(fp);
}

void addLine(char *path) {
    FILE *fp = fopen(path, "ab");
    Line value;
    int *ptr = &(value.year);
    for (int i = 0; i < 8; ptr++, i++) {
        scanf("%d", ptr);
    }
    fwrite(&value, sizeof(Line), 1, fp);
    fclose(fp);
}

char *input(int *flag) {
    char *path = malloc(sizeof(char) * 250);
    (path == NULL) ? *flag = 1 : scanf("%249s", path);
    return (path);
}

void scanFile(char *path) {
    FILE *fp = fopen(path, "rb");
    Line value;
    while (fread(&value, sizeof(Line), 1, fp)) {
        printf("%d %d %d %d %d %d %d %d\n", value.year, value.month, value.day, value.hour, value.min,
               value.sec, value.status, value.code);
    }
    fclose(fp);
}

int fifle(Line first, Line second) {
    int total = 0;
    int *ptr1 = &(first.year);
    int *ptr2 = &(second.year);
    for (int i = 0; !total && i < 6; i++) {
        if (*ptr1 > *ptr2) {
            total = 1;
        }
        if (*ptr1 < *ptr2) {
            total = -1;
        }
        ptr1++;
        ptr2++;
    }
    return (total);
}

void sortFile(char *path) {
    FILE *fp = fopen(path, "rb+");
    Line first, second;

    fseek(fp, SEEK_CUR, SEEK_END);
    int size = ftell(fp) / sizeof(Line);
    fseek(fp, SEEK_CUR, SEEK_SET);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            fseek(fp, sizeof(Line) * j, SEEK_SET);
            fread(&first, sizeof(Line), 1, fp);
            fread(&second, sizeof(Line), 1, fp);
            int total = fifle(first, second);
            if (total == 1) {
                swap(fp, first, second, j, j + 1);
            }
        }
    }
    fclose(fp);
}

void swap(FILE *fp, Line first, Line second, int index1, int index2) {
    fseek(fp, index1 * sizeof(Line), SEEK_SET);
    fwrite(&second, sizeof(Line), 1, fp);
    fseek(fp, index2 * sizeof(Line), SEEK_SET);
    fwrite(&first, sizeof(Line), 1, fp);
}
