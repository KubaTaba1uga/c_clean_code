/* const dependencies */
#include <limits.h>
/* `pow` dependency */
#include <math.h>
#include <stdio.h>

void show_max(char *type_name, unsigned long long int max) {
  printf("`%s` maximum is %llu\n\n", type_name, max);
}

int main(void) {
  short int a = 32767;
  show_max("short int", SHRT_MAX);

  unsigned short int c = 65535;
  show_max("unsigned short int", USHRT_MAX);

  int d = 2147483647;
  show_max("int", INT_MAX);

  unsigned int f = 4294967295;
  show_max("unsigned int", UINT_MAX);

  long int g = 9.223372036854776 * pow(10, 18);
  show_max("long int", LONG_MAX);

  unsigned long int i = 1.844674407370956 * pow(10, 19);
  show_max("unsigned long int", ULONG_MAX);

  long long int j = 0;
  show_max("long long int", LLONG_MAX);

  unsigned long long int l = 0;
  show_max("unsigned long long int", ULLONG_MAX);

  return 0;
}
