#ifndef __STACK_LIST_H__
#define __STACK_LIST_H__
#include "SingleLinkedList.h"

struct stack_list_s {
    struct node_s *head;
    int nb_elements;
};

void stack_list_print(struct stack_list_s *s);
void stack_list_push(struct stack_list_s *s, int e);
int stack_list_pop(struct stack_list_s *s);
int stack_list_lookup(struct stack_list_s *s);
int stack_list_peek(struct stack_list_s *s);
int stack_list_size(struct stack_list_s *s);
bool stack_list_is_empty(struct stack_list_s *s);

#endif // __STACK_LIST_H__
