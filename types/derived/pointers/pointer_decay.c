#include <stdio.h>

/* Because array variables are slightly different from pointer */
/* variables, you need to be careful when assigning arrays to pointers. */
/* If You assign an array to a pointer, variable will only contain the */
/* address of the array.  Informations about array length is lost. */

/* Every time You pass an arra to a function, decay is occuring.*/
/* Function do not know that pointer is to array variable! */
void show_pointer_decay(int array[]) {
  size_t a_size = sizeof(array);

  printf("After pointer decay, array size is %lu bytes\n", a_size);
}

int main() {
  int array[] = {1, 2, 3};

  size_t a_size = sizeof(array);
  printf("Before pointer decay, array size is %lu bytes\n", a_size);

  show_pointer_decay(array);

  return 0;
}
