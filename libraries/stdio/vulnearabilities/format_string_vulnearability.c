#include <stdio.h>
#include <string.h>

/* Format string vulnerabilities are a class of bug that, */
/*   take advantage of an easily avoidable programmer error. */
/*     If the programmer passes an attacker-controlled buffer */
/*     as an argument to a printf (or any of the related */
/*     functions, including sprintf, fprintf, etc), the attacker */
/*     can perform writes to arbitrary memory addresses.  */

int main(int argc, char **argv) {
  char buffer[100];
  strncpy(buffer, argv[1], 100);

  // We are passing command line
  // argument to printf
  printf(buffer);

  return 0;
}

/* To exploit execute: */
/*      print_with_newline   "%p %p %p" */

/* `%p` is memory address macro */
/*         which exploited, will full */
/*         printf to assume more */
/*         arguments than programmer */
/*         really passed */
