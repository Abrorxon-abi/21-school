#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

struct node* init(struct door* dp) {
    struct node* new_node = NULL;
    if (dp != NULL) {
        new_node = malloc(sizeof(struct node));
        new_node->d = dp;
        new_node->next = NULL;
    }
    return new_node;
}
struct node* add_door(struct node* el, struct door* dp) {
    struct node* new_node = NULL;
    if (el != NULL && dp != NULL) {
        new_node = init(dp);
        new_node->next = el->next;
        el->next = new_node;
    }
    return new_node;
}
struct node* find_door(int door_id, struct node* root) {
    struct node* search = root;
    if (root != NULL) {
        while (search != NULL && search->d->id != door_id) {
            search = search->next;
        }
    }
    return search;
}
struct node* remove_door(const struct node* elem, struct node* root) {
    if (root != NULL && elem != NULL) {
        struct node* prev = root;
        struct node* n = root;
        while (n != elem && n != NULL) {
            prev = n;
            n = n->next;
        }
        if (n != NULL) {
            if (n != root) {
                prev->next = n->next;
                free(n);
            } else {
                if (root->next != NULL)
                    root = root->next;
                else
                    root = NULL;
                free(n);
            }
        }
    }
    return root;
}
void destroy(struct node* root) {
    if (root != NULL) {
        struct node* destroyer = root;

        while (destroyer != NULL) {
            root = root->next;
            free(destroyer);
            destroyer = root;
        }
    }
}

void door_init(struct door* d, int door_id, int stat) {
    d->id = door_id;
    d->status = stat;
}

void list_output(struct node* root) {
    struct node* runner = root;
    if (root == NULL) printf("List is empty");
    while (runner != NULL) {
        printf("Door_ID:%d\tDoor_STATUS:%d", runner->d->id, runner->d->status);
        runner = runner->next;
        if (runner != NULL) printf("\n");
    }
}

int list_len(struct node* root) {
    int count = 0;
    struct node* runner = root;
    while (runner != NULL) {
        count++;
        runner = runner->next;
    }
    return count;
}
