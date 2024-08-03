#include "../include/stack.h"
#include <stdio.h>

int main(void) {
    int a = 1, b = 2, c = 3;
    struct stack *s = stack_create(10);
    printf("[1] => stack size %d\n", stack_size(s));
    printf("[2] => stack push %d\n", stack_push(s, a));
    printf("[3] => stack push %d\n", stack_push(s, b));
    printf("[4] => stack push %d\n", stack_push(s, c));
    printf("[5] => stack size %d\n", stack_size(s));
    printf("[6] => stack pop %d\n", stack_pop(s));
    printf("[7] => stack size %d\n", stack_size(s));
    stack_delete(s);
    return 0;
}
