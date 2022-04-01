#include <stdio.h>

int main(void) {
  /* In C only two values can be  */
  /*   compared at the moment. */

  /* So below example: */
  if (5 < 7 < 2)
    puts("2 is biggest");

  /* Is the same as: */
  if ((5 < 7) < 2)
    puts("2 is biggest");

  /* To make comparasion correctly
     it has to be divided in parts: */
  if ((5 < 7) && (7 < 2))
    puts("2 is biggest");
  else
    puts("7 is biggest");

  return 0;
}
