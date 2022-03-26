#include <limits.h>
#include <stdio.h>

void show_width(char *type_name, int width) {
  printf("`%s` is %d bits wide\n\n", type_name, width);
}

int main(void) {
  /* Each data type width is multiplication of `unsigned char` width */
  show_width("char", sizeof(char)*CHAR_BIT);
  show_width("short int",sizeof(short int)*CHAR_BIT);
  show_width("int", sizeof(int)*CHAR_BIT);
  show_width("long int", sizeof(long int)*CHAR_BIT);
  show_width("long long int", sizeof(long long int)*CHAR_BIT);

  return 0;
}
