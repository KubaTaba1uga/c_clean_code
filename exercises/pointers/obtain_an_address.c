/* Declare two variables and print their addresses */
/* 	without using `&` in `printf` function. */
#include <stdio.h>

int main(void) {
  char x = 10;
  char y = 15;

  char *x_p = &x;
  char *y_p = &y;

  printf("`x_p` = %p\n", x_p);
  printf("`y_p` = %p\n", y_p);

  return 0;
}
