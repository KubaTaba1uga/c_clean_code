/* Program which show how pass any data type */
/*         as function argument. */

#include <stdio.h>
/* 'rand' dependency */
#include <stdlib.h>
/* new seed dependency */
#include <time.h>

void show_number(void *data) { printf("In func: %d\n", data); }

int main(void) {
  srand(time(NULL));

  int random_number = rand();

  printf("In main: %d\n", random_number);

  show_number(random_number);

  return 0;
}
