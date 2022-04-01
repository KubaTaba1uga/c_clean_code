/* `errno` dependency */
#include <errno.h>
/* `SCHAR_MIN`, `SCHAR_MAX` dependency */
#include <limits.h>
#include <stdio.h>
/* `strerror` dependency */
#include <string.h>

void test_sint_to_usint(int *errno_p, signed int value) {
  /* As `signed int` can have negative values */
  /* 	validation is required. */
  if (value < 0) {
    *errno_p = ERANGE;
  }
}

int main(void) {
  signed int a = 127;

  test_sint_to_usint(&errno, a);
  if (errno != ERANGE) {
    unsigned int usia = (unsigned int)a; // Cast quiets warning

    puts("usia succesfully converted");
  } else
    // Handle the exception
    printf("Exception handling for %i \n", a);

  signed int b = -59;

  test_sint_to_usint(&errno, b);
  if (errno != ERANGE) {
    unsigned int usib = (unsigned int)b; // Cast quiets warning

    /* do stuff with usib  */
  } else
    // Handle the exception
    printf("Exception handling for %i \n", b);

  return 0;
}
