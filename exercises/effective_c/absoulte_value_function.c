#include <limits.h>
#include <stdio.h>

int absolute_value(int a) {
  if (a < 0) {
    // Avoid overflow
    if (a == INT_MIN)
      return INT_MAX;
    else
      return -a;
  }
  return a;
}

void show_absolute(int a) { printf("|%i|=%i\n", a, absolute_value(a)); }

int main(void) {
  show_absolute(INT_MIN);

  show_absolute(INT_MAX);

  show_absolute(0);

  show_absolute(-999);

  return 0;
}
