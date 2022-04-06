#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  char name[32];
  int age;
} human;

typedef struct list {
  void *value;
  struct list *next;
} list;

human *create_human(char *name, int age) {
  /* Create new instance of `human` object. */
  /* If not enough memory to allocate it */
  /*   return `NULL`. */
  human *p = (human *)malloc(sizeof(human));
  if (p) {
    strcpy(p->name, name);
    p->age = age;
  }
  return p;
}

void show_human(human *human) {
  printf("Name: %s\n", human->name);
  printf("Age: %i\n", human->age);
}

void is_NULL(void *p, char *name) {
  if (!p) {
    printf("Couldn't allocate memory for `%s` object\n", name);
    exit(EXIT_FAILURE);
  }
}

list *create_list(void) {
  /* Create new instance of `list` object. */
  /* If not enough memory to allocate it */
  /*   return `NULL`. */
  list *l = (list *)malloc(sizeof(list));
  if (l) {
    l->value = NULL;
    l->next = NULL;
  }
  return l;
}

list *append_to_list(list *l, void *value) {
  list *l_cp = l;
  while (l_cp->next) {
    // while there is next element skip it
    l_cp = l_cp->next;
  }
  // append new value in place of `NULL`
  l_cp->value = value;
  // allocate next element
  l_cp->next = create_list();
  // return null if allocation fail
  if (l_cp->next == NULL)
    return NULL;

  // return pointer to last element
  return l_cp;
};

void free_list(list *l) {
  // free all elements in list
  list *next, *current = l;

  do {
    if (current->value)
      free(current->value);
    next = current->next;
    free(current);
    current = next;
  } while (next);
}

int main(void) {
  human *jakub = create_human("Jakub", 24);
  is_NULL(jakub, "jakub");
  human *karol = create_human("Karol", 24);
  is_NULL(jakub, "karol");
  human *tomek = create_human("Tomek", 12);
  is_NULL(jakub, "tomek");

  list *l_h, *l = create_list(), *l_cp = l;

  l_h = append_to_list(l, jakub);
  is_NULL(l_h, "append_to_list(l, jakub)");
  l_h = append_to_list(l, tomek);
  is_NULL(l_h, "append_to_list(l, tomek)");
  l_h = append_to_list(l, karol);
  is_NULL(l_h, "append_to_list(l, karol)");

  while (l_cp->next) {
    show_human(l_cp->value);
    l_cp = l_cp->next;
  }

  free_list(l);

  exit(EXIT_SUCCESS);
}
