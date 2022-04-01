/* `enum` allows to define type that */
/*         assign names to integer values. */
#include <stdio.h>

int main(void) {
  /* By default counting is started from 0 */
  enum State { Failed, Working };

  printf(" Failed: %i\n", Failed);
  printf("Working: %i\n", Working);

  /* If value to first element is assigned, it */
  /*     become counter starting point. */
  enum week {
    monday = 1,
    tuesday,
    wednsday,
    thursday,
    friday,
    saturday,
    sunday
  };

  printf(" Friday: %i\n", friday);

  /* Or values can be completly overwriten */
  enum cardinal_points { north = 0, east = 90, south = 180, west = 270 };

  printf("  South: %i\n", south);
}
