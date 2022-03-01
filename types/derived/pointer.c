#include <stdio.h>

void show(int *pa) {
  printf("Memory address: %p\n", pa);
  /* Dereference pointer */
  printf("Variable value: %i\n", *pa);
}

int main(void) {
  int a = 5;

  /* Pass memory address of
     variable to function */
  show(&a);

  /* Memory address and dereference */
  /*     can cancel each other. */
  printf("Cancelation result: %i\n", *&a);

  return 0;
}
