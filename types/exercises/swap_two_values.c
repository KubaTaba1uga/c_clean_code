#include <stdio.h>

/* Declare arguments to be pointers */
void swap(int *pa, int *pb) {
  /* Dereference pointers to pass
        their objects real values */
  int temp = *pb;
  *pb = *pa;
  *pa = temp;
}

int main(void) {
  int a = 21;
  int b = 17;

  printf("Before swap: a=%i, b=%i \n", a, b);

  /* Pass pointers to function */
  swap(&a, &b);

  printf("Aftter swap: a=%i, b=%i \n", a, b);

  return 0;
}
