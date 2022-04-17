#include "task.h"
#include "utils.h"

#ifndef DEPENDENCY_H
#define DEPENDENCY_H

typedef struct {
  task *task;
  task *depend_on;
} dependency;

int take_dependencies_ammount(int n);

int take_dependency(int n, task *tasks[n]);

#endif
