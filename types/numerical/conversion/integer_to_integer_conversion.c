/* `errno_t` dependency */
#include <errno.h>
/* `SCHAR_MIN`, `SCHAR_MAX` dependency */
#include <limits.h>
#include <stdio.h>
/* `strerror` dependency */
#include <string.h>

void test_long_int_to_schar(signed long value) {
  if ((value < SCHAR_MIN) || (value > SCHAR_MAX)) {
    errno = ERANGE;
  }
}

int main(void) {
  signed long a = 127;

  test_long_int_to_schar(a);
  if (errno != ERANGE) {
    signed char sca = (signed char)a; // Cast quiets warning

    /* do stuff with sca  */
  }

  signed long b = 1000;

  test_long_int_to_schar(a);
  if (errno != ERANGE) {
    signed char scb = (signed char)b; // Cast quiets warning

    /* do stuff with scb  */
  } else
    printf("%lu cannot be signed into signed char", b);

  puts(strerror(errno));
  puts(strerror(ERANGE));

  return 0;
}
