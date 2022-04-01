/* `continue` statement is usefull when, the loop */
/*   should proceed to next iteration under some */
/*   conditions and skip rest of the code after the */
/*   statement. */

#include <stdio.h>

int main(void) {
  int numbers_to_check = 10;

  for (int i = 0; i <= numbers_to_check; ++i) {
    if (i % 2)
      continue;

    printf("%i is even\n", i);
  }

  return 0;
}
