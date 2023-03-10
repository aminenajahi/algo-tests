#ifndef __TREE_H__
#define __TREE_H__

struct node_s {
    struct node_s *children[];
    int nb_children;
    int element;
};

struct tree_s {
    struct node_s *root;
};

int tree_print(struct tree_s *tree);
bool tree_lookup(struct node_s *root, struct node_s *x);
void tree_insert(struct tree_s *tree, struct node_s *p, struct node_s *x);
bool tree_remove(struct tree_s *tree, struct node_s *x);


#endif // __TREE_H__
