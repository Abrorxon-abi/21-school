#ifndef STACK_H
#define STACK_H

struct stack {
    int data;
    struct stack *next;
};

struct stack *init(int val);
struct stack *push(struct stack *h, int val);
struct stack *pop(struct stack *h);
void decstroy(struct stack *h);
void stack_output(struct stack *h);
int stack_len(struct stack *h);
#endif
