#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "QueueList.h"

int main()
{
    struct queue_list_s queue = {};
    queue.dll = (struct double_linked_list*) malloc(sizeof(struct double_linked_list));
    queue.dll->head = queue.dll->tail = 0;

    printf("Testing Queue List DS\n");
    printf("Test, enqueue 10 element\n");
    for (int i = 0; i < 10; i++)
    {
        queue_list_enqueue(&queue, i);
    }
    queue_list_print(&queue);

    printf("Test, dequeue 3 nodes\n");
    for (int i = 0; i < 3; i++) {
        queue_list_dequeue(&queue);
        queue_list_print(&queue);

    }
    queue_list_print(&queue);

    printf("Test, peek \n");
    printf("peek %d, expected 3\n", queue_list_peek(&queue));

    printf("Test, enqueue 2 element\n");
    for (int i = 10; i < 12; i++)
    {
        queue_list_enqueue(&queue, i);
    }
    queue_list_print(&queue);

    return 0;
}
