#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

void print_hello(void) { puts("Hello world!"); };

l_list *linked_list_create(void *value) {
  /* Create new empty linked list. */
  /* If not enough memory to allocate it */
  /*   return `NULL`. */
  l_list *l = (l_list *)malloc(sizeof(l_list));

  if (l) {
    l->value = value;
    l->next = NULL;
  }

  return l;
}

l_list *linked_list_append(l_list *l, void *value) {
  /* Append value as last element of linked list. */
  /* If appending succeed return pointer to last */
  /*	node. */
  /* If not enough memory to allocate new node */
  /*	 return `NULL`. */

  while (l->next) {
    // skip all nodes until last one
    l = l->next;
  }
  // create new node
  l->next = linked_list_create(value);

  // return pointer to new node
  return l->next;
};

void linked_list_clear(l_list *l) {
  /* Delete all nodes and values of linked list. */
  l_list *next;

  do {
    // free value if exists
    if (l->value)
      free(l->value);

    next = l->next;
    // free node
    free(l);

    l = next;
  } while (next);
}
