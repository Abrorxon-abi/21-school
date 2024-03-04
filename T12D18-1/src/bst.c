#include "bst.h"

#include <stdio.h>

t_btree *bstree_create_node(int item) {
    t_btree *btree = (t_btree *)malloc(sizeof(t_btree));
    btree->item = item;
    btree->left = NULL;
    btree->right = NULL;
    return btree;
}

t_btree *bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    if (root == NULL) {
        root = bstree_create_node(item);
    } else {
        int cmp = cmpf(item, root->item);
        if (cmp == 1) root->right = bstree_insert(root->right, item, cmpf);
        if (cmp == -1) root->left = bstree_insert(root->left, item, cmpf);
    }
    return root;
}

int cmpf(int node1, int node2) {
    int res;

    if (node1 == node2)
        res = 0;
    else if (node1 > node2)
        res = 1;
    else
        res = -1;

    return res;
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root) {
        applyf(root->item);
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root) {
        bstree_apply_infix(root->left, applyf);
        applyf(root->item);
        bstree_apply_infix(root->right, applyf);
    }
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root) {
        bstree_apply_postfix(root->left, applyf);
        bstree_apply_postfix(root->right, applyf);
        applyf(root->item);
    }
}

void bstree_apply_postfix_free(t_btree *root) {
    if (root) {
        bstree_apply_postfix_free(root->left);
        bstree_apply_postfix_free(root->right);
        free(root);
    }
}