/* `calloc` allocates storage for an array of objects. */
/* 	Allocated storage is initialized with 0s. */
#include <stdio.h>
/* `calloc` dependency */
#include <stdlib.h>

int main(void) {
  int number_of_elements = 4;
  int *arr = (int *)calloc(number_of_elements, sizeof(int));
  if (arr == NULL)
    return EXIT_FAILURE;

  int *arr_cp = arr;

  arr[0] = 1;
  arr[2] = 3;

  while (number_of_elements-- > 0)
    printf("%i\n", *arr_cp++);

  free(arr);

  return EXIT_SUCCESS;
}
