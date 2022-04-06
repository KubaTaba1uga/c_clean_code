#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Linked list
typedef struct _l_list {
  void *value;
  struct _l_list *next;
} l_list;

void print_hello(void);

l_list *linked_list_create(void *value);

l_list *linked_list_append(l_list *l, void *value);

void linked_list_clear(l_list *l);

#endif
