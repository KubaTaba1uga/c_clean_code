#include <limits.h>
#include <stdio.h>

int main(void) {
  unsigned char a = UCHAR_MAX;

  printf("Decimal: a=%d\n", a);
  /* `ff` because all bits are 1 */
  printf("HexaDecimal: a=%x\n", a);
  /* `377` because 3*16+7*8+7*1=255 */
  printf("Octal: a=%o\n\n", a);

  /* Octal notations is best for permissions */
  /* 	or three bits data. */

  /* To describe data as octal value must  */
  /*   have 0 as suffix. */
  int permissions = 0777;
  printf("Decimal: permissions=%d\n", permissions);
  printf("Octal: permissions=%o\n", permissions);

  /* Hecadecimal notation is best for bits  */
  /*   representation. Ex. memory addresses. */

  /* To describe data as hexadecimal must  */
  /*    value 0x as suffix. */
  int address = 0xAC32FA;
  printf("Decimal: address=%d\n", address);
  printf("HexaDecimal: address=%x\n", address);
  printf("HexaDecimal: address+1=%x\n", address + 1);

  /* Integers notation is general purpose type. */
  /* To describe data as: */
  /*	unisgned */
  unsigned u_number = 10U;
  /*	long */
  long l_number = 10L;
  /*	long long */
  long long ll_number = 10LL;

  /* Float notation is best for mathematical */
  /* 	operations. */

  /* To describe data as: */
  /*	float */
  float f_number = 10.0F;
  /*	double */
  double fd_number = 10.0;
  /*	long double */
  long double fld_number = 10.0L;

  return 0;
}
