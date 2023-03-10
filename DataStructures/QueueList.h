#ifndef __QUEUE_LIST_H__
#define __QUEUE_LIST_H__
#include <stdbool.h>
#include "DoubleLinkedList.h"

struct queue_list_s {
    struct double_linked_list *dll;
    int nb_elements;
};

void queue_list_print(struct queue_list_s *q);
void queue_list_enqueue(struct queue_list_s *q, int element);
int queue_list_dequeue(struct queue_list_s *q);
int queue_list_peek(struct queue_list_s *q);
int queue_list_size(struct queue_list_s *q);
bool queue_list_is_empty(struct queue_list_s *q);
bool queue_list_is_full(struct queue_list_s *q);

#endif // __QUEUE_LIST_H__
