#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int arr[100];
  for (int i = 0; i < 100; i++)
    arr[i] = i;

  int *a_p = NULL, *b_p = NULL;

  /* `a_p` points to 40th element of array. */
  a_p = &arr[40];

  printf("arr[40] = %i\n", *a_p);

  /* `b_p` points to 20th element of array. */
  b_p = a_p - 20; // pointers substraction result is `ptrdiff_t` type.

  printf("arr[20] = %i\n", *b_p);

  return 0;
}
