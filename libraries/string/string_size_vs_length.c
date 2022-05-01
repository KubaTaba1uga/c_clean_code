#include <stdio.h>
/* `strncat` dependency */
#include <string.h>

int main(void) {
  char a[] = "abc";
  char b[] = {'a', 'b', 'c'};

  // size of string is accomodation of its each ellement
  size_t a_size = sizeof(a);
  size_t b_size = sizeof(b);

  // length of string is number of elements until '\0'
  int a_len = strlen(a);
  int b_len = strlen(b);

  // 4 because each char takes one byte and there are
  // four of them: a, b, c, \0
  printf("size of a: %lu\n", a_size);

  // 3 because each char takes one byte and there are
  // four of them: a, b, c
  printf("size of b: %lu\n", b_size);

  // 3 because thats much characters are before \0
  printf("length of a: %i\n", a_len);

  // undefinde behaviour because there is no \0 in string
  printf("length of b: %i\n", b_len);

  return 0;
}
