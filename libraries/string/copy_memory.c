/* memcpy_s implementation used in this example is from: */
/* 	https://github.com/rurban/safeclib */
/* to compile using gcc add: `-l safec` */
#define __STDC_WANT_LIB_EXT1__ 1
#include <safeclib/safe_mem_lib.h>
#include <safeclib/safe_str_lib.h>
#include <stdio.h>
#include <string.h>

void show_memcpy(char *dst, char *src, size_t cpy_counter) {
  printf("src: %s, chars to cpy: %lu\n", src, cpy_counter);
  printf("result: %s\n", dst);
}

void show_hex(char *str, size_t str_size) {
  printf("Hexadecimal values of %s: [", str);
  while (str_size--)
    printf(" %x ", *str++);
  puts("]\n");
}

int main(void) {
  char s[] = "Kevin Michnik", z[] = "Richard Hammond";
  size_t s_size = sizeof(s), z_size = sizeof(z), s_size_2 = s_size - (size_t)9,
         z_size_2 = z_size - (size_t)9;

  char s_dst[s_size], z_dst[z_size], s_dst_2[s_size], z_dst_2[z_size];

  memcpy(s_dst, s, s_size);

  show_memcpy(s_dst, s, s_size);
  show_hex(s_dst, s_size);

  memcpy(s_dst_2, s, s_size_2);
  show_memcpy(s_dst_2, s, s_size_2);
  show_hex(s_dst_2, s_size_2 + (size_t)1);

  if(memcpy_s(z_dst, z_size, z, z_size) != 0)
    goto MEMCPY_S_FAILURE;
  show_memcpy(z_dst, z, z_size);
  show_hex(z_dst, z_size);

  if(memcpy_s(z_dst_2, z_size, z, z_size_2) != 0)
  goto MEMCPY_S_FAILURE;
  show_memcpy(z_dst_2, z, z_size_2);
  show_hex(z_dst_2, z_size_2 + (size_t)1);

  return 0;

MEMCPY_S_FAILURE:
  puts("ERROR:  memcpy_s failed");
  return -1;
}
