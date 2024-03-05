#ifndef STATE_SORT_H
#define STATE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#define NMAX 256

typedef struct record {
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int seconds;
    int status;
    int ID;
} record;

void menu();
void read_file(char *file_name);
void sort_file(char *file_name);
record get_by_id(FILE *stream, long int id);
void set_by_id(FILE *stream, long int id, record data);
#endif
