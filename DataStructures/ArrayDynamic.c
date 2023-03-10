#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ArrayDynamic.h"

void dynamic_array_print(struct dynamic_array_s *array)
{
    if (!array)
        assert("invalid argument");

    printf("array capacity %d, nb elements:%d\n", array->capacity, array->nb_elements);
    for (int i = 0; i < array->nb_elements; i++)
        printf("array[%d] = %d\n", i, array->container[i]);
}

void dynamic_array_create(struct dynamic_array_s *array, int capacity)
{
    if (capacity > BLOCK_SIZE)
        array->capacity = (capacity / BLOCK_SIZE + 1 ) * BLOCK_SIZE;

    array->container = (int*) malloc(capacity * sizeof(int));
    if (!array->container)
        assert("unable to create dynamic array");
}

void dynamic_array_expand(struct dynamic_array_s *array)
{
    int new_capacity;

    new_capacity = (array->capacity / BLOCK_SIZE + 1 ) * BLOCK_SIZE;
    array->container = (int*)realloc(array->container, new_capacity);
    if(!array->container)
        assert("unable to expand array to size");

    array->capacity = new_capacity;
}

int dynamic_array_lookup(struct dynamic_array_s *array, int index)
{
    if (index < 0 || index > array->capacity - 1)
        assert("index out of bound");

    return array->container[index];
}

void dynamic_array_push(struct dynamic_array_s *array, int element)
{
    if (array->nb_elements >= array->capacity)
        dynamic_array_expand(array);

    array->container[array->nb_elements++] = element;
}

void dynamic_array_insert(struct dynamic_array_s *array, int index, int element)
{
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

int dynamic_array_remove(struct dynamic_array_s *array, int index)
{
    if (index < 0 || index >= array->nb_elements)
        assert("index out of bound");

    array->container[index] = 0;
    for (int i = index; i < array->nb_elements - 1; i++)
    {
        array->container[i] = array->container[i+1];
    }
    array->container[array->nb_elements--] = 0;
}
