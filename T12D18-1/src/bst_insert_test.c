#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void print_node(t_btree* node);
void print_child(t_btree* child, char* child_name);

int main() {
    t_btree* node1 = bstree_create_node(10);

    node1 = bstree_insert(node1, 100, cmpf);
    printf("insert test 1:\n");
    print_node(node1);
    printf("\n----------------\n");

    node1 = bstree_insert(node1, 5, cmpf);
    printf("insert test 2:\n");
    print_node(node1);
    printf("\n----------------\n");
    bstree_apply_postfix_free(node1);

    free(node1);
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
