#include <stdio.h>

/* Objects declared in file scope have */
/*         `static` storage duration by default. */

/* The lifetime of `static` storage duration */
/*         is entire execution of the program. */
void increment(void) {
  static int x = 0;

  printf("x=%i\n", x);

  x++;
}

int main(void) {
  for (int i = 0; i < 10; ++i) {
    increment();
  }

  /* `static` has to be used with constant values. */
  /*     Like: `5` `c` `abc`. */
  /*     Not with variables or pointer. */

  return 0;
}
