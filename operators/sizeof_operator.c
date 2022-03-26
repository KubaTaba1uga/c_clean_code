#include <stdio.h>

int main(void) {
  /* Use `sizeof` to find variable size in bytes. */
  int a = 1;
  /* Size is always `size_t` type */
  size_t a_size = sizeof(a);
  printf("`a` size is %lu bytes\n", a_size);

  /* Use `sizeof` to find type size in bytes. */
  size_t i_size = sizeof(int);
  printf("`int` size is %lu bytes\n", i_size);

  /* It is always safe to paranthesize the operand, */
  /*   because it is not changing the way the size */
  /*   is calculated. Without parantheses behaviour */
  /*   of the operand differs between type and */
  /*   variable. */

  /* This would throw error. */
  // size_t int_size = sizeof int;

  /* This not. */
  // size_t a_size = sizeof a;

  return 0;
}
