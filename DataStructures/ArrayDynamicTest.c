#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ArrayDynamic.h"

int main()
{
    struct dynamic_array_s array = {};;

    printf("Run tests for dynamic array DS\n");

    dynamic_array_create(&array, 10);

    for (int i = 0; i < 10; i++)
        dynamic_array_push(&array, i);

    printf("Test push 10 elements result:\n");
    dynamic_array_print(&array);

    printf("Test lookup each element:\n");
    for (int i = 0; i < 10; i++)
    if (dynamic_array_lookup(&array, i) != i)
        assert("lookup test failed\n");

    dynamic_array_remove(&array, 5);
    printf("Test, remove 1 element result:\n");
    dynamic_array_print(&array);

    dynamic_array_insert(&array, 5, 5);
    printf("Test, add 1 element result:\n");
    dynamic_array_print(&array);

    printf("TEST COMPLETED");
    return 0;
}
