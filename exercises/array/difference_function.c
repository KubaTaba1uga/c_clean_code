//  return a dynamically allocated array
//  assign the length of this array to *z
//  memory will be freed by the test suite

/* Example: */
/*	array_diff({1, 2}, 2, {1}, 1, *z) == {2} (z == 1) */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2,
                size_t *z) {
  int *array = (int *)malloc(*z);
  bool is_in_arr1 = false;
  *z = 0;

  for (int i = 0; (size_t)i < n1; ++i) {
    for (int j = 0; (size_t)j < n2; ++j) {
      if (arr1[i] == arr2[j])
        is_in_arr1 = true;
      printf("arr1[%d]=%d arr2[%d]=%d\n", i, arr1[i], j, arr2[j]);
      printf("Is in both arrays? %s\n", is_in_arr1 == true ? "yes" : "no");
    }

    if (is_in_arr1 == false) {
      array[(int)*z] = arr1[i];
      *z = *z + 1;
    } else
      is_in_arr1 = false;
  }
  return array;
}

int main(void) {
  size_t z = 4;
  int arr1[5] = {1, 2, 2, 3, 5};
  int arr2[2] = {1, 3};
  int *array = array_diff(arr1, 5, arr2, 2, &z);

  printf("array[0]=%i\nz=%d\n", array[0], (int)z);
  printf("array[1]=%i\nz=%d", array[1], (int)z);
  printf("array[2]=%i\nz=%d\n", array[2], (int)z);
  free(array);
}
