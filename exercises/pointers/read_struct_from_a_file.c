#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[32];
  int age;
} person;

void show_person(char *name, int age) {
  printf("Name: %sAge: %d\n", name, age);
}

int main() {

  const char file_name[] = "person.dat";
  FILE *fp;

  /* allocate structure */
  person *somebody = (person *)malloc(sizeof(person) * 1);
  if (somebody == NULL) {
    fprintf(stderr, "Unable to allocate structure memory\n");
    goto PROGRAM_FAILURE;
  }

  /* read the structure into memory */
  /* open the file */
  fp = fopen(file_name, "r");
  if (fp == NULL) {
    fprintf(stderr, "Unable to read from %s\n", file_name);
    goto PROGRAM_FAILURE;
  }
  /* read in the structure */
  fread(somebody, sizeof(person), 1, fp);
  /* close the file */
  fclose(fp);

  /* output results */
  puts("Data read:");
  show_person(somebody->name, somebody->age);

  free(somebody);

  return EXIT_SUCCESS;

PROGRAM_FAILURE:
  exit(EXIT_FAILURE);
}
