#include <stdio.h>

int is_empty(FILE *file);

int main() {
    char path[1024];
    scanf("%s", path);
    FILE *file = fopen(path, "r");
    if (file == NULL || is_empty(file)) {
        printf("n/a");
    } else {
        int year = 0;
        int month = 0;
        int day = 0;
        if (scanf("%d.%d.%d", &day, &month, &year) != 3) {
            printf("n/a");
        } else {
            int a[8];
            while (!feof(file)) {
                fread(a, 8*sizeof(int), 1, file);
                if (a[0] == year && a[1] == month && a[2] == day) {
                    printf("%d", a[7]);
                    break;
                }
            }
        }
    }
    if (file != NULL) {
        fclose(file);
    }
    return 0;
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
