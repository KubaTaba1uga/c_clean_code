#include <stdio.h>

/* Scope of an identifier begins at the end of the identifier's declaration */
/*         and ends at the end of the function declaration. The identifier in */
/*         the function prototype and the corresponding identifier in the */
/*         function definition need not be identical but can be perhaps to */
/*         improve readability.  */

/* function prototype (not part of a function definition) */
int simple_add(int lho, int rho);

int lho; /* no conflict with "lho" in function prototype */

int main(void) {
  printf("%d\n", simple_add(1, 2));

  return 0;
}

/* function definition */
int simple_add(int lho, int rho) { return (lho + rho); }
