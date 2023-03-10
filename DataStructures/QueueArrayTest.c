#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "QueueArray.h"

int main()
{
    struct queue_array_s queue = {};

    printf("Testing Queue Array DS\n");
    printf("Test, enqueue 10 element\n");
    for (int i = 0; i < 10; i++)
    {
        queue_array_enqueue(&queue, i);
    }
    queue_array_print(&queue);

    printf("Test, dequeue 3 nodes\n");
    for (int i = 0; i < 3; i++)
        printf("dequeue %d\n", queue_array_dequeue(&queue));

    queue_array_print(&queue);

    printf("Test, peek \n");
    printf("peek %d, expected 3\n", queue_array_peek(&queue));

    return 0;
}
