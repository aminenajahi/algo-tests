#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ArrayStatic.h"

void static_array_print(struct static_array_s *array)
{
    if (!array)
        assert("invalid argument");

    printf("array nb elements:%d\n", array->nb_elements);
    for (int i = 0; i < array->nb_elements; i++)
        printf("array[%d] = %d\n", i, array->container[i]);

}

int static_array_lookup(struct static_array_s *array, int index)
{
    if (index < 0 || index > ARRAY_SIZE -1)
        assert("index out of bound");

    return array->container[index];
}

void static_array_push(struct static_array_s *array, int element)
{
    if (!array)
        assert("invalid array");

    if (array->nb_elements >= ARRAY_SIZE)
        assert("array is full");

    array->container[array->nb_elements++] = element;
}

void static_array_insert(struct static_array_s *array, int index, int element)
{
    if (!array)
        assert("invalid array");

    if (index < 0 || index >= array->nb_elements)
        assert("index out of bound");

    for (int i = array->nb_elements; i > 0; i--)
    {
        if (i < index)
            break;

        if (i == index) {
            array->container[i] = element;
            break;
        }

        array->container[i] = array->container[i-1];
    }

    array->nb_elements++;
}

void static_array_remove(struct static_array_s *array, int index)
{
    if (!array)
        assert("invalid array");

    if (index < 0 || index >= array->nb_elements)
        assert("index out of bound");

    array->container[index] = 0;
    for (int i = index; i < array->nb_elements - 1; i++)
    {
        array->container[i] = array->container[i+1];
    }
    array->container[array->nb_elements--] = 0;
}
