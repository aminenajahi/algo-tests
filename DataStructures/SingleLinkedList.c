#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "SingleLinkedList.h"

void single_linked_list_print(struct node_s *head)
{
    struct node_s *c;

    if (!head)
        assert("invalid list head\n");

    printf("print list:\n");

    c = head;
    while(c != NULL) {
        printf("node:%p, value:%d, next:%p\n", c, c->element, c->next);
        c = c->next;
    }
}

struct node_s *single_linked_list_prepend(struct node_s *head, struct node_s *x)
{
    if (!x)
        assert("invalid node");

    if (!head) {
        x->next = NULL;
        printf("head node not available");
        return x;
    }
//  x + n0->n1->n2->n3->...
//  x->n0->n1->n2->n3

    x->next = head;

    return x;
}

struct node_s *single_linked_list_append(struct node_s *head, struct node_s *x)
{
    struct node_s *c;

    if (!x)
        assert("invalid node");

    if (!head) {
        x->next = NULL;
        printf("head node not available\n");
        return x;
    }

    c = head;
    while(c->next)
        c = c->next;

    c->next = x;
    x->next = NULL;

    return head;
}

struct node_s *single_linked_list_lookup(struct node_s *head, struct node_s *x)
{
    struct node_s *c;

    if (!head || !x)
        assert("invalid arguments");

    c = head;
    while(c) {
        if (c == x)
            return c;

        c = c->next;
    }

    return NULL;
}
struct node_s *single_linked_list_lookup_by_element(struct node_s *head, int element)
{
    struct node_s *c;

    if (!head)
        assert("invalid arguments");

    c = head;
    while(c) {
        if (c->element == element)
            return c;

        c = c->next;
    }

    return NULL;
}

void single_linked_list_insert(struct node_s *head, struct node_s *p, struct node_s *x)
{
    struct node_s *n;

    if (!head || !p || !x)
        assert("invalid arguments");

    n = p->next;
    p->next = x;
    x->next = n;
}

struct node_s *single_linked_list_remove(struct node_s *head, struct node_s *x)
{
    struct node_s *c, *p, *n;

    if (!head || !n)
        assert("invalid arguments");

    if (head == x) {
        return head->next ? head->next : NULL;
    }

    c = head;
    while (c) {
        if (c == x) {
            p->next = c->next;
            c->next = NULL;
            return head;
        }
        p = c;
        c = c->next;
    }

    return head;
}

struct node_s* single_linked_list_last(struct node_s *head)
{
    struct node_s *c;

    if (!head)
        assert("invalid arguments");

    c = head;
    while (c->next != NULL)
        c = c->next;

    return c;
}
