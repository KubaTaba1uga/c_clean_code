/* `uin8_t` dependency */
#include <stdint.h>
#include <stdio.h>

void show_hex(char *equation, uint8_t number) {
  printf("%s = %hhx\n", equation, number);
}

int main(void) {
  /* a = 0 0 0 0 0 0 0 1 */
  uint8_t a = 0x01;
  printf("a = %hhx\n", a);
  /* b = 1 1 1 1 1 1 1 1 */
  uint8_t b = 0xFF;
  printf("b = %hhx\n", b);

  /* AND=`&` gives 1 if both bits are 1. */
  uint8_t n = a & b;
  show_hex("a & b", n);

  /* OR=`|` gives 1 if one of bits is 1. */
  uint8_t m = a | b;
  show_hex("a | b", m);

  /* XOR=`^` gives 1 if one bit is 0 and other is 1. */
  uint8_t o = a ^ b;
  show_hex("a ^ b", o);

  /* Complement=`~` gives 1 if other bit is 0 and 0 if other bit is 1. */
  uint8_t p = ~b;
  show_hex("~b", p);

  /* Shift left=`<<` moves all lvalue bits to left
     by number of places on rvalue. */
  /* Example: */
  /* b = 1 1 1 1 1 1 1 1 */
  /* 2 = 0 0 0 0 0 0 1 0 */
  /* b << 2 = 1 1 1 1 1 1 0 0 */
  /* 1111 = f | 1100 = c */
  uint8_t r = b << 2;
  show_hex("b<<2", r);

  /* Shift right=`>>` moves all lvalue bits to right
     by number of places on rvalue. */
  /* Example: */
  /* b = 1 1 1 1 1 1 1 1 */
  /* 2 = 0 0 0 0 0 0 1 0 */
  /* b >> 2 = 0 0 1 1 1 1 1 1 */
  /* 0011 = 3 | 1111 = f */
  uint8_t s = b >> 2;
  show_hex("b>>2", s);

  /* In case of shifting `signed` values additional */
  /*	validation has to be made.  */
  int8_t c = 0xFF, t;
  if (c < 0)
    printf("Shifting can't be performed on negative value c=%i", c);
  else {
    t = c << 1;
    show_hex("t<<1", t);
  }

  return 0;
}
