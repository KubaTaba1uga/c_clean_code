#include "linked_list.h"

l_list *linked_list_create_node(void *value) {
  /* Create new linked list node. */
  /* If not enough memory to allocate it */
  /*   return `NULL`. */
  l_list *n = (l_list *)malloc(sizeof(l_list));

  if (n) {
    n->value = value;
    n->next = NULL;
  }

  return n;
}

l_list *linked_list_get_node(l_list *l, int i) {
  /* Find node with  index `i` and return it.  */
  /* If  `i` is bigger than linked list length, assign */
  /*	`ERANGE` to errno and return `NULL`. */

  // find value with index `i`
  while (i-- > 0) {
    if (!l) {
      errno = ERANGE;
      break;
    }

    l = l->next;
  };

  return l;
}

void *linked_list_get_value(l_list *l, int i) {
  /* Find node with  index `i` and return its value.  */
  /* If  `i` is bigger than linked list length, assign */
  /*	`ERANGE` to errno and return `NULL`. */

  // if list length reached errno will be already set up
  l = linked_list_get_node(l, i);
  if (!l)
    return NULL;

  return l->value;
}

l_list *linked_list_insert(l_list *l, void *value, int i) {
  /* Insert value as node with index `i` and return */
  /*	pointer to this node. */
  /* If  `i` is bigger than linked list length, assign */
  /*	`ERANGE` to errno and return `NULL`. */
  /* If not enough memory to allocate new node,  */
  /*	return `NULL`.*/
  l_list *n_i = linked_list_create_node(value), *tmp = NULL;
  if (!n_i)
    return NULL;

  if (i == 0)
    goto INSERT;

  // get node to which node will be attached
  l = linked_list_get_node(l, i - 1);
  // check node and node->next existance
  if (!l || !l->next) {
    free(n_i);
    return NULL;
  }

  // attach node
  tmp = l->next;
  l->next = n_i;
  l = tmp;

INSERT:
  n_i->next = l;
  return n_i;
}

void *linked_list_pop(l_list *l, int i) {
  /* Find node with  index `i`, return its value and  */
  /*	remove it from list. */
  /* Node memory with index 'i'  will be realesed. */
  /* If  `i` is bigger than linked list length, assign */
  /*	`ERANGE` to errno and return `NULL`. */
  /* Be carefull when popping list first element, because */
  /*	list could be lost if You won't do it carefully enough. */
  l_list *n_i = l;
  void *n_i_value = NULL;

  if (i == 0)
    goto FREE_NODE;

  // get node before the one to remove
  l = linked_list_get_node(l, i - 1);
  // check node and node->next existance
  if (!l || !l->next)
    return NULL;

  // get node which memory should be released
  n_i = l->next;
  // remove node from list
  l->next = l->next->next;

FREE_NODE:
  n_i_value = n_i->value;
  free(n_i);
  return n_i_value;
};

l_list *linked_list_remove(l_list *l, int i) {
  /* Find node with  index `i` and delete it from linked list.  */
  /* Node and node's value memory will be realesed. */
  /* If operation succeed return pointer to new node */
  /*	with index `i`. */
  /* If  `i` is bigger than linked list length, assign */
  /*	`ERANGE` to errno and return `NULL`. */
  /* Be carefull when removing list first element, because */
  /*	list could be lost if You won't do it carefully enough. */
  l_list *n_i = l->next;

  if (i == 0)
    goto REALESE_MEMORY;

  // get node before the one to remove
  n_i = linked_list_get_node(l, i - 1);
  // check node and node->next existance
  if (!n_i || !n_i->next)
    return NULL;

  // get node to remove
  l = n_i->next;
  // remove node from list
  n_i->next = n_i->next->next;
  // get pointer to current node with index `i`
  n_i = n_i->next;

REALESE_MEMORY:
  if (l->value)
    free(l->value);
  free(l);

  return n_i;
};

l_list *linked_list_find(l_list *l, void *value,
                         bool cmp_function(void *, void *)) {
  /* Find node witch contain `value` and return its.  */
  /* Comparision function should take pointers to `void*`, */
  /*  type and make casting explicitly inside a `cmp_function`. */

  while (l) {
    // if node's value match what is looked for return it
    if (cmp_function(l->value, value))
      return l;
    l = l->next;
  }

  // return `NULL` if nothing was found
  return NULL;
}

void linked_list_clear(l_list *l) {
  /* Realese memory for all nodes and values of linked list. */
  while (l)
    l = linked_list_remove(l, 0);
}

void linked_list_swap(l_list *a, l_list *b) {
  /* Swap value of node `a` with value of node `b`. */
  void **tmp = a->value;
  a->value = b->value;
  b->value = tmp;
}

l_list *linked_list_sort(l_list *l, bool cmp_function(void *, void *)) {
  /* Bubble sort implementation */

  l_list *current = NULL;
  l_list *cmp_to = NULL;
  int swap_counter;

  do {
    current = l;
    cmp_to = l->next;
    swap_counter = 0;

    while (cmp_to) {
      if (cmp_function(current->value, cmp_to->value)) {
        linked_list_swap(current, cmp_to);
        swap_counter++;
      }
      cmp_to = cmp_to->next;
      current = current->next;
    }

  } while (swap_counter > 0);

  return l;
}
