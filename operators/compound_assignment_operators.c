#include <stdint.h>
#include <stdio.h>

/* Compound assignment operators modify */
/* 	object by performing operation on it. */
int main(void) {
  int a = 5;
  printf("a = %d\n", a);
  a += 5;
  printf("a = %d\n", a);
  a -= 9;
  printf("a = %d\n", a);
  a *= 4;
  printf("a = %d\n", a);
  a /= 2;
  printf("a = %d\n", a);
  a %= 2;
  printf("a = %d\n\n", a);

  /* b = 1 1 1 1 1 1 1 1 */
  uint8_t b = 0xFF;
  printf("b = %hhx\n", b);

  /* AND=`&` gives 1 if both bits are 1. */
  b &= 0x00;
  printf("b = %hhx\n", b);
  b = 0xFF;

  /* OR=`|` gives 1 if one of bits is 1. */
  b |= 0x00;
  printf("b = %hhx\n", b);
  b = 0xFF;

  /* XOR=`^` gives 1 if one bit is 0 and other is 1. */
  b ^= 0x00;
  printf("b = %hhx\n", b);
  b = 0xFF;

  /* Shift left=`<<` moves all lvalue bits to left
     by number of places on rvalue. */
  /* Example: */
  /* b = 1 1 1 1 1 1 1 1 */
  /* 2 = 0 0 0 0 0 0 1 0 */
  /* b << 2 = 1 1 1 1 1 1 0 0 */
  /* 1111 = f | 1100 = c */
  b <<= 2;
  printf("b = %hhx\n", b);

  /* Shift right=`>>` moves all lvalue bits to right
     by number of places on rvalue. */
  /* Example: */
  /* b = 1 1 1 1 1 1 1 1 */
  /* 2 = 0 0 0 0 0 0 1 0 */
  /* b >> 2 = 0 0 1 1 1 1 1 1 */
  /* 0011 = 3 | 1111 = f */
  b >>= 2;
  printf("b = %hhx\n", b);

  return 0;
}
