#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "StackArray.h"

int main()
{
    struct stack_array_s stack = {};

    printf("Testing Stack Array DS\n");
    printf("Test, push 10 element\n");
    for (int i = 0; i < 10; i++)
    {
        stack_array_push(&stack, i);
    }
    stack_array_print(&stack);

    printf("Test, pop 3 nodes\n");
    for (int i = 0; i < 3; i++)
        printf("pop %d\n", stack_array_pop(&stack));

    stack_array_print(&stack);

    printf("Test, peek \n");
    printf("peek %d, expected 6\n", stack_array_peek(&stack));

    return 0;
}
