//
// Created by omarmohseni on 8/3/2024.
//

#include "../include/stack.h"
#include <stdlib.h>


struct stack *stack_create(int capacity) {
    struct stack *stack = malloc(sizeof(struct stack));

    stack->top = -1;
    stack->capacity = capacity;
    stack->data = malloc(capacity * sizeof(int));

    return stack;
}


int stack_is_full(struct stack *stack) {
    return stack->top == stack->capacity - 1;
}

int stack_is_empty(struct stack *stack) {

    return stack->top == -1;
}

int stack_push(struct stack *stack, int data) {
    if (stack_is_full(stack))
        return -1;
    stack->top += 1;
    stack->data[stack->top] = data;
    return stack->data[stack->top];
}

extern int stack_pop(struct stack *stack) {
    if(stack_is_empty(stack))
        return -1;

    stack->top -= 1;

    return stack->data[stack->top];
}

void stack_delete(struct stack *stack) {
    if (stack == NULL)
        return;
    if (stack->data == NULL)
        return;

    free(stack->data);
    free(stack);
}

int stack_size(struct stack *stack) {
    return stack->top + 1;
}