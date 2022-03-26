#include <stdio.h>

void show_char(signed char *a) {
  printf("     numerical value of a=%i\n", *a);

  printf("representation value of a=%c\n", *a);
}

int main(void) {
  signed char a = (signed char)127;

  show_char(&a);

  /* Because signed char is 7 bit long (max 127) */
  /*     incremented `a` will shift left a bit (changing */
  /*     MSB). Changing its value to -128. */

  a++;

  show_char(&a);

  return 0;
}
