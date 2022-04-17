#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#include "utils.h"

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

void realese_tasks(int n, task *tasks[n]) {
  while (n-- > 0)
    if (tasks[n])
      free(tasks[n]);
}

int take_tasks_ammount(void) {
  const int max_value = 10000;
  const int min_value = 1;
  const char *question = "tasks ammount";
  const char *n_format = "%i";

  return take_input_warning(max_value, min_value, question, n_format);
}

int take_task_priority(void) {
  const int max_value = 1000000;
  const int min_value = 1;
  const char *question = "task priority";
  const char *n_format = "%i";

  return take_input_warning(max_value, min_value, question, n_format);
}

bool check_pairwise_distinct(int i, int t, task *tasks[]) {
  /* If there is a task with priority == t, return false.*/
  while (i-- > 0) {
    if (t == tasks[i]->priority) {
      print_error("There already is task with that priority");
      return false;
    }
  }
  return true;
}
