#include <stdbool.h>

#ifndef TASK_H
#define TASK_H

typedef struct {
  int priority;
  int task_number;
  int dependency_ammount;
} task;

task *create_new_task(int priority, int task_number);

void realese_tasks(int n, task *tasks[n]);

bool check_pairwise_distinct(int i, int t, task *tasks[]);

int take_tasks_ammount(void);

int take_task_priority(void);

#endif
