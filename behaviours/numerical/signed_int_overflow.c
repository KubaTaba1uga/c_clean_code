#include <limits.h>
#include <stdio.h>

#define abs(i) ((i) < 0 ? (i * -1) : (i))
/* To prevent from undefined behaviour, check value */
/*	after wraparound, if it is equal to controll flag, */
/*	return flag in plice of unpredictable result.  */
/*	That way behaviour is always known.  */
#define abs_better(i, flag) ((i) >= 0 ? (i) : (i) == (flag) ? (flag) : (i) * -1)

void show_abs(int a, int abs_a) { printf("abs(%d)=%d\n", a, abs_a); }

int main(void) {
  signed int a = -25;

  signed int abs_a = abs(a);

  show_abs(a, abs_a);

  signed char min = SCHAR_MIN;

  /* Wrap around signed type is undefined in C */
  signed char abs_min = abs(min); // integer overflow
  /* Overflow explained: */
  /*	-128 = 10000001 */
  /*	-1 = 11111111 */
  /*	-128*-1 = 1000000001111111 */

  show_abs(min, abs_min);

  signed char minimum = SCHAR_MIN;

  signed char abs_minimum = abs_better(minimum, SCHAR_MIN);

  if (abs_minimum == SCHAR_MIN)
    printf("Getting absolute value failed for: %d\n", abs_minimum);
  else
    show_abs(min, abs_minimum);

  return 0;
}
