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

bool cmp_priorities(void *a, void *b) {
  task *a_p = (task *)a;
  task *b_p = (task *)b;
  return a_p->priority > b_p->priority;
}

int find_tasks_without_dependencies(l_list **tasks, l_list **result) {
  l_list *tmp_t = *tasks;

  int task_i = 0;
  while (tmp_t) {
    task *tmp = tmp_t->value;

    tmp_t = tmp_t->next;

    if (tmp->deps == 0) {

      // delete node from tasks list
      linked_list_pop(*tasks, task_i);

      // overwrite head if previously
      // popped 0th element
      if (task_i == 0)
        *tasks = tmp_t;

      *result = linked_list_insert(*result, tmp, 0);
      if (*result == NULL) {
        print_error("Not enough memory to allocate zero dependencies list");
        return 0;
      }

      task_i--;
    }

    task_i++;
  }

  return 1;
}

void show_tasks(l_list *tasks, char *list_name) {
  puts(list_name);
  while (tasks) {
    show_task(tasks->value);
    tasks = tasks->next;
  }
}
