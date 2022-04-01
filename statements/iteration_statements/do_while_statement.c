/* `do while` statement start to evaluate condition */
/* 	after first iteration. */

#include <stdio.h>

int main(void) {
  int n = 0;

  /* Condition is tested after each loop execution. */
  do
    printf("%i\n", n);
  while (n > 0);

  return 0;
}
