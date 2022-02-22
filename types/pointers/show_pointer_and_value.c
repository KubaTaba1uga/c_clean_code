#include <stdio.h>

void show(int *pa) {
  printf("Memory address: %p\n", pa);
  /* Dereference pointer */
  printf("Variable value: %i\n", *pa);
}

int main(void) {
  int a = 5;

  /* Pass reference to variable */
  show(&a);
}
