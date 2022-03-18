/* `errno` dependency */
#include <errno.h>
#include <stdio.h>
/* `strerror` dependency */
#include <string.h>

int main(void) {
  int a = 127;

  long int b = (long int)a;

  return 0;
}
