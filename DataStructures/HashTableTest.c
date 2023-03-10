#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "HashTable.h"

int main()
{
    struct hashtable_s ht = {};
    bool found;

    printf("Testing Hashtable DS\n");
    printf("Test, append 10 element\n");
    for (int i = 0; i < 10; i++)
    {
        hash_table_insert(&ht, i);
    }
    hash_table_print(&ht);

    printf("Test, lookup elements 0-9\n");
    for (int i = 0; i < 10; i++)
    {
        found = hash_table_lookup(&ht, i);
        printf("element %d %s\n", i, found ? "found" : "not found");
    }

    printf("Test, lookup elements 10-19\n");
    for (int i = 10; i < 19; i++)
    {
        found = hash_table_lookup(&ht, i);
        printf("element %d %s\n", i, found ? "found" : "not foun");
    }

    printf("Test, append 10 element\n");
    for (int i = 100; i < 110; i++)
    {
        hash_table_insert(&ht, i);
    }
    hash_table_print(&ht);

    printf("Test, remove 5 elements\n");
    for (int i = 0; i < 5; i++)
    {
        hash_table_delete(&ht, i);
    }
    hash_table_print(&ht);

    printf("Test, remove 5 elements\n");
    for (int i = 105; i < 110; i++)
    {
        hash_table_delete(&ht, i);
    }
    hash_table_print(&ht);

    return 0;
}
