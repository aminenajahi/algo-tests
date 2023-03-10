#ifndef __QUEUE_ARRAY_H__
#define __QUEUE_ARRAY_H__
#include <stdbool.h>

#define MAX_SIZE 100

struct queue_array_s {
    int elements[MAX_SIZE];
    int head, tail;
    int nb_elements;
};

void queue_array_print(struct queue_array_s *q);
void queue_array_enqueue(struct queue_array_s *q, int element);
int queue_array_dequeue(struct queue_array_s *q);
int queue_array_peek(struct queue_array_s *q);
int queue_array_size(struct queue_array_s *q);
bool queue_array_is_empty(struct queue_array_s *q);
bool queue_array_is_full(struct queue_array_s *q);



#endif // __QUEUE_ARRAY_H__
