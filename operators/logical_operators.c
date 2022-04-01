#include <stdbool.h>
#include <stdio.h>

void print_bool(int value, char *equation) {
  printf("%s == %s\n", equation, value == true ? "true" : "false");
}

int main(void) {
  /* In C 0 or NULL are false and more than 1 is true.  */
  /*  Boolean type is only syntax sugar. */

  /* `x && y` is true only if x and y are true. */
  print_bool(1 && 1, "1 && 1");
  print_bool(1 && 0, "1 && 0");
  print_bool(0 && 1, "0 && 1");
  print_bool(0 && 0, "0 && 0");

  /* `x || y` is true when x or y is true. */
  print_bool(1 || 1, "1 || 1");
  print_bool(1 || 0, "1 || 0");
  print_bool(0 || 1, "0 || 1");
  print_bool(0 || 0, "0 || 0");

  puts("");

  /* `x && y` is true only if x and y are true. */
  print_bool(true && true, "true && true");
  print_bool(true && false, "true && false");
  print_bool(false && true, "false && true");
  print_bool(false && false, "false && false");

  /* `x || y` is true when x or y is true. */
  print_bool(true || true, "true || true");
  print_bool(true || false, "true || false");
  print_bool(false || true, "false || true");
  print_bool(false || false, "false || false");

  return 0;
}
