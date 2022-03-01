#include <stdio.h>

/* An array is contigously allocated sequence
        of objects that all have the same type. */

int main(void) {
  /* Array of 3 integers. */
  int int_array[3] = {1, 2, 3};

  /* Array of non-specified number of integers. */
  extern int int_nlen_array[];

  /* Array of 5 pointers to integers. */
  int *pint_array[5];

  /* Array of 3 arrays of 5 integers. */
  int two_dim_array[3][5];

  /* Pointer to array points to its first element. */
  printf("Pointer to array: %p\n", int_array);

  /* Dereferencing pointer gives value of first element. */
  int first_array_element = *int_array;

  /* So elements can be accessed on two ways. */

  /* Adding element index to pointer. Let assume
     that pointer is set on 32bits integer (4 bytes)
     at address 1000, adding 32bits integer to
     it will mean pointing to address at 1004.
     Adding two 32bits integer will mean
     pointing to address at 1008 (third element).  */
  int second_array_element = *(int_array + 1);

  /* Or using syntax. Above mechanism shortcut. */
  int third_array_element = int_array[2];

  printf("Array: [%d, %d, %d]\n", int_array[0], int_array[1], int_array[2]);
  printf(" First element: %d\n", first_array_element);
  printf("Second element: %d\n", second_array_element);
  printf(" Third element: %d\n", third_array_element);

  return 0;
}
