#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ArrayStatic.h"

int main()
{
    struct static_array_s array = {};

    printf("Run tests for static array DS\n");

    for (int i = 0; i < 10; i++)
        static_array_push(&array, i);

    printf("Test push 10 elements result:\n");
    static_array_print(&array);

    printf("Test lookup each element:\n");
    for (int i = 0; i < 10; i++)
    if (static_array_lookup(&array, i) != i)
        assert("lookup test failed\n");

    static_array_remove(&array, 5);
    printf("Test, remove 1 element result:\n");
    static_array_print(&array);

    static_array_insert(&array, 5, 5);
    printf("Test, add 1 element result:\n");
    static_array_print(&array);

    return 0;
}
