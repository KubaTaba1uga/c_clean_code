#include <stdio.h>

int main(void) {

  int x = 13;

  {
    /* `x` copy has scope restricted to this block */
    /*         so it won't be visiable after it's over */
    int x = 15;
    printf("Inner block: %i\n", x);

    /* `y` can't be accessed outisde of this block' */
    int y = 99;
  }

  printf(" Main block: %i\n", x);

  return 0;
}
