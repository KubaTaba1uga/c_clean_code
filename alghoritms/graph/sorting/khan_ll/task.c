#include "task.h"

task *create_new_task(int priority, int task_number) {
  task *t = (task *)malloc(sizeof(task));
  if (t) {
    t->priority = priority;
    t->task_number = task_number;
    // Initialize incoming edges counter
    t->deps = 0;
  }
  return t;
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

void show_task(task *t) {
  printf("Task number: %i | ", t->task_number);
  printf("Priority: %i | ", t->priority);
  printf("Dependencies: %i \n", t->deps);
}

bool is_priority_eq(void *t, void *p) {
  // Is task `t` priority equal to `p`
  task *t_p = (task *)t;
  int *p_p = (int *)p;

  return t_p->priority == *p_p;
}
