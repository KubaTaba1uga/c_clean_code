/* const dependencies */
#include <limits.h>
/* `pow` dependency */
#include <math.h>
#include <stdio.h>

void show_min(char *type_name, long long int max) {
  printf("`%s` minimum is %lld\n\n", type_name, max);
}

int main(void) {
  short int a = -32767;
  show_min("short int", SHRT_MIN);

  unsigned short int c = 0;
  show_min("unsigned short int", 0);

  int d = -2147483647;
  show_min("int", INT_MIN);

  unsigned int f = 0;
  show_min("unsigned int", 0);

  long int g = -9223372036854775807;
  show_min("long int", LONG_MIN);

  unsigned long int i = 0;
  show_min("unsigned long int", 0);

  long long int j = -9223372036854775807;
  show_min("long long int", LLONG_MIN);

  unsigned long long int l = 0;
  show_min("unsigned long long int", 0);

  return 0;
}
