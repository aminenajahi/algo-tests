#ifndef __SINGLE_LINKED_LIST_H_INCLUDED
#define __SINGLE_LINKED_LIST_H_INCLUDED
#include <stdbool.h>

struct node_s {
    struct node_s *next;
    int element;
};

void single_linked_list_print(struct node_s *head);
struct node_s *single_linked_list_append(struct node_s *head, struct node_s *x);
struct node_s *single_linked_list_prepend(struct node_s *head, struct node_s *x);
struct node_s *single_linked_list_lookup(struct node_s *head, struct node_s *x);
struct node_s *single_linked_list_lookup_by_element(struct node_s *head, int element);
void single_linked_list_insert(struct node_s *head, struct node_s *p, struct node_s *x);
struct node_s *single_linked_list_remove(struct node_s *head, struct node_s *x);
struct node_s *single_linked_list_last(struct node_s *head);

#endif // __SINGLE_LINKED_LIST_H_INCLUDED

