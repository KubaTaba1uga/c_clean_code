#include <stdio.h>

void show_char(char *a) {
  printf("     numerical value of a=%i\n", *a);

  printf("representation value of a=%c\n", *a);
}

/* Each compiler implementation define char to have the same */
/*     alignment, size, range, representation and behaviour as */
/*     either signed char or unsigned char. However char is
         separated type, which is incompatibile with previous two.*/

int main(void) {
  /* char is mostly intended to be used to represent characters. */
  /*     But characters in C are represented by their integer "codes", */
  /*     so there's nothing unusual in the fact that an integer type */
  /*     char is used to serve that purpose. */

  char a = 'a';

  show_char(&a);
}
