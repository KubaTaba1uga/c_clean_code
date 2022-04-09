#ifndef EXAMPLE_CONTEXT_H
#define EXAMPLE_CONTEXT_H

typedef struct {
  int a;
  int b;
} numbers;

int create_random_n(int lower, int upper);

numbers *create_numbers(int a, int b);

numbers *create_random_numbers(int min, int max);

#endif
