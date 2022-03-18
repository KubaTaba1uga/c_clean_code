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

  return 0;
}
