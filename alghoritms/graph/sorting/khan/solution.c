#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int priority;
  int task_number;
  int dependency_ammount;
} task;

task *create_new_task(int priority, int task_number) {
  task *t = (task *)malloc(sizeof(task));
  if (t) {
    t->priority = priority;
    t->task_number = task_number;
    t->dependency_ammount = 0;
  } else {
    puts("Not enough memory to allocate task");
  }
  return t;
}

void print_error(const char *message) {
  const char *prefix = "ERROR";
  const char *postfix = "!!!";
  printf("%s: %s %s\n", prefix, message, postfix);
}

void take_int_input(int *n, const char *question) {
  const char *error = "Value has to be a number";
  const char *n_format = "%i";
  while (true) {
    printf("%s: ", question);
    int a = scanf(n_format, n);
    // clear stdin if input is not in specified format
    if (a == 0) {
      char c;
      while ((c = getchar()) != '\n' && c != EOF)
        ;
      print_error(error);
    } else
      break;
  }
}

int take_int_input_warning(int n_max, int n_min, const char *question) {
  const char *error_msg = "Value has to be bigger than %i and smaller than %i";
  char error[strlen(error_msg) + (n_min % 10) + (n_max % 10) + 1];
  sprintf(error, error_msg, n_min, n_max);

  int n;
  while (true) {
    take_int_input(&n, question);
    if (n >= n_min && n <= n_max)
      return n;
    print_error(error);
  }
}

int take_tasks_ammount(void) {
  const int max_value = 10000;
  const int min_value = 1;
  const char *question = "tasks ammount";

  return take_int_input_warning(max_value, min_value, question);
}

int take_task_priority(void) {
  const int max_value = 1000000;
  const int min_value = 1;
  const char *question = "task priority";

  return take_int_input_warning(max_value, min_value, question);
}

bool check_pairwise_distinct(int *i, int t, task *tasks[]) {
  /* If there is a task with priority == t, return false and  */
  /*   decrease i value. */
  for (int j = 0; j < *i; j++) {
    if (t == tasks[j]->priority) {
      print_error("There already is task with that priority");
      (*i)--;
      return false;
    }
  }
  return true;
}

int main(void) {
  int tasks_ammount = take_tasks_ammount();
  task *tasks[tasks_ammount];
  for (int i = 0; i < tasks_ammount; i++) {
    int t = take_task_priority();

    if (check_pairwise_distinct(&i, t, tasks)) {
      task *new_task = create_new_task(t, i + 1);
      if (!new_task)
        exit(EXIT_FAILURE);

      tasks[i] = new_task;
    }
  }
}
