#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "doubleLinkedList.h"

int main()
{
    struct double_linked_list dll = {};

    printf("Testing double Linked List DS\n");
    printf("Test, append 5 nodes\n");
    for (int i = 0; i < 5; i++)
    {
        printf("append node %d\n", i);
        struct node_s *n = (struct node_s *)malloc(sizeof(struct node_s));
        if (!n)
            assert("invalid node\n");

        n->element = i;
        double_linked_list_append(&dll, n);
        double_linked_list_print(&dll);
    }
    double_linked_list_print(&dll);

    printf("Test, prepend 5 nodes\n");
    for (int i = 5; i < 10; i++)
    {
        printf("prepend node %d\n", i);
        struct node_s *n = (struct node_s *)malloc(sizeof(struct node_s));
        if (!n)
            assert("invalid node\n");

        n->element = i;
        double_linked_list_prepend(&dll, n);
        double_linked_list_print(&dll);
    }
    double_linked_list_print(&dll);

    printf("Test, lookup for node with value 5\n");
    struct node_s *n = double_linked_list_lookup_by_element(&dll, 5);
    if (!n)
        printf("node not found\n");
    printf("node with value 5 %p value %d\n", n, n->element);

    struct node_s *x = (struct node_s *)malloc(sizeof(struct node_s));
    x->element = 100;
    double_linked_list_insert(&dll, n, x);
    double_linked_list_print(&dll);

    return 0;
}
