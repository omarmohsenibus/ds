//
// Created by omarmohseni on 8/3/2024.
//

#ifndef DS_STACK_H
#define DS_STACK_H


#define DS_STACK_ERROR_INITIALIZATION 100
#define DS_STACK_ERROR_OVERFLOW 101
#define DS_STACK_ERROR_UNDERFLOW 102



struct stack {
    int capacity;
    int top;
    int *data;
};

extern struct stack *stack_create(int capacity);
extern int stack_is_full(struct stack *stack);
extern int stack_push(struct stack *stack, int data);
extern int stack_pop(struct stack *stack);
extern int stack_is_empty(struct stack *stack);
extern void stack_delete(struct stack *stack);
extern int stack_size(struct stack *stack);
extern char *dump_stack(struct stack *stack);

#endif //DS_STACK_H
