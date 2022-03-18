#include <stdio.h>

void show_i_x(int i, int x, char *operator) {
  printf("x=%s=%i i=%i\n", operator, x, i);
}

int main(void) {
  int i = 0, x;
  printf("i=%i\n", i);

  x = i++;
  show_i_x(i, x, "i++");

  x = i--;
  show_i_x(i, x, "i--");

  x = ++i;
  show_i_x(i, x, "++x");

  x = --i;
  show_i_x(i, x, "--i");

  return 0;
}
