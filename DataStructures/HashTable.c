#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "HashTable.h"

void hash_table_print(struct hashtable_s *hashtable)
{
    if (!hashtable)
        assert("invalid hashtable");

    printf("Hashtable content\n");
    for (int i = 0; i < HASH_SIZE; i++)
    {
        printf("Hashtable[%d] -> %s\n", i, hashtable->containers[i] ? "valid" : "invalid");
        single_linked_list_print(hashtable->containers[i]);
    }
}

int hash_table_compute_hash(int element)
{
    return element % HASH_SIZE;
}

bool hash_table_lookup(struct hashtable_s *hashtable, int element)
{
    int hash_key;
    struct node_s *n;

    if (!hashtable)
        assert("invalid hashtable\n");

    hash_key = hash_table_compute_hash(element);
    if (!hashtable->containers[hash_key])
        return false;

    n = single_linked_list_lookup_by_element(hashtable->containers[hash_key], element);

    return n ? true : false;
}

void hash_table_insert(struct hashtable_s *hashtable, int element)
{
    int hash_key;
    struct node_s *n;

    if (!hashtable)
        assert("invalid hashtable\n");

    hash_key = hash_table_compute_hash(element);
    n = (struct node_s *)malloc(sizeof(struct node_s));
    n->element = element;
    hashtable->containers[hash_key] = single_linked_list_append(hashtable->containers[hash_key], n);
}

void hash_table_delete(struct hashtable_s *hashtable, int element)
{
    int hash_key;
    struct node_s *n;

    if (!hashtable)
        assert("invalid hashtable\n");

    hash_key = hash_table_compute_hash(element);
    if(!hashtable->containers[hash_key])
        return;

    n = single_linked_list_lookup_by_element(hashtable->containers[hash_key], element);
    hashtable->containers[hash_key] = single_linked_list_remove(hashtable->containers[hash_key], n);
}

