#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>
int s21_strlen(char *mas) {
    int i = 0;
    while (*mas++) i++;
    return i;
}

int s21_strcmp(char *str1, char *str2) {
    int res = 0;
    int size1 = s21_strlen(str1);
    int size2 = s21_strlen(str2);
    if (size1 == size2) {
        for (int i = 0; i < size1; i++) {
            if (str1[i] != str2[i]) {
                if (str1[i] > str2[i])
                    res = 1;
                else
                    res = -1;
                break;
            }
            res = 0;
        }
    }
    if (size1 > size2) res = 1;
    if (size1 < size2) res = -1;
    return res;
}

char *s21_strcpy(char *str1, char *str2) {
    for (int i = 0; str2[i] != '\0'; i++) {
        str1[i] = str2[i];
    }
    return str1;
}

char *s21_strcat(char *str1, char *str2) {
    int size1 = s21_strlen(str1);
    int size2 = s21_strlen(str2);

    str1 = (char *)realloc(str1, size1 + size2);
    for (int i = size1, k = 0; i < size1 + size2; i++, k++) {
        str1[i] = str2[k];
    }
    return str1;
}

char *s21_strchr(char *str1, int symbol) {
    char *p = NULL;
    for (int i = 0; i < s21_strlen(str1) + 1 || str1[i] != '\0'; i++) {
        if (str1[i] == symbol) {
            p = (str1 + i);
            break;
        }
    }
    return p;
}

int s21_compare(char *str1, char *str2) {
    int res = 1;
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            res = 0;
        }
        str1++;
        str2++;
    }
    return res;
}

char *s21_strstr(char *str1, char *str2) {
    char *res = NULL;
    if (*str2 == '\0') {
        res = str1 + s21_strlen(str1);
        str1 += s21_strlen(str1);
    }
    while (*str1 != '\0') {
        if (*str1 == *str2) {
            if (s21_compare(str1, str2)) {
                res = str1;
                break;
            }
        }
        str1++;
    }
    return res;
}
