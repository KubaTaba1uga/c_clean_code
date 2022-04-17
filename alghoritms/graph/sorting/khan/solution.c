#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dependency.h"
#include "task.h"
#include "utils.h"

int main(void) {
  // take `n`
  int tasks_ammount = take_tasks_ammount();
  task *tasks[tasks_ammount];
  for (int i = 0; i < tasks_ammount; ++i) {
    tasks[i] = NULL;
  }

  // take `n` size array
  for (int i = 0; i < tasks_ammount; i++) {
    int t = take_task_priority();
    if (check_pairwise_distinct(i, t, tasks)) {
      task *new_task = create_new_task(t, i + 1);
      if (!new_task) {
        realese_tasks(tasks_ammount, tasks);
        exit(EXIT_FAILURE);
      }
      tasks[i] = new_task;
    } else {
      i--;
    }
  }

  // take `d`
  int dependencies_ammount = take_dependencies_ammount(tasks_ammount);
  dependency *dependencies[dependencies_ammount];
  for (int i = 0; i < dependencies_ammount; ++i) {
    dependencies[i] = NULL;
  }

  stdin_buffer_cleanup();

  // take `d` size array
  for (int i = 0; i < dependencies_ammount; ++i) {
    take_dependency(tasks_ammount, tasks);
  }
}
