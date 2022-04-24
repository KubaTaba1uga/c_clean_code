#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dependency.h"
#include "linked_list.h"
#include "task.h"
#include "utils.h"

int main(void) {
  l_list *tmp_t, *tmp_d, *tasks = NULL, *deps = NULL, *zero_deps_tasks = NULL;
  int n, d, v_nodes, exit_status = EXIT_FAILURE;

  // take `n`
  n = take_tasks_ammount();
  task *sorted[n];

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
  d = take_dependencies_ammount(n);

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

  // khan alghoritm
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
  v_nodes = 0;

  /* Step-2 */
  // Pick all nodes without incoming edges
  //	and add it to a list.
  if (!find_tasks_without_dependencies(&tasks, &zero_deps_tasks)) {
    exit_status = EXIT_FAILURE;
    goto REALESE_ZERO_DEPENDENCIES;
  }

  while (zero_deps_tasks) {
    /* This is not part of khan's algorithm */
    /* however it is necessery to acomplish */
    /* exercise */
    // Move task with smallest priority to
    //  beginning of the tasks without
    //  dependencies list
    linked_list_sort(zero_deps_tasks, cmp_priorities);

    /* Step-3 */
    // Remove 0'th node from list of nodes
    // without dependencies and add it to
    // sorted sequence

    // Add node without dependencies and
    // least preority to sorted sequence
    sorted[v_nodes] = zero_deps_tasks->value;

    // Increment count of visited nodes
    v_nodes++;

    // Decrease dependencies counter
    // for all tasks that depends on
    // deleted task
    tmp_d = deps;
    while (tmp_d) {
      dependency *tmp = tmp_d->value;
      if (tmp->depend_on == zero_deps_tasks->value)
        tmp->task->deps--;
      tmp_d = tmp_d->next;
    }

    // Remove node with least priority
    tmp_t = zero_deps_tasks->next;
    linked_list_pop(zero_deps_tasks, 0);
    zero_deps_tasks = tmp_t;

    if (!find_tasks_without_dependencies(&tasks, &zero_deps_tasks)) {
      exit_status = EXIT_FAILURE;
      goto REALESE_ZERO_DEPENDENCIES;
    }
  }

  if (v_nodes != n) {
    print_error("Topological sort is not possible for the given graph");
    exit_status = EXIT_FAILURE;
    goto REALESE_ZERO_DEPENDENCIES;
  } else {
    printf("\nSorted:\n    ");
    for (int i = 0; i < n; ++i) {
      printf("%i ", sorted[i]->task_number);
      free(sorted[i]);
    }
    puts("");
    exit_status = EXIT_SUCCESS;
  }

REALESE_ZERO_DEPENDENCIES:
  linked_list_clear(zero_deps_tasks);
REALESE_DEPENDENCIES:
  linked_list_clear(deps);
REALESE_TASKS:
  linked_list_clear(tasks);
  exit(exit_status);
}
