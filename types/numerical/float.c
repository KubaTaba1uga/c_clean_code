#include <stdio.h>

int main(void) {
  /* By default all floats are `double` type. */
  /*     To require `float` add `f` to number. */

  /* 32 bits long */
  /*     1-bit for the sign, */
  /*     8-bits for exponent, */
  /*     23-bits for significand = 6 decimal digits of precision. */
  float a = 3.1111115555f;
  /* Anything after 6th decimal digit will be displayed incorrectly */
  printf("a=%.10f\n", a);

  /* 64 bits long */
  /*     1-bit for the sign, */
  /*     11-bits for exponent, */
  /*     52*-bits for the significand = 11 decimal digits of precision. */
  double b = 3.1111115555555555;
  /* Anything after 11th decimal digit will be displayed incorrectly */
  printf("b=%.20f\n", b);

  printf("0.1=%.20f\n", 0.1);
  printf("0.2=%.20f\n", 0.2);
  printf("0.1+0.2=%.20f\n", 0.1 + 0.2);

  /* Explanation:  */
  /*	How to represent 0.5 in binary? */
  /*		0x2^0 . 1x2^-1 = 0.1 */
  /*	How to represent 0.1 in binary? */
  /*		0x2^0 . 0x2^-1 + 0x2^-2 + 0x2^-3 + 1x2^-4 + 1x2^-5 + 0x2^-6 +
   * 0x2^-7
   * + 1x2^-8 + 1x2^-9 */
  /*		0.000110011 = 0,099609375 */
  /* Because of data width and exponent description by (0 || 1)x2^-N, */
  /*   float numbers are prone to missrepresentations. */

  return 0;
}
