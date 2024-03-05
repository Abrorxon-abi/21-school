#include "clear_state.h"

int main() {
    char path[NMAX];
    char str_from[11], str_to[11];
    scanf("%255s", path);
    scanf("%10s %10s", str_from, str_to);
    s_date date_from, date_to;
    str_to_date(str_from, &date_from);
    str_to_date(str_from, &date_to);

    FILE *file = fopen(path, "r+b");
    if (file) {
        if (SEEK_SET != SEEK_END) {
            s_record r;
            record_init(&r);
            int count = get_records_count_in_file(file);
            int index = 0;
            for (; index < count; index++) {
                r = read_record_from_file(file, index);
                s_date cur = {r.day, r.month, r.year};
                if (date_to_int(cur) >= date_to_int(date_from) && date_to_int(cur) <= date_to_int(date_to)) {
                    //как удалить строку из файла????
                }
            }
            if (index == count) printf("n/a");
        } else
            printf("n/a");
        fclose(file);
    } else
        printf("n/a");

    return 0;
}

void str_to_date(char str, s_date *date) {
    date->day = atoi(strtok(str, "."));
    date->month = atoi(strtok(NULL, "."));
    date->year = atoi(strtok(NULL, "\0"));
}

int date_to_int(s_date date) {
    return date.year * 1e4 + date.month * 1e2 + date.day;
}
