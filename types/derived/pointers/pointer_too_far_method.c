#include <stdio.h>
#include <stdlib.h>

int main(void) {
  /* Too far pointer method, is about */
  /*   performing operation unitil the */
  /*   memory address of array length */
  /*   + 1 is not reached. */
  int arr[5];

  int i = 0;

  // `tf_p` is pointing to first element.
  for (int *tf_p = arr;
       // perform operation until length + 1 is not reached.
       tf_p < &arr[5];
       // increment pointer addres + siizeof(int) after each iteration.
       tf_p++)
    *tf_p = i++;

  printf("arr[0] = %i\n", arr[0]);

  printf("arr[4] = %i\n", arr[4]);

  return 0;
}
