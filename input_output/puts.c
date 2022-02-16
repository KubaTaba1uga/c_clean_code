// `puts` dependency
#include <stdio.h>
// `EXIT_SUCCESS` dependency
#include <stdlib.h>

int main(void) {
  /* `puts` write argument to stdout */
  /*     appending newline at its end */
  int exit_code = puts("Hello World!");

  /* If write to stdout failed return EOF */
  /*     which is always negative number. */
  /* If write to stdout succeed return */
  /*     positive number. */
  printf("Exit code: %i\n", exit_code);

  /* The same as `#define EXIT_SUCCESS 0` */
  return EXIT_SUCCESS;
}
