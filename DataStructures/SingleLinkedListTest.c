#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "SingleLinkedList.h"

int main()
{
    struct node_s *n0 = NULL;

    printf("Testing Single Linked List DS\n");
    printf("Test, append 5 nodes\n");
    for (int i = 0; i < 5; i++)
    {
        printf("append node %d\n", i);
        struct node_s *n = (struct node_s *)malloc(sizeof(struct node_s));
        if (!n)
            assert("invalid node\n");

        n->element = i;
        n0 = single_linked_list_append(n0, n);
        single_linked_list_print(n0);
    }
    single_linked_list_print(n0);

    printf("Test, prepend 5 nodes\n");
    for (int i = 5; i < 10; i++)
    {
        printf("prepend node %d\n", i);
        struct node_s *n = (struct node_s *)malloc(sizeof(struct node_s));
        if (!n)
            assert("invalid node\n");

        n->element = i;
        n0 = single_linked_list_prepend(n0, n);
        single_linked_list_print(n0);
    }
    single_linked_list_print(n0);

    printf("Test, lookup for node with value 5\n");
    struct node_s *n = single_linked_list_lookup_by_element(n0, 5);
    if (!n)
        printf("node not found\n");
    printf("node with value 5 %p value %d\n", n, n->element);

    struct node_s *s = single_linked_list_last(n0);
    printf("last node %p, value %d\n", s, s->element);

    struct node_s *x = (struct node_s *)malloc(sizeof(struct node_s));
    x->element = 100;
    single_linked_list_insert(n0, n, x);
    single_linked_list_print(n0);



    return 0;
}
