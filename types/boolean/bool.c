#include <stdio.h>
/* Boolean dependency */
#include <stdbool.h>

int main(void) {
  /* Boolean types can store only 0 and 1
                or `false` and `true`. */
  bool loop_controol = true;

  short int i = 0;

  while (loop_controol) {
    printf("%i", i);

    i++;

    if (i > 9) {
      loop_controol = false;
    }
  }

  return 0;
}
