#ifndef CLEAR_STATE_H
#define CLEAR_STATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_file_module.h"
#include "record_struct.h"

#define NMAX 256
// #define  DAYS 365
// #define  HOURS 24
// #define  MINUTES 60
// #define  SECONDS 60

typedef struct date{
    int day;
    int month;
    int year;
} s_date;

void str_to_date(char str, s_date *date);

#endif
