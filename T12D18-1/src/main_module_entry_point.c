#include <stdio.h>

#include "documentation_module.h"
#include "print_module.h"

int main() {
#ifdef Quest_1
    print_log(print_char, Module_load_success_message);
#endif

#ifdef Quest_2
    int availability_mask[MAX_docs_count];
    check_available_documentation_module(validate, Documents_count, availability_mask, Documents);

    char *docs[Documents_count] = {Documents};

    for (int i = 0; i < Documents_count; i++) {
        if (availability_mask[i] == 0)
            printf("[%15s : unavailable]\n", docs[i]);
        else
            printf("[%15s : available  ]\n", docs[i]);
    }
#endif
    return 0;
}
