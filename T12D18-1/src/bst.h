#ifndef BST_H
#define BST_H
#include <stdlib.h>

typedef struct s_btree {
    struct s_btree *left;
    struct s_btree *right;
    int item;
} t_btree;

t_btree *bstree_create_node(int item);
t_btree *bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));
int cmpf(int node1, int node2);

void bstree_apply_infix(t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(t_btree *root, void (*applyf)(int));
void bstree_apply_postfix_free(t_btree *root);

#endif
