#include "record_struct.h"

void record_init(s_record *data) {
    data->year = 0;
    data->month = 0;
    data->day = 0;
    data->hours = 0;
    data->minutes = 0;
    data->seconds = 0;
    data->status = 0;
    data->ID = 0;
}

long long int calc_date(s_record r) {
    long long int date = 0;
    date = r.year * 1e10 + r.month * 1e8 + r.day * 1e6 + r.hours * 1e4 + r.minutes * 1e2 + r.seconds;
    return date;
}