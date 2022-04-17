#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dependency.h"
#include "task.h"
#include "utils.h"

dependency *create_new_dependency(task *task_, task *depend_on) {
  dependency *d = (dependency *)malloc(sizeof(dependency));
  if (d) {
    d->task = task_;
    d->depend_on = depend_on;
  } else
    print_error("Not enough memory to allocate dependency");
  return d;
}

int take_dependencies_ammount(int n) {
  const int max_value = n * n;
  const int min_value = 0;
  const char *question = "dependencies ammount";
  const char *n_format = "%i";

  return take_input_warning(max_value, min_value, question, n_format);
}

void take_dependency_input(int result[2], int n, int n_max, int n_min,
                           const char *question, const char *n_format) {
  const char *error_type_msg =
      "Value has to contain to integers separated with one space";

  const char *error_range_msg =
      "Both values has to be bigger than %i and smaller than %i";
  char error_range[strlen(error_range_msg) + (n_min % 10) + (n_max % 10) + 1];
  sprintf(error_range, error_range_msg, n_min, n_max);

  int numbers_len = ((n % 10) + 1) * 2 + 1;
  char numbers[numbers_len];
  numbers[numbers_len - 1] = '\0';

  int a, b;
  while (true) {
    take_input(&numbers, n_format, question);
    a = atoi(numbers);
    b = atoi(numbers);
    printf("%i\n", a);
    printf("%i\n", b);
    if (!a || !b)
      puts(error_type_msg);
    else if (a < n_min || a > n_max || b < n_min || b > n_max)
      puts(error_range_msg);
    else {
      result[0] = a;
      result[1] = b;
      break;
    }
  }
}

int take_dependency(int n, task *tasks[n]) {
  const int max_value = n;
  const int min_value = 1;
  const char *question = "dependency";
  const char *n_format = "%[^\n]%*c";

  int numbers[2];

  take_dependency_input(numbers, n, max_value, min_value, question, n_format);

  return 0;
}
