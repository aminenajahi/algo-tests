#ifndef __ARRAY_DYNAMIC_H_INCLUDED
#define __ARRAY_DYNAMIC_H_INCLUDED

#define BLOCK_SIZE 5

struct dynamic_array_s
{
    int *container;
    int nb_elements;
    int capacity;
};

void dynamic_array_create(struct dynamic_array_s *array, int capacity);
void dynamic_array_expand(struct dynamic_array_s *array);
int dynamic_array_lookup(struct dynamic_array_s *array, int index);
void dynamic_array_push(struct dynamic_array_s *array, int element);
void dynamic_array_insert(struct dynamic_array_s *array, int index, int element);
int dynamic_array_remove(struct dynamic_array_s *array, int index);
void dynamic_array_print(struct dynamic_array_s *array);

#endif // __ARRAY_DYNAMIC_H_INCLUDED
