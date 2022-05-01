/* To use `strdup` on Linux/GNU compilation has to be done  */
/* using `-D _GNU_SOURCE`. */
/* Example: */
/* gcc -o get_string_dynamically.out -D _GNU_SOURCE get_string_dynamically.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *username = getenv("USERNAME");
  if (!username) {
    puts("There is no USERNAME in environment variables");
    goto PROGRAM_FAILURE;
  }

  char *modify_username = strdup(username);
  if (!modify_username) {
    puts("Allocating memory by `strdup` has failed");
    goto PROGRAM_FAILURE;
  }

  int char_to_modify = strlen(modify_username) / 2;

  modify_username[char_to_modify] = 'X';

  printf("Username before: %s\n", username);
  printf("Username after: %s\n", modify_username);

  free(modify_username);

  exit(EXIT_SUCCESS);

PROGRAM_FAILURE:
  exit(EXIT_FAILURE);
}
