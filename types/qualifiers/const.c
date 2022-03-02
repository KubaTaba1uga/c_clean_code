#include <stdio.h>
/* Object declared with `const` qualifier */
/* 	can't be changed. It is placed in */
/* 	read-only memory, by the compiler. */

int main(void){
  const int a = 5;
  /* error */
  // a = 3;

  printf("a=%i\n",a);

  /* we can cheat a compiler */
  /* 	by telling that pointer */
  /* 	to `const` is not a `const` */
  /* 	but this is undefined */
  /* 	behaviour. */
  int *ia = (int *)&a;

  *ia = 3;

  printf("a=%i\n",*ia);

  return 0;
}
