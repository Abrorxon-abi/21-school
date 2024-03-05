#include "date.h"
#include <stdio.h>

int is_empty(FILE *file);

int main() {
    char path[1024];
    scanf("%s", path);
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a");
    } else {
        date d1;
        date d2;
        if (scanf("%d.%d.%d", &(d1.day), &(d1.month), &(d1.year)) != 3) {
            printf("n/a");
        } else {
            if (scanf("%d.%d.%d", &(d2.day), &(d2.month), &(d2.year)) != 3) {
                printf("n/a");
            }
            date temp;
            int a[8];
            date d[10000];
            int n = 0;
            d1.hour = 0;
            d1.minute = 0;
            d1.second = 0;
            d1.status = 0;
            d1.code = 0;
            d2.hour = 0;
            d2.minute = 0;
            d2.second = 0;
            d2.status = 0;
            d2.code = 0;
            while (!feof(file)) {
                fread(a, 8*sizeof(int), 1, file);
                fill(&temp, a);
                if ((date_min(&d1, &temp) && date_min(&temp, &d2)) || cmp(&temp, &d2)) {
                    continue;
                }
                fill(&d[n++], a);
            }
            file = fopen(path, "wb");
            for (int i = 0; i < n; i++) {
                fwrite(&d[i], sizeof(date), 1, file);
            }
        }
    }
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
