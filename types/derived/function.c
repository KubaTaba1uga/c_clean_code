#include <stdio.h>

/* Function type is precised by type of return statement */
/*         and by types of passed arguments. */

/* Function type is pointer to int */
int *max(int *a, int *b) {
  /* If `*a` is bigger than `*b`, return `a` */
  /*    else return `b`. */
  return *a > *b ? a : b;
}

/* Function type is int. */
int sum(int a, int b) {
  /* Function can return any
     object besides array.  */

  return a + b;
}

int main(void) {
  int a = 100;

  int b = 200;

  printf("Max: %i\n", *max(&a, &b));

  printf("Sum: %i\n", sum(a, b));

  /* Function can return any object besides */
  /*     array.  */
  return 0;
}
