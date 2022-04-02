#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[32];
  int age;
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
  printf("%s is %i years old\n", somebody->name, somebody->age);
}

int main(void) {

  person *somebody = (person *)malloc(sizeof(person));
  if (somebody == NULL)
    goto ALLOCATION_ERROR;

  ask_name(somebody->name);
  ask_age(&somebody->age);
  present(somebody);

  free(somebody);

  exit(EXIT_SUCCESS);

ALLOCATION_ERROR:
  fprintf(stderr, "Program unable to allocate enough memory\n");
  exit(EXIT_FAILURE);
}
