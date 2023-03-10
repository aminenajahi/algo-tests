#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "QueueArray.h"

int queue_array_size(struct queue_array_s *q)
{
    return q->nb_elements;
}

bool queue_array_is_empty(struct queue_array_s *q)
{
    return q->nb_elements == 0 ? true : false;
}

bool queue_array_is_full(struct queue_array_s *q)
{
    return q->nb_elements > 0 ? true : false;
}

void queue_array_print(struct queue_array_s *q)
{
    int nb_elements;

    if (!q)
        assert("invalid queue\n");

    printf("queue head %d, tail %d, nb_elements %d\n", q->head, q->tail, q->nb_elements);
    for(int i=q->head; i<q->tail; i++,nb_elements++)
        printf("%d -> queue position[%d] = %d\n", nb_elements, i, q->elements[i]);
}

void queue_array_enqueue(struct queue_array_s *q, int element)
{
    if (!q)
        assert("invalid queue\n");

    if (queue_array_is_full(q))
        assert("no more space in the queue\n");

    q->elements[q->tail] = element;
    q->tail = (q->tail + 1) % MAX_SIZE;
    q->nb_elements++;

}

int queue_array_dequeue(struct queue_array_s *q)
{
    int element;

    if (!q)
        assert("invalid queue\n");

    if (queue_array_is_empty(q))
        assert("queue is empty\n");

    element = q->elements[q->head];
    q->head = (q->head + 1) % MAX_SIZE;
    q->nb_elements--;

    return element;
}

int queue_array_peek(struct queue_array_s *q)
{
    int element;

    if (!q)
        assert("invalid queue\n");

    if (queue_array_is_empty)
        assert("queue is empty\n");

    element = q->elements[q->head];

    return element;
}
