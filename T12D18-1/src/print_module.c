#include "print_module.h"

#include <stdio.h>
#include <time.h>

void print_log(char (*print)(char), char *message) {
    const char *ptr = Log_prefix;
    while (*ptr != ']') print(*ptr++);
    print(*ptr);
    print(' ');

    time_t timer = time(NULL);
    struct tm *u = localtime(&timer);
    char formatted_time[TIME_FORMAT_SIZE];
    snprintf(formatted_time, sizeof(formatted_time), "%02d:%02d:%02d", u->tm_hour, u->tm_min, u->tm_sec);

    ptr = formatted_time;
    while (*ptr) print(*ptr++);
    print(' ');

    ptr = message;
    while (*ptr) print(*ptr++);
}

char print_char(char ch) { return putchar(ch); }