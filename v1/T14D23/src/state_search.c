#include <stdio.h>
#include <stdlib.h>
typedef struct line {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int status;
    int code;
} Line;

int getDate(int *da, int *mo, int *ye);
char *input(int *flag);

int main(void) {
    int flag = 0;
    char *path = input(&flag);
    if (flag) {
        printf("n/a");
    } else {
        Line value;
        FILE *fp;
        int da, mo, ye;
        (fp = fopen(path, "rb"));

        if (!getDate(&da, &mo, &ye)) {
            int flagS = 1;
            while (fread(&value, sizeof(Line), 1, fp)) {
                if (value.year == ye && value.month == mo && value.day == da) {
                    printf("%d\n", value.code);
                    flagS = 0;
                }
            }
            if (flagS) {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
        fclose(fp);
    }
    free(path);
    return (0);
}

char *input(int *flag) {
    char *path = malloc(sizeof(char) * 250);
    FILE *fp;
    Line value;
    (path == NULL) ? *flag = 1 : scanf("%249s", path);
    if ((fp = fopen(path, "rb")) == NULL) {
        *flag = 1;
    } else {
        fread(&value, sizeof(Line), 1, fp);
        if (value.year == EOF) {
            *flag = 1;
        }
        fclose(fp);
    }
    return (path);
}

int getDate(int *da, int *mo, int *ye) {
    int flag = 0;
    if (scanf("%2d.%2d.%4d", da, mo, ye) != 3) {
        flag = 1;
    }
    return (flag);
}
