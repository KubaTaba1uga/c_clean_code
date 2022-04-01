#include <stdio.h>
/* `malloc` dependency */
#include <stdlib.h>
#include <string.h>

void check_null_pointer(void *p) {
  if (p == NULL)
    exit(EXIT_FAILURE);
}

typedef struct {
  char name[32];
  char lastname[32];
  int age;
} person;

void show_person(person *p) {
  printf("Name: %s\n", p->name);
  printf("Last Name: %s\n", p->lastname);
  printf("Age: %d\n", p->age);
}

void ask_for_person(person *p) {
  printf("Name:");
  scanf("%s", p->name);
  printf("Last Name:");
  scanf("%s", p->lastname);
  printf("Age:");
  scanf("%d", &p->age);
  puts("");
}

int main(void) {
  //`malloc` alocates storage for an object.
  //	Its return value is address of allocated
  //	storage.
  person *p_1 = malloc(sizeof(person));

  /* If there is no enough memory in os */
  /*   to allocate desired value. `malloc` */
  /*   will return NULL. */
  check_null_pointer(p_1);

  // It is a good practice to cast malloc
  //	pointer, to type for which memory
  //  is being allocated.
  person *p_2 = (person *)malloc(sizeof(person));
  check_null_pointer(p_2);

  /* ask_for_person(p_1); */

  /* ask_for_person(p_2); */

  /* puts("\nPerson 1"); */
  /* show_person(p_1); */

  /* puts("\nPerson 2"); */
  /* show_person(p_2); */

  free(p_1);
  free(p_2);

  // Allocated but unicialized memory is not filled
  //	by any data.
  char *un_malloc = (char *)malloc(sizeof(char) * 4);
  // So this code containe error. Because '\0' is not
  //	copied, so some random data is in its place.
  strncpy(un_malloc, "Kuba", 3);
  // To fix it add string termination char.
  un_malloc[3] = '\0';
  printf("%s\n", un_malloc);

  free(un_malloc);

  return EXIT_SUCCESS;
}
