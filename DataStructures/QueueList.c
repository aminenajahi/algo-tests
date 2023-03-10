#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "QueueList.h"

int queue_list_size(struct queue_list_s *q)
{
    return q->nb_elements;
}

bool queue_list_is_empty(struct queue_list_s *q)
{
    return q->nb_elements == 0 ? true : false;
}

void queue_list_print(struct queue_list_s *q)
{
    int nb_elements;

    if (!q)
        assert("invalid queue\n");

    printf("queue list nb_elements %d\n", q->nb_elements);
    double_linked_list_print(q->dll);
}

void queue_list_enqueue(struct queue_list_s *q, int element)
{
    struct node_s *n;

    if (!q)
        assert("invalid queue\n");

    n = (struct node_s *)malloc(sizeof(struct node_s));
    n->element = element;

    double_linked_list_append(q->dll, n);
    q->nb_elements++;
}

int queue_list_dequeue(struct queue_list_s *q)
{
    struct node_s *n;
    int element;

    if (!q)
        assert("invalid queue\n");

    if (queue_list_is_empty(q))
        assert("queue is empty\n");

    n = q->dll->head;
    element = n->element;
    double_linked_list_remove(q->dll, n);
    q->nb_elements--;

    return n;
}

int queue_list_peek(struct queue_list_s *q)
{
    struct node_s *n;
    int element;

    if (!q)
        assert("invalid queue\n");

    if (queue_list_is_empty(q))
        assert("queue is empty\n");

    n = q->dll->head;
    element = n->element;

    return element;
}
