#ifndef __ARRAY_STATIC_H_INCLUDED
#define __ARRAY_STATIC_H_INCLUDED

#define ARRAY_SIZE 100

struct static_array_s
{
    int container[ARRAY_SIZE];
    int nb_elements;
};

int static_array_lookup(struct static_array_s *array, int index);
void static_array_push(struct static_array_s *array, int element);
void static_array_insert(struct static_array_s *array, int index, int element);
void static_array_remove(struct static_array_s *array, int index);
void static_array_print(struct static_array_s *array);

#endif // __ARRAY_STATIC_H_INCLUDED
