#include <limits.h>
#include <stdio.h>
/* Wraparound occurs when maximum or */
/* 	minimum value is exceeded by object. */
/* 	Result is object value, modulo maximum */
/* 	or minimum value. */

void to_big(unsigned int a, unsigned int b, char sign) {
  printf("%u%c%u=Value to big!!!\n", a, sign, b);
}

void to_small(unsigned int a, unsigned int b, char sign) {
  printf("%u%c%u=Value to small!!!\n", a, sign, b);
}

int main(void) {
  unsigned int a, b, c, d;

  a = c = 100;

  b = d = UINT_MAX - 50;

  /* Check wrapparound exsistance */
  /*	in `unsigned int`. */

  /* Addition */
  if (a > UINT_MAX - b)
    to_big(a, b, '+');
  else
    a = a + b;

  /* Substraction */
  if (c < d)
    to_small(c, d, '-');
  else
    c = c - d;

  /* Wrap around is not well-defined for signed types, */
  /* 	 because there are multiple methods for */
  /* 	 representing signed values, and the result of */
  /* 	 an overflow will be interpreted differently  */
  /* 	 based on that method. */
  signed int e = INT_MIN;

  e = e * -1; // overflow

  printf("%d\n", e);

  return 0;
}
