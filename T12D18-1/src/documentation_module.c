#include "documentation_module.h"

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list docs;  //указатель va_list
    va_start(docs, document_count);

    int* tmp_avail;
    tmp_avail = va_arg(docs, int*);

    for (int i = 0; i < document_count; i++) {
        tmp_avail[i] = validate(va_arg(docs, char*));
    }

    va_end(docs);
    return tmp_avail;
}

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}
