#include <stdio.h>
/* Require C-11 compiler */
#define print(x) _Generic((x), int * : print_int, char * : print_char)(x);

void print_int(int *value) { printf("%i\n", *value); }

void print_char(char *value) { printf("%c\n", *value); }

int main(void) {
  char a = '@';

  int b = 123;

  print(&a);

  print(&b);

  return 0;
}
