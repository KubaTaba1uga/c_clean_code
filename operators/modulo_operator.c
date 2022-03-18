#include <stdio.h>
/* `fmod` dependency */
#include <stdbool.h>
#include <stdlib.h>

bool is_odd(int number) {
  /* `%` operator return reminder from dividing `x` by `y`. */
  return number % 2 != 0;
}

void show_odd(int number) {
  if (is_odd(number))
    printf("%i is odd\n", number);
  else
    printf("%i is even\n", number);
}

int main(void) {
  int a = 5;
  int b = 8;

  show_odd(a);
  show_odd(b);
  return 0;
}
