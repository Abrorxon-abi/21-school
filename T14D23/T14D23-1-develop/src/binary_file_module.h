#ifndef BINARY_FILE_MODULE_H
#define BINARY_FILE_MODULE_H
#include <stdio.h>

#include "record_struct.h"

s_record read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const s_record *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);

#endif
