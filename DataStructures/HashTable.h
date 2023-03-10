#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED
#include "SingleLinkedList.h"

#define HASH_SIZE   25

// array of linked lists.
struct hashtable_s {
    struct nodes_s *containers[HASH_SIZE];
};

void hash_table_print(struct hashtable_s *hashtable);
bool hash_table_lookup(struct hashtable_s *hashtable, int element);
void hash_table_insert(struct hashtable_s *hashtable, int element);
int hash_table_compute_hash(int element);
void hash_table_delete(struct hashtable_s *hashtable, int element);

#endif // HASH_TABLE_H_INCLUDED
