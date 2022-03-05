#include <stdio.h>

/* sizeof(array) - array size */
/* sizeof(*array) - first element size */
#define get_array_length(array) (sizeof(array) / sizeof(*array))

/* Only soultion by function is to pass */
/* 	array size explicitly. As sizeof */
/* 	is compile-time expression. */
int calculate_array_length(int array_size, int element_size) {
  return array_size / element_size;
}

int main(void) {

  int a[4] = {5, 1, 3};

  int a_len = get_array_length(a);

  printf("Length of `a`: %i\n", a_len);

  int b[99];

  int b_len = calculate_array_length(sizeof(b), sizeof(*b));

  printf("Length of `b`: %i\n", b_len);

  return 0;
}
