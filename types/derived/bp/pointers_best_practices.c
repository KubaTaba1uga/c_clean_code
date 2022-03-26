#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isN(int *ptr, int n) {
  /* Only dereferrence pointer if it is not NULL. */
  return ptr && *ptr == n;
}

void print_pointer(int *value, char *equation) {
  printf("%s %s\n\n", equation,
         value ? "allocated succesfully." : "can't be allocated.");
}

int main(void) {
  /* Always assign NULL to pointer when  */
  /*   not allocatin memory. To avoid */
  /*	dereferecing pointers to invalid */
  /*	memory locations. */
  int *array_of_4 = NULL;

  printf("Calculations done.\n\n");

  print_pointer(array_of_4, "array_of_4");

  /* When `malloc` is unable to allocate */
  /*   memory. It assigns `NULL` to pointer. */
  array_of_4 = (int *)malloc(sizeof(int) * 4);

  array_of_4[1] = 5;
  array_of_4[2] = 55;
  array_of_4[3] = 555;
  array_of_4[4] = 5555;

  print_pointer(array_of_4, "array_of_4");

  free(array_of_4);

  int a = 5, *b, *c;
  b = c = &a;
  /* To check are two pointers  */
  /* 	points to the same variable */
  /* 	use comparasion. */
  if (b == c)
    puts("`b` and `c` points to `a`");

  return 0;
}
