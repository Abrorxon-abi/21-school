#include "state_search.h"

int main() {
    char path[NMAX];
    char date[11];
    scanf("%255s", path);
    scanf("%10s", date);
    int dd = atoi(strtok(date, "."));
    int mm = atoi(strtok(NULL, "."));
    int yyyy = atoi(strtok(NULL, "\0"));

    FILE *file = fopen(path, "rb");
    if (file) {
        if (SEEK_SET != SEEK_END) {
            s_record r;
            record_init(&r);
            int count = get_records_count_in_file(file);
            int index = 0;
            for (; index < count; index++) {
                r = read_record_from_file(file, index);
                if (r.day == dd && r.month == mm && r.year == yyyy) {
                    printf("%d", r.ID);
                    break;
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
