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

char *find_number(char *line, int line_len, int *results) {

  *results = atoi(line);
  while (*line++ != ' ')
    if (*line == '\0')
      break;

  return line;
}

void check_numbers(int a[2], int n_min, int n_max) {
  const char *format_error = "Wrong input format";
  const char *range_error_msg =
      "Both values has to be bigger than %i and smaller than %i";

  char range_error[strlen(range_error_msg) + (n_min % 10) + (n_max % 10)];
  sprintf(range_error, range_error_msg, n_min, n_max);

  if (!a[0] || !a[1]) {
    print_error(format_error);
    return;
  }
  // if numbers don't met aqusition reset their's values
  if (a[0] < n_min || a[0] > n_max || a[1] < n_min || a[1] > n_max) {
    print_error(range_error);
    a[0] = 0;
    a[1] = 0;
  }
}

void take_dependency_input(int results[2], int n_min, int n_max,
                           const char *question, const char *n_format) {

  int line_len = 32;
  char *line = (char *)malloc(sizeof(char) * line_len), *line_cp;

  while (!results[0] || !results[1]) {
    take_input(line, n_format, question);
    line_cp = line;
    for (int i = 0; i < 2; ++i) {
      line_cp = find_number(line_cp, line_len, &results[i]);
    }
    check_numbers(results, n_min, n_max);
  }
  free(line);
}

dependency *take_dependency(int n, task *tasks[n]) {
  const int max_value = n;
  const int min_value = 1;
  const char *question = "dependency";
  const char *n_format = "%[^\n]%*c";

  int numbers[2] = {0, 0};

  take_dependency_input(numbers, min_value, max_value, question, n_format);

  task *task_ = tasks[numbers[1] - 1];
  task *depend_on = tasks[numbers[0] - 1];
  task_->dependency_ammount++;

  return create_new_dependency(task_, depend_on);
}

void realese_dependencies(int d, dependency *dependencies[d]) {
  while (d-- > 0)
    if (dependencies[d])
      free(dependencies[d]);
}

void show_dependency(dependency *dependency) {
  printf("Task %i ", dependency->task->task_number);
  printf("Depends on %i\n", dependency->depend_on->task_number);
}
