#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dependency.h"
#include "linked_list.h"
#include "task.h"
#include "utils.h"

int main(void) {
  l_list *tmp_t, *tmp_d, *tasks = NULL, *deps = NULL;

  int n, exit_status = EXIT_FAILURE;

  // take `n`
  n = take_tasks_ammount();

  // take `n` size array
  for (int i = 0; i < n;) {
    int p = take_task_priority();
    // check priority uniqueness
    if (!linked_list_find(tasks, &p, is_priority_eq)) {
      task *tmp = create_new_task(p, i + 1);
      tasks = linked_list_insert(tasks, tmp, 0);
      if (!tmp || !tasks) {
        puts("Not enough memory to allocate tasks");
        goto REALESE_TASKS;
      }
      i++;
    } else
      printf("There already is task with priority: %i \n", p);
  }

  // take `d`
  int d = take_dependencies_ammount(n);

  stdin_buffer_cleanup();

  // take `d` size array
  for (int i = 0; i < d; ++i) {
    dependency *tmp = take_dependency(n, tasks);
    deps = linked_list_insert(deps, tmp, 0);
    if (!tmp || !deps) {
      print_error("Not enough memory to allocate dependencies");
      goto REALESE_DEPENDENCIES;
    }
  }

  /* tmp_t = tasks; */
  /* while (tmp_t) { */
  /*   show_task(tmp_t->value); */
  /*   tmp_t = tmp_t->next; */
  /* } */

  /* tmp_d = deps; */
  /* while (tmp_d) { */
  /*   show_dependency(tmp_d->value); */
  /*   tmp_d = tmp_d->next; */
  /* } */

  /* // khan alghoritm */
  /* Step-1 */
  // Compute number of incoming edges for
  //	each node
  tmp_t = tasks;
  while (tmp_t) {
    task *tmp = tmp_t->value;
    tmp->deps = count_dependencies(deps, tmp_t->value);
    tmp_t = tmp_t->next;
  }

  // Initialize the count of visited nodes as 0
  int v_nodes = 0;

  /* Step-2 */
  // Pick all nodes without incoming edges
  //	and add it to a list.
  l_list *no_deps = NULL;

  tmp_t = tasks;
  while (tmp_t) {
    task *tmp = tmp_t->value;
    if (!tmp->deps) {
      no_deps = linked_list_insert(no_deps, tmp, 0);
      if (!no_deps) {
        print_error("Not enough memory to allocate zero dependencies");
        goto REALESE_ZERO_DEPENDENCIES;
      }
    }
    tmp_t = tmp_t->next;
  }

  /* tmp_t = no_deps; */
  /* while (tmp_t) { */
  /*   show_task(tmp_t->value); */
  /*   tmp_t = tmp_t->next; */
  /* } */

  exit_status = EXIT_SUCCESS;

REALESE_ZERO_DEPENDENCIES:
  linked_list_clear(no_deps);
REALESE_DEPENDENCIES:
  linked_list_clear(deps);
REALESE_TASKS:
  linked_list_clear(tasks);
  exit(exit_status);
}
