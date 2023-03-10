#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "DoubleLinkedList.h"

void double_linked_list_print(struct double_linked_list *dll)
{
    struct node_s *c;

    if (!dll)
        assert("invalid list head\n");

    if (!dll->head || !dll->tail)
        assert("invalid list head or tail\n");

    printf("print list info head:%p, tail:%p\n", dll->head, dll->tail);

    c = dll->head;
    while(c != NULL) {
        printf("node:%p, next:%p, previous:%p, value:%d\n", c, c->next, c->previous, c->element);
        c = c->next;
    }
}

struct double_linked_list *double_linked_list_prepend(struct double_linked_list *dll, struct node_s *x)
{
    if (!x)
        assert("invalid node\n");

    if (!dll)
        assert("invalid list head\n");

    if (!dll->head || !dll->tail) {
        x->next = x->previous = NULL;
        dll->head = dll->tail = x;
        return dll;
    }

    // head<->n1<->n2<->n3->NULL
    // x<->head<->n1<->n2<->n3->NULL
    dll->head->previous = x;
    x->next = dll->head;
    x->previous = NULL;
    dll->head = x;

    return dll;
}

struct double_linked_list *double_linked_list_append(struct double_linked_list *dll, struct node_s *x)
{
    if (!dll)
        assert("invalid list\n");

    if (!x)
        assert("invalid node\n");

    // case where this is the first node in the list
    if (!dll->head || !dll->tail) {
        x->next = x->previous = NULL;
        dll->head = dll->tail = x;
        return dll;
    }

    dll->tail->next = x;
    x->previous = dll->tail;
    x->next = NULL;
    dll->tail = x;

    return dll;
}

struct node_s *double_linked_list_lookup_by_node(struct double_linked_list *dll, struct node_s *x)
{
    struct node_s *c;

    if (!dll)
        assert("invalid list\n");

    if (!x)
        assert("invalid node\n");

    c = dll->head;
    while(c) {
        if (c == x)
            return c;

        c = c->next;
    }

    return NULL;
}

struct node_s *double_linked_list_lookup_by_element(struct double_linked_list *dll, int element)
{
    struct node_s *c;

    if (!dll)
        assert("invalid list\n");

    c = dll->head;
    while(c) {
        if (c->element == element)
            return c;

        c = c->next;
    }

    return NULL;
}

struct double_linked_list *double_linked_list_insert(struct double_linked_list *dll, struct node_s *p, struct node_s *x)
{
    struct node_s *n;

    if (!dll || !p || !x)
        assert("invalid arguments\n");

    if (!dll->head || !dll->tail)
        assert("invalid list, no head or tail\n");

    // head => n0, tail->n2, p->n2
    // n0<->n1<->n2->NULL
    // n0<->n1<->n2<->x->NULL
    // head => n0, tail = x
    if (dll->tail == p)
    {
        p->next = x;
        x->previous = p;
        x->next = NULL;
        dll->tail = x;
        return dll;
    }

    // head => n0, tail->n2
    // n0<->n1<->n2->NULL
    // n0<->x<->n1<->n2->NULL

    //save next node
    n = p->next;

    // right side connections
    n->previous = x ;
    x->next = n;

    //left side connections
    p->next = x;
    x->previous = p;

    return dll;
}

struct double_linked_list *double_linked_list_remove(struct double_linked_list *dll, struct node_s *x)
{
    struct node_s *c, *p, *n;

    if (!dll || !x)
        assert("invalid arguments\n");

    if (!dll->head || !dll->tail)
        assert("invalid list, no head or tail\n");

    // only 1 node n the list
    // head = n0, tail = n0, p = n0
    // n0->NULL
    // NULL
    // head = NULL, tail = NULL
    if (dll->head == dll->tail)
    {
        p->next = NULL;
        p->previous = NULL;
        dll->head = NULL;
        dll->tail = NULL;
        return dll;
    }

    // only 1 node n the list
    // head = n0, tail = n1, x = n0
    // n0<->n1->NULL
    // n1->NULL
    // head = n1, tail = n1
    c = dll->head;
    while (c) {
        if (c == x) {
            //save links
            p = x->previous;
            n = x->next;

            //remove node x;
            x->next = NULL;
            x->previous = NULL;

            if (p!=NULL)
                p->next = n;

            if (n!=NULL)
                n->previous = p;

            if (dll->head == x)
                dll->head = n;

            if (dll->tail == x)
                dll->tail = p;

            return dll;
        }
        c = c->next;
    }

    return NULL;
}
