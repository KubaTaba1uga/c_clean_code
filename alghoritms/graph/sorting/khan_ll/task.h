#ifndef TASK_H
#define TASK_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "utils.h"

typedef struct {
  int priority;
  int task_number;
  int deps;
} task;

task *create_new_task(int priority, int task_number);

int take_tasks_ammount(void);

int take_task_priority(void);

void show_task(task *t);

bool is_priority_eq(void *t, void *p);

bool cmp_priorities(void *a, void *b);

int find_tasks_without_dependencies(l_list **tasks, l_list **result);

void show_tasks(l_list *tasks, char *list_name);

#endif
