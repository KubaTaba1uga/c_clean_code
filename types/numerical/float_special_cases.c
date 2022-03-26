/* `fpclassify` dependency */
#include <math.h>
#include <stdio.h>

char *show_classification(double x) {
  /* macro `fpclassify` return exception */
  /* 	based on passed value.  */
  switch (fpclassify(x)) {
  case FP_INFINITE:
    return "infinity";
  case FP_NAN:
    return "not a number";
  case FP_NORMAL:
    return "normal";
  case FP_SUBNORMAL:
    return "subnormal";
  case FP_ZERO:
    return "zero";
  default:
    return "unknown";
  }
}

int main(void) {
  float infinity = log(0);

  printf("log(0)=%s\n", show_classification(infinity));

  float infinity_0 = 1.0 / 0.0;

  printf("1.0/0.0=%s\n", show_classification(infinity_0));

  float not_a_number = sqrt(-1);

  printf("sqrt(-1)=%s\n", show_classification(not_a_number));

  return 0;
}
