#include <stdio.h>
/* `fmod` dependency */
#include <math.h> // has to be compiled with `-lm` flag
#include <stdbool.h>
#include <stdlib.h>

bool is_odd_int(int number) {
  /* `%` operator return reminder from dividing `x` by `y`. */
  return number % 2 != 0;
}

bool is_odd_float(float number) {
  /* As `%` takes int as argument, to perform it on float `fmod` */
  /*   has to be used. */
  return fmod(number, 2) != 0;
}

void show_odd_int(int number) {
  if (is_odd_int(number))
    printf("%i is odd\n", number);
  else
    printf("%i is even\n", number);
}

int main(void) {
  int a = 5;
  int b = 8;

  show_odd_int(a);
  show_odd_int(b);
  return 0;
}
