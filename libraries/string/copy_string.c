/* strcpy_s implementation used in this example is from: */
/* 	https://github.com/rurban/safeclib */
/* to compile using gcc add: `-l safec` */
#define __STDC_WANT_LIB_EXT1__ 1
#include <safeclib/safe_str_lib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char s[] = "Harold Hamil";
  char z[] = "James McGill";
  size_t s_size = sizeof(s);
  char s_cp[s_size];

  strcpy(s_cp, s);

  printf("strcpy: %s\n", s_cp);

  if (strcpy_s(s_cp, s_size, z) != 0)
    puts("strcpy_s failed");
  else
    printf("strcpy_s: %s\n", s_cp);
}
