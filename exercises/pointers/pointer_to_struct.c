#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int *age;
} person;

char *ask_name(char *name) {
  puts("What is Your name?");
  scanf("%s", name);
  return name;
}

int *ask_age(int *age) {
  puts("How old are You?");
  scanf("%i", age);
  return age;
}

void present(person *sbdy) {
  printf("%s is %i years old\n", sbdy->name, *sbdy->age);
}

int main(void) {
  size_t max_name_len = 32;

  person *jakub = (person *)malloc(sizeof(person));
  if (jakub == NULL)
    goto ALLOCATION_ERROR;

  char *name = (char *)malloc(sizeof(char) * max_name_len);
  if (name == NULL)
    goto FREE_PERSON;

  int *age = (int *)malloc(sizeof(int));
  if (age == NULL)
    goto FREE_NAME;

  jakub->name = ask_name(name);
  jakub->age = ask_age(age);

  present(jakub);

  free(name);
  free(age);
  free(jakub);

  exit(EXIT_SUCCESS);

FREE_PERSON:
  free(jakub);
FREE_NAME:
  free(name);
ALLOCATION_ERROR:
  puts("Program unable to allocate enough memory");
  exit(EXIT_FAILURE);
}
