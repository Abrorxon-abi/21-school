#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void print_node_value(int value);
void free_tree_without_leaks(t_btree *root);

int main() {
    t_btree *node1 = bstree_create_node(10);

    node1 = bstree_insert(node1, 6, cmpf);
    node1 = bstree_insert(node1, 5, cmpf);
    node1 = bstree_insert(node1, 7, cmpf);
    node1 = bstree_insert(node1, 9, cmpf);

    printf("infix_apply: \t");
    bstree_apply_infix(node1, print_node_value);
    printf("\n");
    printf("prefix_apply: \t");
    bstree_apply_prefix(node1, print_node_value);
    printf("\n");
    printf("postfix_apply: \t");
    bstree_apply_postfix(node1, print_node_value);

    free_tree_without_leaks(node1);
    return 0;
}

void print_node_value(int value) { printf("%d\t", value); }

void free_tree_without_leaks(t_btree *root) {
    if (root) {
        free_tree_without_leaks(root->left);
        free_tree_without_leaks(root->right);
        free(root);
    }
}
