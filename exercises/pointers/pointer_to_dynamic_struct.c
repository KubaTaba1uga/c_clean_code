#include <stdio.h>
#include <stdlib.h>

int PERSON_NAME_SIZE = 32;

typedef struct {
  char *name;
  int *age;
} person;

void ask_name(char *name) {
  puts("What is Your name?");
  scanf("%s", name);
}

void ask_age(int *age) {
  puts("How old are You?");
  scanf("%i", age);
}

void present(person *somebody) {
  printf("%s is %i years old\n", somebody->name, *somebody->age);
}

int main(void) {

  /* If structer member is pointer, only memory needed */
  /* 	to hold the pointer is allocated.  */
  person *somebody = (person *)malloc(sizeof(person));
  if (somebody == NULL)
    goto ALLOCATION_ERROR;

  /* Because `name` and `age are a pointer type, storage to which */
  /*   they are pointing has to be allocated. */

  somebody->name = (char *)malloc(sizeof(char) * PERSON_NAME_SIZE);
  if (somebody->name == NULL)
    goto REALESE_PERSON;

  somebody->age = (int *)malloc(sizeof(int));
  if (somebody->age == NULL)
    goto REALESE_NAME;

  ask_name(somebody->name);
  ask_age(somebody->age);
  present(somebody);

  free(somebody);

  exit(EXIT_SUCCESS);

REALESE_NAME:
  free(somebody->name);
REALESE_PERSON:
  free(somebody);
ALLOCATION_ERROR:
  fprintf(stderr, "Program unable to allocate enough memory\n");
  exit(EXIT_FAILURE);
}
