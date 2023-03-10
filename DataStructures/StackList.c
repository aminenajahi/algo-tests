#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "StackList.h"

void stack_list_print(struct stack_list_s *s)
{
    printf("nb elements:%d\n", s->nb_elements);
    single_linked_list_print(s->head);
}

int stack_list_size(struct stack_list_s *s)
{
    return s->nb_elements;
}

bool stack_list_is_empty(struct stack_list_s *s)
{
    return s->nb_elements == 0 ? true : false;
}

void stack_list_push(struct stack_list_s *s, int e)
{
    struct node_s *n;

    if(!s)
        assert("invalid argument, list is invalid");

    n = (struct node_s *)malloc(sizeof(struct node_s));
    n->element = e;
    single_linked_list_append(s->head, n);
    s->nb_elements++;
}

int stack_list_pop(struct stack_list_s *s)
{
    struct node_s *n;
    int element;

    if(!s)
        assert("invalid argument, list is invalid");

    n = single_linked_list_last(s->head);
    element = n->element;
    single_linked_list_remove(s->head, n);
    s->nb_elements--;

    return element;
}

int stack_list_peek(struct stack_list_s *s)
{
    struct node_s *n;

    if(!s)
        assert("invalid argument, list is invalid");

    n = single_linked_list_last(s->head);

    return n->element;
}
