#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[32];
  int age;
} person;

void ask_name(char *name) {
  puts("What is Your name?");
  char *f = fgets(name, 32, stdin);
  if (f == NULL) {
    fprintf(stderr, "Input error\n");
    exit(EXIT_FAILURE);
  }
}

void ask_age(int *age) {
  puts("How old are You?");
  scanf("%d", age);
}

int main(void) {
  const char *file_name = "person.dat";
  FILE *fp;

  person *somebody = (person *)malloc(sizeof(person));
  if (somebody == NULL) {
    fprintf(stderr, "Program unable to allocate enough memory\n");
    goto PROGRAM_FAILURE;
  }

  ask_name(somebody->name);
  ask_age(&somebody->age);

  fp = fopen(file_name, "w");
  if (fp == NULL) {
    fprintf(stderr, "Program unable to read from %s\n", file_name);
    goto PROGRAM_FAILURE;
  }

  fwrite(somebody, sizeof(person), 1, fp);
  fclose(fp);

  free(somebody);

  exit(EXIT_SUCCESS);

PROGRAM_FAILURE:
  exit(EXIT_FAILURE);
}
