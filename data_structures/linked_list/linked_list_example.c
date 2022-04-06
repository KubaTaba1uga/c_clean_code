#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "linked_list.h"

void show_progress(int i) {
  const char *progress = "-\\|/";
  printf("%c%c%c]", 8, 8, progress[(i / 100) % 4]);
  fflush(stdout);
}

typedef struct {
  int a;
  int b;
} numbers;

int create_random_n(void) { return rand() % 100 + 1; }

int main(void) {
  // reset seed
  srand(time(0));

  numbers *first_n = (numbers *)malloc(sizeof(numbers));
  if (!first_n) {
    puts("Unable to first numbers memory");
    goto PROGRAM_FAILURE;
  }
  first_n->a = 0;
  first_n->b = 0;

  l_list *l = linked_list_create(first_n), *l_cp = l;
  if (!l) {
    puts("Unable to allocate linked list memory");
    goto PROGRAM_FAILURE;
  }

  printf("Initializing array [-]");

  // fill linked list with 200 000 000 elements
  for (int i = 0; i < 200000000; ++i) {
    if (!(i % 100))
      show_progress(i);

    numbers *n = (numbers *)malloc(sizeof(numbers));
    if (!n) {
      printf("\nUnable to allocate %i number memory\n", i);
      goto PROGRAM_FAILURE;
    }
    n->a = create_random_n();
    n->b = create_random_n();
    l_cp = linked_list_append(l_cp, n);
  }
  puts("");

  linked_list_clear(l);

  /* while (l->next) { */
  /*   numbers *n = l->value; */
  /*   printf("a=%i | b=%i\n", n->a, n->b); */
  /*   l = l->next; */
  /* } */

  /* for (int i = 0; i < 1000; i++) { */
  /*   clock_t clk = clock(); */
  /*   printf("`printf` took %ld procesor cycles\n", clock() - clk); */
  /* } */

  return 0;

PROGRAM_FAILURE:
  exit(EXIT_FAILURE);
}
