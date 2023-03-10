#ifndef __STACK_ARRAY_H__
#define __STACK_ARRAY_H__
#include <stdbool.h>

#define MAX_SIZE 100

struct stack_array_s {
  int elements[MAX_SIZE];
  int nb_elements;
};

void stack_array_print(struct stack_array_s *s);
void stack_array_push(struct stack_array_s *s, int e);
int stack_array_pop(struct stack_array_s *s);
int stack_array_lookup(struct stack_array_s *s);
int stack_array_peek(struct stack_array_s *s);
int stack_array_size(struct stack_array_s *s);
bool stack_array_is_empty(struct stack_array_s *s);

#endif // __STACK_ARRAY_H__

