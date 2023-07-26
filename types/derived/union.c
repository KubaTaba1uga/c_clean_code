#include <stdio.h>

/* A union type contains sequentially
allocated memory objects, but unlike
array they can be different types and
unlike structure data can overlap itself. */

/* Union declaration */
/* allocates memory for the biggest type. */
/* In ex. below it would be sizeof(long int).  */
typedef union {
  long int count;
  float weight;
  float volume;
} quantity;

int main(void) {

  quantity computers = {.count = 1};
  quantity apples = {.weight = 155.3};
  quantity juice = {.volume = 6.4};

  /* Only last written fields should be read from. */
  printf("%li %f %f\n", computers.count, apples.weight, juice.volume);

  return 0;
}
