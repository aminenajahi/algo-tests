#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "StackArray.h"

void stack_array_print(struct stack_array_s *s)
{
    printf("nb elements:%d\n", s->nb_elements);
    for (int i = 0; i < s->nb_elements; i++)
        printf("stack[%d] = %d\n", i, s->elements[i]);
}

int stack_array_size(struct stack_array_s *s)
{
    return s->nb_elements;
}

bool stack_array_is_empty(struct stack_array_s *s)
{
    return s->elements == 0 ? true : false;
}

void stack_array_push(struct stack_array_s *s, int e)
{
    if (s->nb_elements > MAX_SIZE)
        assert("no space left in stack");

    s->elements[s->nb_elements++] = e;
}

int stack_array_pop(struct stack_array_s *s)
{
    int element;

    if (s->nb_elements <= 0)
        assert("no elements in stack");

    element = s->elements[s->nb_elements - 1];
    s->nb_elements--;

    return element;
}

int stack_array_peek(struct stack_array_s *s)
{
     if (s->nb_elements <= 0)
        assert("no elements in stack");

    return s->elements[s->nb_elements - 1];
}
