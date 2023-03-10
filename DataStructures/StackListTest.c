#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "StackList.h"

int main()
{
    struct stack_list_s stack = {};
    struct node_s *n0;

    n0 = (struct node_s *)malloc(sizeof(struct node_s));
    n0->element = 0;
    n0->next = NULL;
    stack.head = n0;

    printf("Testing Stack List DS\n");
    stack_list_print(&stack);

    printf("Test, push 9 element\n");
    for (int i = 1; i < 10; i++)
    {
        stack_list_push(&stack, i);
    }
    stack_list_print(&stack);

    printf("Test, pop 3 nodes\n");
    for (int i = 0; i < 3; i++)
        printf("pop %d\n", stack_list_pop(&stack));

    stack_list_print(&stack);

    printf("Test, peek \n");
    printf("peek %d, expected 6\n", stack_list_peek(&stack));

    return 0;
}
