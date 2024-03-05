#ifndef SRC_DATE_H_
#define SRC_DATE_H_

typedef struct date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} date;

void fill(date *s, int *a);

int date_min(const date *s1, const date *s2);
void clone(date *s1, const date *s2);
void print(const date *s);
void print_all(const date *s, int n);
int cmp(const date *s1, const date *s2);

#endif  // SRC_DATE_H_
