/* `void` means "cannot hold any value" however, */
/*     `void *` means "can hold value of any type" */

#include <stdio.h>

/* To specify that function return no value */
/*      and that take no arguments. */
void my_func(void) {}

int main(void) {
  /* No value created explicitly. */
  void my_func();
  /* No value created implicitly */
  my_func();

  int a = 10;

  /* Hold pointer to integer */
  void *pa = &a;

  /* Derefference pointer to integer with */
  /*     proper casting. */
  printf("%i\n", *(int *)pa);

  return 0;
}
