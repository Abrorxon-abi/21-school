#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void test1(int val1, int val2, int val3) {
    printf("TEST1 - pushing in emty stack\n");
    struct stack *head = NULL;
    stack_output(head);
    printf("\t%d %d %d\n", val1, val2, val3);
    head = push(head, val1);
    head = push(head, val2);
    head = push(head, val3);
    stack_output(head);
    int size = stack_len(head);
    if (size == 3 && head->data == val3)
        printf("\nSUCCESS");
    else
        printf("\nFAIL");

    printf("\nTEST1 - poping stack\n");
    printf("pop test1\n");
    stack_output(head);
    printf("\tpop(head)\n");
    head = pop(head);
    stack_output(head);
    if (head->data == val2)
        printf("\nSUCCESS");
    else
        printf("\nFAIL");

    printf("\npop test2\n");
    stack_output(head);
    printf("\tpop(head)\n");
    head = pop(head);
    stack_output(head);
    if (head->data == val1)
        printf("\nSUCCESS");
    else
        printf("\nFAIL");

    decstroy(head);
}

void test2() {
    printf("\nTEST2 - poping empty stack");
    struct stack *head = NULL;
    printf("NOW\n");
    stack_output(head);
    printf("TRYING TO POP\n");
    head = pop(head);
    if (head == NULL)
        printf("\nSUCCESS");
    else
        printf("\nFAIL");

    printf("\nTEST2 - pushing");
    printf("\n");
    stack_output(head);
    printf("\t 1 2 3 2 4");
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 4);
    printf("\n");
    stack_output(head);
    int size = stack_len(head);
    if (size == 5)
        printf("\nSUCCESS");
    else
        printf("\nFAIL");

    decstroy(head);
}
int main() {
    test1(1, 2, 3);
    printf("\n");
    test2();
    return 0;
}
