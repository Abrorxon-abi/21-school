#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIST_SIZE 15
#include "door_struct.h"

void test1(struct door el1, struct door el2, struct door el3, struct door el4, struct door el5) {
    struct node *n1 = init(&el1);

    add_door(n1, &el2);
    struct node *n2 = find_door(el2.id, n1);
    add_door(n2, &el3);

    struct node *n3 = find_door(el3.id, n1);
    add_door(n3, &el4);

    struct node *n4 = find_door(el4.id, n1);
    add_door(n4, &el5);

    printf("TEST1 - removing element from list\n");
    int len5 = list_len(n1);
    printf("List size:%d\n", len5);
    list_output(n1);

    remove_door(n2, n1);
    int len4 = list_len(n1);
    printf("\nList size:%d\tREMOVED EL2\n", len4);
    list_output(n1);

    if (len5 == len4 + 1)
        printf("\nSUCCESS: %d == %d + 1", len5, len4);
    else
        printf("\n\nFAIL: %d != %d + 1", len5, len4);

    printf("\n\nTEST1 - adding element after el3\n");

    len4 = list_len(n1);
    printf("List size:%d\n", len4);
    list_output(n1);

    add_door(n3, &el2);
    len5 = list_len(n1);
    printf("\nList size:%d\t ADDED EL2\n", len5);
    list_output(n1);

    if (len5 - 1 == len4)
        printf("\nSUCCESS: %d - 1 == %d", len5, len4);
    else
        printf("\nFAIL: %d - 1!= %d", len5, len4);
    destroy(n1);
}

void test2(struct door el1, struct door el2, struct door el3, struct door el4, struct door el5) {
    struct node *n1 = init(&el1);

    add_door(n1, &el2);
    struct node *n2 = find_door(el2.id, n1);
    add_door(n2, &el3);

    struct node *n3 = find_door(el3.id, n1);
    add_door(n3, &el4);

    struct node *n4 = find_door(el4.id, n1);
    add_door(n4, &el5);

    struct node *n5 = find_door(el5.id, n1);
    printf("\n\nTEST2 - removing element - root from list\n");
    int len5 = list_len(n1);
    printf("List size:%d\n", len5);
    list_output(n1);

    n1 = remove_door(n1, n1);
    int len4 = list_len(n1);
    printf("\nList size:%d\tREMOVED EL1 - list root\n", len4);
    list_output(n1);

    if (len5 == len4 + 1)
        printf("\nSUCCESS: %d == %d + 1", len5, len4);
    else
        printf("\nFAIL: %d != %d + 1", len5, len4);

    printf("\n\nTEST2 - adding element after 4el\n");
    len4 = list_len(n1);
    printf("List size:%d\n", len4);
    list_output(n1);

    add_door(n5, &el1);
    len5 = list_len(n1);
    printf("\nList size:%d\t ADDED EL1\n", len5);
    list_output(n1);

    if (len5 - 1 == len4)
        printf("\nSUCCESS: %d - 1 == %d", len5, len4);
    else
        printf("\nFAIL: %d - 1!= %d", len5, len4);
    destroy(n1);
}

void test3(struct door el1, struct door el2) {
    printf("\n\nTEST3 - adding elements in empty list\n");
    struct node *n1 = NULL;
    list_output(n1);
    printf("\n");
    n1 = init(&el1);

    add_door(n1, &el2);
    struct node *n2 = find_door(el2.id, n1);
    list_output(n1);
    if (list_len(n1) == 2)
        printf("\nSUCCESS");
    else
        printf("FAIL");

    printf("\n\nTEST3 - removing all elements from list\n");
    list_output(n1);
    printf("\n");
    remove_door(n2, n1);
    n1 = remove_door(n1, n1);
    list_output(n1);
    if (n1 == NULL)
        printf("\nSUCCESS");
    else
        printf("\nFAIL");
    destroy(n1);
}

int main() {
    struct door el1;
    struct door el2;
    struct door el3;
    struct door el4;
    struct door el5;
    door_init(&el1, 3, 1);
    door_init(&el2, 2, 0);
    door_init(&el3, 1, 1);
    door_init(&el4, 4, 0);
    door_init(&el5, 5, 1);
    test1(el1, el2, el3, el4, el5);
    test2(el1, el2, el3, el4, el5);
    test3(el1, el2);

    return 0;
}
