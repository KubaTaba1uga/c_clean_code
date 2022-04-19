#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "task.h"
#include "utils.h"

typedef struct {
  task *task;
  task *depend_on;
} dependency;

int take_dependencies_ammount(int n);

dependency *take_dependency(int n, l_list *tasks);

void realese_dependencies(int d, dependency *dependencies[d]);

void show_dependency(dependency *dependency);

bool is_depend_on_eq(void *d, void *t);

int count_dependencies(l_list *deps, task *t);

#endif
