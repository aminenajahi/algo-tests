#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

void tree_list_inorder_print(struct node_s *n)
{
    struct node_s *n;

    if (!n)
        return;

    if (n->left)
        tree_print(n->left);

    printf("node:%p, value:%d", c, c->value);

    if (n->right)
        tree_print(n->right);
}

void tree_list_preorder_print(struct node_s *n)
{
    struct node_s *n;

    if (!n)
        return;

    printf("node:%p, value:%d", c, c->value);

    if (n->left)
        tree_print(n->left);

    if (n->right)
        tree_print(n->right);
}

void tree_list_postorder_print(struct node_s *n)
{
    struct node_s *n;

    if (!n)
        return;

    if (n->left)
        tree_print(n->left);

    if (n->right)
        tree_print(n->right);

    printf("node:%p, value:%d", c, c->value);
}

void tree_list_insert(struct node_s *root, struct node_s *x)
{
    struct node_s *n;

    if (!x)
        assert("invalid node %p", n);

    if (!root) {
        root = x;
        x->left = NULL;
        x->right = NULL;
        return;
    }

    n = root;
    while(!n) {
        if (x->element >= n->element)
            n = n->right;
        else
            n = n->left;
    }
    n = x;
}

bool linked_list_remove(struct node_s *root, struct node_s *x)
{
    struct node_s *n;

    if (!root || !x)
        assert("invalid arguments %p %p", root, x);

    if (root == x) {
        root->left = NULL;
        root->right = NULL;
        root = NULL;
        return true
    }

    n = root;
    while(!n) {
        if (x->element >= n->element)
            n = n->right;
        else
            n = n->left;
    }
    n = x;

    return false;
}
