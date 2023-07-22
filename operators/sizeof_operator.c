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

  /* Pointers are fixed in size. On 32-bit system */
  /*   memory address is stored as a 32-bit number. */
  /*   In 64-bit system memory address is stored as */
  /*   64-bit number.  */
  int b = 1;
  char c = '1';
  long int d = 1L;

  size_t b_size = sizeof(&b);
  printf("Pointer to `b` size is %lu bytes\n", b_size);
  size_t c_size = sizeof(&c);
  printf("Pointer to `c` size is %lu bytes\n", c_size);
  size_t d_size = sizeof(&d);
  printf("Pointer to `d` size is %lu bytes\n", d_size);

  return 0;
}
