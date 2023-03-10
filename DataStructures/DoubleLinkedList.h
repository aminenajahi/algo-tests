#ifndef __DOUBLE_LINKED_LIST_H_INCLUDED
#define __DOUBLE_LINKED_LIST_H_INCLUDED
#include <stdbool.h>

struct node_s {
    struct node_s *next;
    struct node_s *previous;
    int element;
};

struct double_linked_list {
    struct node_s *head;
    struct node_s *tail;
};

void double_linked_list_print(struct double_linked_list *dll);
struct double_linked_list *double_linked_list_append(struct double_linked_list *dll, struct node_s *x);
struct double_linked_list *double_linked_list_prepend(struct double_linked_list *dll, struct node_s *x);
struct node_s *double_linked_list_lookup_by_node(struct double_linked_list *dll, struct node_s *x);
struct node_s *double_linked_list_lookup_by_element(struct double_linked_list *dll, int element);
struct double_linked_list *double_linked_list_insert(struct double_linked_list *dll, struct node_s *p, struct node_s *x);
struct double_linked_list *double_linked_list_remove(struct double_linked_list *dll, struct node_s *x);

#endif // __DOUBLE_LINKED_LIST_H_INCLUDED

