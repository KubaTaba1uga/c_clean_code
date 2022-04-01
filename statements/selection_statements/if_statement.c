#include <stdio.h>

int main(void) {

  /* Ommiting braceles is allowed only if */
  /*   one expression should be inside them. */
  if (1 < 5)
    puts("1 < 5");

  if ((2 > 5) && (5 < 7))
    puts("2 > 5");
  // It is executed, independly of if result.
  puts("5 < 7");

  int a = 5;

  /* Next expression will evaluate only if */
  /*   current comparasion return false. */
  if (a < 3)
    printf("%i < 3", a);
  else if (a < 4)
    printf("%i < 4", a);
  else if (a < 5)
    printf("%i < 5", a);
  else
    printf("%i >= 5", a);

  return 0;
}
