/* `pow` dependency */
#include <math.h>

int main(void) {
  /* 16 bits long */
  short int a = 0;

  /* Max value = 2^15 - 1 = 32767 */
  signed short int b = 32767;

  /* Max value = 2^16 - 1 = 65535 */
  unsigned short int c = 65535;

  /* 32 bits long */
  int d = 0;

  /* Max value = 2^31 - 1 = 2147483647 */
  signed int e = 2147483647;

  /* Max value = 2^32 - 1 = 4294967295 */
  unsigned int f = 4294967295;

  /* 64 bits long */
  long int g = 0;

  /* Max value = 2^63 - 1 = 9,223372036854776 * 10^18 */
  signed long int h = 9.223372036854776 * pow(10, 18);

  /* Max value = 2^64 - 1 = 1,844674407370956 * 10^19 */
  unsigned long int i = 1.844674407370956 * pow(10, 19);

  return 0;
}
