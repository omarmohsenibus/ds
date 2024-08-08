//
// Created by omarmohseni on 8/3/2024.
//

#include "../include/stack.h"

#define STACK_GROWTH_FACTOR 1.75


struct stack* stack_create(const size_t capacity, const size_t data_type_size) {
    struct stack *stack = malloc(sizeof(struct stack));

    if (stack == NULL)
        return NULL;

    void *tmp = malloc(capacity * data_type_size);

    if (tmp == NULL) {
        free(stack);
        return NULL;
    }

    stack->data = tmp;
    stack->top = 0;
    stack->data_type_size = data_type_size;
    stack->capacity = capacity;
    
    return stack;
}


int stack_is_full(const struct stack *stack) {
    return stack->top == stack->capacity;
}

int stack_is_empty(const struct stack *stack) {
    return stack->top == 0;
}

void *stack_push(struct stack *stack, void *data) {
    if (stack_is_full(stack))
        stack_realloc(stack);
    
    char* dst = (char*) stack->data + stack->top * stack->data_type_size;
    memcpy(dst, data, stack->data_type_size);
    stack->top += 1;
    return dst;
}

void stack_realloc(struct stack *stack) {
    const size_t new_capacity = stack->capacity * STACK_GROWTH_FACTOR;
    void* tmp = realloc(stack->data, new_capacity * stack->data_type_size);
    if (tmp == NULL);

    stack->capacity = new_capacity;
    stack->data = tmp;
}

extern void *stack_pop(struct stack *stack) {
    if(stack_is_empty(stack))
        return NULL;

    stack->top -= 1;

    return (char *)stack->data + stack->top * stack->data_type_size;
}

void stack_delete(struct stack *stack) {
    if (stack == NULL)
        return;
    if (stack->data == NULL)
        return;

    free(stack->data);
    stack->data = NULL;
    stack->capacity = 0;
    stack->data_type_size = 0;
    stack->top = 0;
    free(stack);
    stack = NULL;

}

int stack_size(struct stack *stack) {
    return stack->top;
}