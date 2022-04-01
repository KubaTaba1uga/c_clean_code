/* VLAs (variable length array) are arrays that */
/* 	can be declared using a variable to specify */
/* 	its length. Because so they size can be  */
/* 	specified at runtime. */

#include <stdio.h>

// Function using VLA
void print_array(size_t size, int arr[size]) {
  printf("[ ");
  while (size-- > 0)
    printf("%i, ", *arr++);
  puts("]");
}

int main(void) {
  size_t arr_size = 5;
  int arr[] = {1, 2, 3, 4, 5};
  print_array(arr_size, arr);

  return 0;
}
