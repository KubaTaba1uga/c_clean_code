#include <stdio.h>
/* `strncat` dependency */
#include <string.h>

int main(void) {
  char a = 'a';
  char b = 'b';
  char string[sizeof(a)+sizeof(b)];

  sprintf(string, "%c %c", a, b);

  printf("%s\n", string);

  return 0;
}
