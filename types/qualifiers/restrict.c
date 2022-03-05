#include <stdio.h>
#define get_array_length(array, element) (array / element)

/* `restrict` says that the pointer is the only thing that accesses */
/* 	 the underlying object. It eliminates the potential for pointer */
/* 	 aliasing, enabling better optimization by the compiler. */

void copy(int n, int *array_a, int *array_b) {
  while (n-- > 0) {
    *array_a++ = *array_b++;
  }
}

void show_array(int *array, int array_len, char *array_name) {
  printf("%s = [", array_name);

  for (int i = 0; i < array_len; ++i) {

    printf("%i, ", array[i]);
  }
  puts("]");
}

int main(void) {
  /* pointer antilising caused by two pointers */
  /*   to the same value. */
  int array[5] = {1, 2, 3, 4, 5};

  /* compiler assume that those are two different */
  /*   pointers that why he is not optimised properly */
  copy(3, array, array);

  int array_len = get_array_length(sizeof(array), sizeof(*array));

  show_array(array, array_len, "array");

  return 0;
}
