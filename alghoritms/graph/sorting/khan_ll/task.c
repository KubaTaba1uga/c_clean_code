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

l_list *fill_no_deps_list(l_list **tasks, l_list **no_deps) {
  l_list *tmp_t = *tasks;

  int task_i = 0;
  while (tmp_t) {
    task *tmp = tmp_t->value;

    tmp_t = tmp_t->next;

    if (tmp->deps == 0) {

      show_task(tmp);
      printf("Task i: %i\n", task_i);
      // delete node from list
      puts("inside fill before pop");
      linked_list_pop(*tasks, task_i);
      puts("inside fill after pop");

      // overwrite head if popped 0th element
      if (task_i == 0)
        *tasks = tmp_t;

      *no_deps = linked_list_insert(*no_deps, tmp, 0);
      if (*no_deps == NULL) {
        print_error("Not enough memory to allocate zero dependencies list");
        return NULL;
      }

      task_i--;
    }

    task_i++;
  }
  return *tasks;
}

void show_tasks(l_list *tasks, char *list_name) {
  puts(list_name);
  while (tasks) {
    show_task(tasks->value);
    tasks = tasks->next;
  }
}
