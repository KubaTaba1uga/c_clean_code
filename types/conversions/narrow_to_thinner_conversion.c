/* `errno_t` dependency */
#include <errno.h>
/* `SCHAR_MIN`, `SCHAR_MAX` dependency */
#include <limits.h>
#include <stdio.h>
/* `strerror` dependency */
#include <string.h>

void test_long_int_to_schar(int *errno_p, signed long value) {
  /* As `signed long int` is wider than `signed char` */
  /* 	validation is required. */
  if ((value < SCHAR_MIN) || (value > SCHAR_MAX)) {
    *errno_p = ERANGE;
  }
}

int main(void) {
  signed long a = 127;

  test_long_int_to_schar(&errno, a);
  if (errno != ERANGE) {
    signed char sca = (signed char)a; // Cast quiets warning
   
    puts("sca succesfully converted");
  } else
    // Handle the exception
    printf("Exception handling for %lu \n", a);


  signed long b = 255;

  test_long_int_to_schar(&errno, b);
  if (errno != ERANGE) {
    signed char scb = (signed char)b; // Cast quiets warning

    /* do stuff with scb  */
  } else
    // Handle the exception
    printf("Exception handling for %lu \n", b);

  return 0;
}
