#include "dependency.h"

dependency *create_new_dependency(task *task_, task *depend_on) {
  dependency *d = (dependency *)malloc(sizeof(dependency));
  if (d) {
    d->task = task_;
    d->depend_on = depend_on;
  }
  return d;
}

int take_dependencies_ammount(int n) {
  // meet assumption: "d does not exceed n^2"
  const int max_value = n * n;
  // meet assumption: "d contains one non-negative integer"
  const int min_value = 0;
  const char *question = "dependencies ammount";
  const char *n_format = "%i";

  return take_input_warning(max_value, min_value, question, n_format);
}

char *find_number(char *line, int *results) {
  // extract number from string
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
  // meet assumption: "validate that number is in the range between 1 and n"
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
    for (int i = 1; i >= 0; --i) {
      line_cp = find_number(line_cp, &results[i]);
    }
    check_numbers(results, n_min, n_max);
  }
  free(line);
}

dependency *take_dependency(int n, l_list *tasks) {
  const int max_value = n;
  const int min_value = 1;
  const char *question = "dependency";
  const char *n_format = "%[^\n]%*c";

  int numbers[2] = {0, 0};

  take_dependency_input(numbers, min_value, max_value, question, n_format);

  task *task_ = linked_list_get_value(tasks, n - numbers[0]);
  task *depend_on = linked_list_get_value(tasks, n - numbers[1]);

  return create_new_dependency(task_, depend_on);
}

void show_dependency(dependency *dependency) {
  printf("Task %i | ", dependency->task->task_number);
  printf("Depends on %i |", dependency->depend_on->task_number);
}

bool is_depend_on_eq(void *d, void *t) {
  // Does dependency `d` depend on task `t`
  dependency *d_p = (dependency *)d;
  task *t_p = (task *)t;

  return d_p->task->task_number == t_p->task_number;
}

int count_dependencies(l_list *deps, task *t) {
  int i = 0;
  while (deps) {
    deps = linked_list_find(deps, t, is_depend_on_eq);
    if (deps) {
      i++;
      deps = deps->next;
    } else
      break;
  }

  return i;
}
