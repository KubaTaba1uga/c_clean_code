#include <stdio.h>

/* Lifetime of variables passed as values */
/*         is automatic, because their */
/*         exsistanceis over when their */
/*         visability is. */
int sum_two_memory_numbers(int *a, int *b) { return *a + *b; }
int sum_two_register_numbers(int a, int b) { return a + b; }

int main(void) {
  /* There are two types of automatic variables. */

  /* Stored in memory. */
  auto int a = 9, b = 13;

  /* Stored in cpu register */
  register int c = 9, d = 13;

  int memory_result = sum_two_memory_numbers(&a, &b);

  /* As reister hasn't got memory kind addresation. */
  /*     Pointers can't be used with it. */
  register int register_result = sum_two_register_numbers(c, d);

  printf("  Memory result %i\n", memory_result);
  printf("Registry result %i\n", register_result);
}
