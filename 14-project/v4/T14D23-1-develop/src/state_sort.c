#include "state_sort.h"

int main() {
    menu();
    return 0;
}

void menu() {
    int mode = 0;
    char file_name[NMAX];
    while (scanf("%d", &mode) == 1 && mode != -1) {
        switch (mode) {
            case 0:
                scanf("%255s", file_name);
                read_file(file_name);
                break;
            case 1:
                scanf("%255s", file_name);
                sort_file(file_name);
                read_file(file_name);
                break;
            case 2:
                break;
            default:
                break;
        }
    }

    printf("eror3\n");
}

void read_file(char *file_name) {
    printf("file = %s\n", file_name);
    FILE *file = fopen(file_name, "rb");
    if (file) {
        record r;
        int res = 1;
        while (res) {
            res &= fread(&r.year, sizeof(int), 1, file);
            res &= fread(&r.month, sizeof(int), 1, file);
            res &= fread(&r.day, sizeof(int), 1, file);
            res &= fread(&r.hours, sizeof(int), 1, file);
            res &= fread(&r.minutes, sizeof(int), 1, file);
            res &= fread(&r.seconds, sizeof(int), 1, file);
            res &= fread(&r.status, sizeof(int), 1, file);
            res &= fread(&r.ID, sizeof(int), 1, file);

            if (res) {
                printf("%d %d %d %d %d %d %d %d\n", r.year, r.month, r.day, r.hours, r.minutes, r.seconds,
                       r.status, r.ID);
            }
        }
        fclose(file);
    } else
        printf("n/a\n");
}

record get_by_id(FILE *stream, long int id) {
    record data;
    fseek(stream, id * 8 * sizeof(int), SEEK_SET);
    fread(&data.year, sizeof(int), 1, stream);
    fread(&data.month, sizeof(int), 1, stream);
    fread(&data.day, sizeof(int), 1, stream);
    fread(&data.hours, sizeof(int), 1, stream);
    fread(&data.minutes, sizeof(int), 1, stream);
    fread(&data.seconds, sizeof(int), 1, stream);
    fread(&data.status, sizeof(int), 1, stream);
    fread(&data.ID, sizeof(int), 1, stream);
    return data;
}

void set_by_id(FILE *stream, long int id, record data) {
    fseek(stream, id * sizeof(record), SEEK_SET);

    printf("set id = %ld | %d %d %d %d %d %d %d %d\n", id, data.year, data.month, data.day, data.hours,
           data.minutes, data.seconds, data.status, data.ID);

    int res = fwrite(&data.year, sizeof(int), 1, stream);
    res &= fwrite(&data.month, sizeof(int), 1, stream);
    res &= fwrite(&data.day, sizeof(int), 1, stream);
    res &= fwrite(&data.hours, sizeof(int), 1, stream);
    res &= fwrite(&data.minutes, sizeof(int), 1, stream);
    res &= fwrite(&data.seconds, sizeof(int), 1, stream);
    res &= fwrite(&data.status, sizeof(int), 1, stream);
    res &= fwrite(&data.ID, sizeof(int), 1, stream);
    if (!res) printf("NOT WRITE\n");
}
int row_counter(FILE *stream) {
    fseek(stream, sizeof(record), SEEK_END);
    return ftell(stream) / sizeof(record);
}

void sort_file(char *file_name) {
    printf("file = %s\n", file_name);
    FILE *file = fopen(file_name, "r+b");
    if (file) {
        record r_i, r_j, r_min;
        // int k = 0;
        int n = row_counter(file);
        for (int i = 0; i < n; i++) {
            r_i = get_by_id(file, i);
            int k = i;
            r_min = r_i;
            //            printf("i = %d |before| %d %d %d %d %d %d %d %d\n", i, r_i.year, r_i.month, r_i.day,
            //            r_i.hours,
            //                   r_i.minutes, r_i.seconds, r_i.status, r_i.ID);
            for (int j = i + 1; j < n; j++) {
                r_j = get_by_id(file, j);
                // printf("m1 = %d <> m2 = %d | ", r_min.month, r_j.month);
                if (r_min.year > r_j.year)
                    if (r_min.month > r_j.month)
                    //                        if (r_min.day > r_j.day)
                    //                            if (r_min.hours > r_j.hours)
                    //                                if (r_min.minutes > r_j.minutes)
                    //                                    if (r_min.seconds > r_j.seconds)
                    {
                        r_min = r_j;
                        k = j;
                        // r_j = r_i;
                    }
            }

            set_by_id(file, i, r_min);
            set_by_id(file, k, r_i);
        }
        fclose(file);
    } else
        printf("n/a\n");
}
