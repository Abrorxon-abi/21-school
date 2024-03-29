#include "module_io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int saveScan(int *input) {
    int res;
    char sym;
    if (scanf("%d%c", input, &sym) == 2 && sym == '\n') {
        res = 1;
    } else {
        res = 0;
        fseek(stdin, 0, SEEK_END);
    }
    return res;
}

char *charInput(int flag) {
    char *res = calloc(1, sizeof(char));
    res[0] = '\0';
    int i = 0;
    if (res != NULL) {
        while (1) {
            scanf("%c", &(res[i]));
            char *tmp = realloc(res, (i + 2) * sizeof(char));
            if (tmp != NULL) {
                res = tmp;
            } else {
                free(res);
                res = NULL;
                break;
            }
            if (res != NULL) {
                if (res[i] == '\n') {
                    if (!flag) res[i] = '\0';
                    break;
                }
                i++;
            } else {
                free(res);
                res = NULL;
                break;
            }
        }
    }
    return res;
}

char *charInputFromFile(FILE *f) {
    char *res = NULL;
    char buff;
    int counter = 0;
    while (fread(&buff, sizeof(char), 1, f)) {
        char *tmp = realloc(res, (counter + 1) * sizeof(char));
        if (tmp != NULL) {
            res = tmp;
            res[counter] = buff;
            counter++;
        } else {
            free(res);
            return NULL;
        }
    }
    return res;
}

int charInputInFile(FILE *f, char *write) {
    int res = 1;
    if (f == NULL && write == NULL) {
        res = 0;
    } else {
        for (size_t i = 0; i < strlen(write); i++) {
            fputc(write[i], f);
        }
    }
    return res;
}

void str_output(char *str) {
    for (int i = 0; i < (int)strlen(str); i++) printf("%c", str[i]);
}

char *s21_strcat(char *str1, char *str2) {
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    str1 = (char *)realloc(str1, size1 + size2);
    for (int i = size1, k = 0; i < size1 + size2; i++, k++) {
        str1[i] = str2[k];
    }
    return str1;
}