#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void print_node(t_btree* node);
void print_child(t_btree* child, char* child_name);

int main() {
    int item1 = 10;
    t_btree* node1 = bstree_create_node(item1);
    printf("create test 1: (node1)\n");
    print_node(node1);
    printf("\n----------------\n");

    int item2 = 100;
    t_btree* node2 = bstree_create_node(item2);
    printf("create test 2: (node2)\n");
    print_node(node2);
    printf("\n----------------\n");

    free(node1);
    free(node2);
    return 0;
}

void print_node(t_btree* node) {
    printf("item = %d | ", node->item);

    print_child(node->left, "left");
    print_child(node->right, "right");
}

void print_child(t_btree* child, char* child_name) {
    if (child == NULL)
        printf("%s = NULL | ", child_name);
    else
        printf("%s = %d | ", child_name, child->item);
}
