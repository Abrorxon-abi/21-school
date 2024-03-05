#ifndef RECORD_STRUCT_H
#define RECORD_STRUCT_H

typedef struct record {
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int seconds;
    int status;
    int ID;
} s_record;

void record_init(s_record *data);
long long int calc_date(s_record r);

#endif
