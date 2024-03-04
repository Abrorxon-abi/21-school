#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
struct stack *init(int val) {
    struct stack *t = malloc(sizeof(struct stack));
    t->data = val;
    t->next = NULL;
    return t;
}

struct stack *push(struct stack *h, int val) {
    struct stack *new_el = init(val);
    new_el->next = h;
    h = new_el;

    return h;
}
struct stack *pop(struct stack *h) {
    if (h != NULL) {
        struct stack *del = h;
        h = h->next;
        free(del);
    } else {
        printf("Stack is empty");
    }
    return h;
}
void decstroy(struct stack *h) {
    struct stack *destroyer = h;

    while (destroyer != NULL) {
        h = h->next;
        free(destroyer);
        destroyer = h;
    }
}

void stack_output(struct stack *h) {
    if (h == NULL) {
        printf("Stack is empty");
    } else {
        struct stack *runner = h;
        while (runner != NULL) {
            printf("%d ", runner->data);
            runner = runner->next;
        }
    }
}

int stack_len(struct stack *h) {
    struct stack *runner = h;
    int count = 0;
    while (runner != NULL) {
        count++;
        runner = runner->next;
    }
    return count;
}
