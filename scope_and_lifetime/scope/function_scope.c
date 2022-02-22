#include <stdio.h>

void x_plus_one(void) {
  /* `x` is visible only inside that function. */
  int x = 0;

  x++;

  printf("In x_plus_one x=%i\n", x);
}

void x_plus_two() {
  /* A label (and only a label) declared inside */
  /*     a function is in scope everywhere in that */
  /*     function, in all nested blocks, before and */
  /*     after its own declaration.  */

  int x = 0;

  if (x < 2) {
    goto INCREMENT;

  } else {
    goto DECREMENT;
  }

  if (1 == 0) {
  /* Label is visible in all function scope not only */
  /*     after its declaration. */
  DECREMENT:
    while (x != 2) {
      x--;
    }
    /* If it would be different error would occur
      because this code will never be executed. */
  INCREMENT:
    while (x != 2) {
      x++;
    }
  }

  printf("In x_plus_two x=%i\n", x);
}

int main(void) {
  puts("x=0");

  x_plus_one();

  x_plus_two();

  return 0;
}
