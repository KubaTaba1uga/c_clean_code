#include <stdio.h>

void show_char(unsigned char *a) {
  printf("     numerical value of a=%u\n", *a);

  printf("representation value of a=%c\n", *a);
}

int main(void) {
  unsigned char a = (unsigned char)255;

  show_char(&a);

  /* Because unsigned char is 8 bit long (max 255) */
  /*     incremented `a` will shift left a bit. Changing */
  /*     its value to 0. */

  a++;

  show_char(&a);

  return 0;
}
