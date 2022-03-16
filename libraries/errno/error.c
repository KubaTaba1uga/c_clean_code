/* `errno` variable is set by system calls and */
/* 	 some library functions in the event of */
/* 	an error to indicate that anything went wrong. */

/* `errno` dependency */
#include <errno.h>
#include <limits.h>
#include <stdio.h>
/* `strerror` dependency */
#include <string.h>

int main(void) {
  FILE *ptr = fopen("non_existing_file", "r");

  /* At program startup `errno` is set up to 0 */
  if (errno != 0)
    /* Get message based on code value */
    puts(strerror(errno));

  return 0;
}
