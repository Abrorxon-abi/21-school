#include "binary_file_module.h"

s_record read_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(s_record);
    fseek(pfile, offset, SEEK_SET);
    s_record record;
    fread(&record, sizeof(s_record), 1, pfile);
    rewind(pfile);
    return record;
}

void write_record_in_file(FILE *pfile, const s_record *record_to_write, int index) {
    int offset = index * sizeof(s_record);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(s_record), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    s_record record1 = read_record_from_file(pfile, record_index1);
    s_record record2 = read_record_from_file(pfile, record_index2);

    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return size;
}

int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(s_record); }

void remove_record_from_file(FILE *pfile, int index) {
    int offset = index * sizeof(s_record);
    fseek(pfile, offset, SEEK_SET);
    //
    fflush(pfile);
    rewind(pfile);
}