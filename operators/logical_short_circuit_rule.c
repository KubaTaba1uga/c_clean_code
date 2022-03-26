#include <stdbool.h>
#include <stdio.h>

void print_bool(int value, char *equation) {
  printf("%s == %s\n\n", equation, (bool)value == true ? "true" : "false");
}

int a(void) {
  puts("`a()` returned 1");
  return 1;
}

int b(void) {
  puts("`b()` returned 0");
  return 0;
}

int main(void) {
  /* In C short circuit rule is applied to */
  /*   boolean evaluations. Only those*/
  /*   expressions will be evaluated  */
  /*   which are needed to predict a  */
  /*   result. */

  /* For `a() && b()` b will evaluate only */
  /*   if a() return true. */
  print_bool(a() && b(), "a() && b()");
  print_bool(b() && a(), "b() && a()");

  puts("");

  /* For `a() || b()` b will evaluate only */
  /*   if a() return false. */
  print_bool(a() || b(), "a() || b()");
  print_bool(b() || a(), "a() || b()");

  return 0;
}
