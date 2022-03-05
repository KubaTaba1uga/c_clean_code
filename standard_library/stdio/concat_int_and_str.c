#include <stdio.h>

int main(void) {
  char buffer[100] = "";

  int a = 1;

  int b = 2;

  sprintf(buffer, "%d %d", a, b);

  printf("%s\n", buffer);

  return 0;
}
