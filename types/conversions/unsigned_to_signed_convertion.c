/* `errno` dependency */
#include <errno.h>
/* `SCHAR_MIN`, `SCHAR_MAX` dependency */
#include <limits.h>
#include <stdio.h>
/* `strerror` dependency */
#include <string.h>

void test_usint_to_sint(int *errno_p, unsigned int value) {
  /* As `unsigned int` is wider than `signed int` */
  /* 	validation is required. */
  if (value > INT_MAX) {
    *errno_p = ERANGE;
  }
}

int main(void) {
  unsigned int a = 127;

  test_usint_to_sint(&errno, a);
  if (errno != ERANGE) {
    signed int sia = (signed int)a; // Cast quiets warning

    puts("sia succesfully converted");
  } else
    // Handle the exception
    printf("Exception handling for %u \n", a);

  unsigned int b = UINT_MAX - 59;

  test_usint_to_sint(&errno, b);
  if (errno != ERANGE) {
    signed int sib = (unsigned int)b; // Cast quiets warning

    /* do stuff with scb  */
  } else
    // Handle the exception
    printf("Exception handling for %u \n", b);

  return 0;
}
