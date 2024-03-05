#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int getDate(int *da1, int *mo1, int *ye1, int *da2, int *mo2, int *ye2);
int inDate(int da1, int mo1, int ye1, int da2, int mo2, int ye2, int da, int mo, int ye);
char *input(int *flag);

int main(void) {
    int flag = 0;
    char *path = input(&flag);
    if (flag) {
        printf("n/a");
    } else {
        Line value;
        FILE *fp;
        FILE *temp;
        int da1, mo1, ye1;
        int da2, mo2, ye2;
        fp = fopen(path, "rb");
        temp = fopen("temp", "wb");

        if (!getDate(&da1, &mo1, &ye1, &da2, &mo2, &ye2)) {
            while (fread(&value, sizeof(Line), 1, fp)) {
                if (!inDate(da1, mo1, ye1, da2, mo2, ye2, value.day, value.month, value.year)) {
                    fwrite(&value, sizeof(Line), 1, temp);
                    /* printf("%d %d %d\n", value.year, value.month, value.day); */
                };
            }
        } else {
            printf("n/a");
        }
        fclose(fp);
        fclose(temp);
        remove(path);
        rename("temp", path);
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

int getDate(int *da1, int *mo1, int *ye1, int *da2, int *mo2, int *ye2) {
    int flag = 0;
    if (scanf("%2d.%2d.%4d %2d.%2d.%4d", da1, mo1, ye1, da2, mo2, ye2) != 6) {
        flag = 1;
    }
    return (flag);
}

int inDate(int da1, int mo1, int ye1, int da2, int mo2, int ye2, int da, int mo, int ye) {
    int res = 0;

    struct tm info1;
    struct tm info2;
    struct tm info;

    info1.tm_year = ye1;
    info1.tm_mon = mo1 - 1;
    info1.tm_mday = da1;
    info1.tm_sec = 0;
    info1.tm_min = 0;
    info1.tm_hour = 0;

    info2.tm_year = ye2;
    info2.tm_mon = mo2 - 1;
    info2.tm_mday = da2;
    info2.tm_sec = 0;
    info2.tm_min = 0;
    info2.tm_hour = 0;

    info.tm_year = ye;
    info.tm_mon = mo - 1;
    info.tm_mday = da;
    info.tm_sec = 0;
    info.tm_min = 0;
    info.tm_hour = 0;

    long i = mktime(&info);
    long i1 = mktime(&info1);
    long i2 = mktime(&info2);
    /* printf("%ld %ld\n", i1, i2); */
    if (i >= i1 && i <= i2) {
        res = 1;
    }
    return (res);
}
