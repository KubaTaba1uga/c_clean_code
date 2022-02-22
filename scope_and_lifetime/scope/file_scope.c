#include <stdio.h>

/* Values declared outside of any block */
/*         have entire file scope. They can */
/*         be accessed by any function */
/*         inside a file. */

int x = 13;

void show_x(void) { printf("%i\n", x); }

int main(void) {

  show_x();

  /* Value can be change in every scope */
  x = 99;

  show_x();
}
