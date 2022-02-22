#include <stdio.h>

int main(void) {
  /* By default all floats are `double` type. */
  /*     To require `float` add `f` to number. */

  /* 32 bits long */
  /*     1-bit for the sign, */
  /*     8-bit for exponent, */
  /*     23*-bit for the value. */
  /*     It has 6 decimal digits of precision. */
  float a = 3.1111115555f;
  /* Anything after 6th decimal digit will be displayed incorrectly */
  printf("%.10f\n", a);

  /* 64 bits long */
  /*     1-bit for the sign, */
  /*     11-bit for exponent, */
  /*     52*-bit for the value. */
  double b = 3.1111115555555555;
  /* Anything after 11th decimal digit will be displayed incorrectly */
  printf("%.20f\n", b);
}
