/* Program for random number generation */
/*         in range from 0 to 100. */

#include <stdio.h>
/* 'rand' dependency */
#include <stdlib.h>
/* new seed dependency */
#include <time.h>

int get_random(int lower, int upper) {

  /* use current time as seed for random generator */
  int now = time(NULL);

  /* use of two seeds will create better random illusion  */
  int extra_seed = rand();

  /* generate new seed for each program execution */
  int new_seed = now * extra_seed;

  /* update `rand` seed */
  srand(new_seed);

  return (rand() % upper) + lower;
}

int main(void) {

  /* precise lower boundary */
  int lower_bound = 0;

  /* precise upper boundary */
  int upper_bound = 100;

  for (int i = 0; i < 10; ++i) {

    int random_number = get_random(lower_bound, upper_bound);

    printf("%i\n", random_number);
  }

  return 0;
}
