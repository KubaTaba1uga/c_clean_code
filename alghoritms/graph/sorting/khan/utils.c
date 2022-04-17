#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void stdin_buffer_cleanup(void) {
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void print_error(const char *message) {
  const char *prefix = "ERROR";
  const char *postfix = "!!!";
  printf("%s: %s %s\n", prefix, message, postfix);
}

void take_input(void *n, const char *n_format, const char *question) {
  const char *error = "Value has to be a number";
  int a;
  while (true) {
    printf("%s: ", question);
    a = scanf(n_format, n);
    // clear stdin buffer if wrong input
    if (a == 0) {
      stdin_buffer_cleanup();
      print_error(error);
    } else
      break;
  }
}

int take_input_warning(int n_max, int n_min, const char *question,
                       const char *n_format) {
  const char *error_msg = "Value has to be bigger than %i and smaller than %i";
  char error[strlen(error_msg) + (n_min % 10) + (n_max % 10) + 1];
  sprintf(error, error_msg, n_min, n_max);

  int n;
  while (true) {
    take_input(&n, n_format, question);
    if (n >= n_min && n <= n_max)
      return n;
    print_error(error);
  }
}
