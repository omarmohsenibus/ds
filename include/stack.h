//
// Created by omarmohseni on 8/3/2024.
//

#ifndef DS_STACK_H
#define DS_STACK_H

#include <stdlib.h>
#include <string.h>

struct stack {
    size_t capacity;
    size_t top;
    size_t data_type_size;
    void *data;
};

extern struct stack *stack_create(const size_t capacity, const size_t data_type_size);
extern int stack_is_full(const struct stack *stack);
extern void stack_realloc(struct stack* stack);
extern void *stack_push(struct stack *stack, void *data);
extern void *stack_pop(struct stack *stack);
extern int stack_is_empty(const struct stack *stack);
extern void stack_delete(struct stack *stack);
extern int stack_size(struct stack *stack);

#endif //DS_STACK_H
