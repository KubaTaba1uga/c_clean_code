#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dependency.h"
#include "task.h"
#include "utils.h"

int main(void) {
  int exit_status = EXIT_FAILURE;

  // take `n`
  int n = take_tasks_ammount();
  task *result[n], **tmp;
  task **tasks = (task **)malloc(sizeof(task *) * n);
  for (int i = 0; i < n; ++i) {
    tasks[i] = result[i] = NULL;
  }

  // take `n` size array
  for (int i = 0; i < n;) {
    int t = take_task_priority();
    if (check_pairwise_distinct(i, t, tasks)) {
      task *tmp = create_new_task(t, i + 1);
      if (!tmp)
        exit(exit_status);
      // goto REALESE_TASKS;
      tasks[i] = tmp;
      i++;
    }
  }

  show_tasks(n, tasks);

  tasks = remove_task_from_array(&n, tasks, 2);

  show_tasks(n, tasks);
  /* // take `d` */
  /* int d = take_dependencies_ammount(n); */
  /* dependency **dependencies = (dependency **)malloc(sizeof(dependency *) *
   * d); */
  /* if (!dependencies) { */
  /*   goto REALESE_DEPENDENCIES_ARRAY; */
  /* } */

  /* stdin_buffer_cleanup(); */

  /* // take `d` size array */
  /* for (int i = 0; i < d; ++i) { */
  /*   dependency *tmp = take_dependency(n, tasks); */
  /*   if (!d) { */
  /*     goto REALESE_DEPENDENCIES; */
  /*   } */
  /*   dependencies[i] = tmp; */
  /* } */

  /* /\* for (int i = 0; i < d; ++i) { *\/ */
  /* /\*   show_dependency(dependencies[i]); *\/ */
  /* /\* } *\/ */

  /* /\* show_tasks(n, tasks); *\/ */

  /* // khan alghoritm */
  /* for (int i = 0; i < n; ++i) { */
  /*   // TODO: remove t from tasks */
  /*   task *t = find_smallest_task_with_zero_dependencies(n, tasks); */
  /*   if (!t) { */
  /*     print_error("Cycle dependencies are not allowed"); */
  /*     goto REALESE_DEPENDENCIES; */
  /*   } */

  /*   // TODO: remove all occurences from dependencies */
  /*   t->dependency_ammount--; */
  /*   for (int j = 0; j < d; ++j) { */
  /*     if (dependencies[j]->depend_on->task_number == t->task_number) */
  /*       dependencies[j]->task->dependency_ammount--; */
  /*   } */

  /*   result[i] = t; */
  /* } */

  /* for (int i = 0; i < n; ++i) { */
  /*   printf("%i\n", result[i]->task_number); */
  /* } */

  /*   exit_status = EXIT_SUCCESS; */

  /* REALESE_DEPENDENCIES: */
  /*   realese_dependencies(d, dependencies); */
  /* REALESE_DEPENDENCIES_ARRAY: */
  /*   free(dependencies); */
  /* REALESE_TASKS: */
  /*   realese_tasks(n, tasks); */
  /*   exit(exit_status); */
}
