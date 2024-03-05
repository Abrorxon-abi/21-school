#include "date.h"
#include <stdio.h>

void fill(date *s, int *a) {
    s -> year = a[0];
    s -> month = a[1];
    s -> day = a[2];
    s -> hour = a[3];
    s -> minute = a[4];
    s -> second = a[5];
    s -> status = a[6];
    s -> code = a[7];
}

int date_min(const date *s1, const date *s2) {
    int result = 1;
    if (s1 -> year < s2 -> year) {
        result = 1;
    } else if (s1 -> year > s2 -> year) {
        result = 0;
    } else if (s1 -> month < s2 -> month) {
        result = 1;
    } else if (s1 -> month > s2 -> month) {
        result = 0;
    } else if (s1 -> day < s2 -> day) {
        result = 1;
    } else if (s1 -> day > s2 -> day) {
        result = 0;
    } else if (s1 -> hour < s2 -> hour) {
        result = 1;
    } else if (s1 -> hour > s2 -> hour) {
        result = 0;
    } else if (s1 -> minute < s2 -> minute) {
        result = 1;
    } else if (s1 -> minute > s2 -> minute) {
        result = 0;
    } else if (s1 -> second < s2 -> second) {
        result = 1;
    } else if (s1 -> second > s2 -> second) {
        result = 0;
    } else if (s1 -> status < s2 -> status) {
        result = 1;
    } else if (s1 -> status > s2 -> status) {
        result = 0;
    } else if (s1 -> code < s2 -> code) {
        result = 1;
    } else if (s1 -> code > s2 -> code) {
        result = 0;
    }
    return result;
}

void print(const date *s) {
    printf("%d %d %d %d %d %d %d %d\n", s -> year, s -> month,
            s -> day, s -> hour, s -> minute,
            s -> second, s -> status, s -> code);
}

void clone(date *s1, const date *s2) {
    s1 -> year = s2 -> year;
    s1 -> month = s2 -> month;
    s1 -> day = s2 -> day;
    s1 -> hour = s2 -> hour;
    s1 -> minute = s2 -> minute;
    s1 -> second = s2 -> second;
    s1 -> status = s2 -> status;
    s1 -> code = s2 -> code;
}

void print_all(const date *s, int n) {
    for (int i = 0; i < n; i++) {
        print(&s[i]);
    }
}

int cmp(const date *s1, const date *s2) {
    return s1 -> year == s2 -> year && s1 -> month == s2 -> month && s1 -> day == s2 -> day;
}
