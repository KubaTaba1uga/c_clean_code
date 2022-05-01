/* memcpy_s implementation used in this example is from: */
/* 	https://github.com/rurban/safeclib */
/* to compile using gcc add: `-l safec` */
#define __STDC_WANT_LIB_EXT1__ 1
#include <safeclib/safe_lib.h>
#include <stdio.h>
#include <string.h>

void stdin_buffer_cleanup(void) {
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int main(void) {
  rsize_t input_size = 2;
  char input[input_size];
  char *input_result = NULL;
  while (!input_result) {
    printf("Type one character: ");

    input_result = gets_s(input, 2);

    if (!input_result) {
      puts("Input too long!!!");
      stdin_buffer_cleanup();
    }
  }

  printf("Your input: %s\n", input);
}
