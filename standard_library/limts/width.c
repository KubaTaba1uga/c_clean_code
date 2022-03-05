#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

/* Width principles: */
/* 	1. Each data type width is multiple of `unsigned char` width */
/* 	2. Smaller type cannot be wider than bigger one */

int get_witdh(unsigned long long int max) { return log2l(max); }

void show_width(char *type_name, int width) {
  printf("`%s` is %d bits wide\n\n", type_name, width);
}

int main(void) {
  show_width("char", get_witdh(UCHAR_MAX) + 1);
  show_width("short int", get_witdh(USHRT_MAX) + 1);
  show_width("int", get_witdh(UINT_MAX) + 1);
  show_width("long int", get_witdh(ULONG_MAX));
  show_width("long long int", get_witdh(ULLONG_MAX));

  return 0;
}
