#include <stddef.h>
#include <stdio.h>

void print_memory_layout(void *ptr, size_t size);

struct BasicStruct {
  int a;
  long int b;
  long long int c;
};

int main() {
  struct BasicStruct example = {
      0x12345678,          // a
      0x123456789ABCDEF0L, // b
      0x0FEDCBA987654321LL // c
  };

  printf("Size of struct: %zu bytes\n", sizeof(struct BasicStruct));
  printf("Offset>Size of 'a': %zu>%zu bytes\n", offsetof(struct BasicStruct, a),
         sizeof(example.a));
  printf("Offset>Size of 'b': %zu>%zu bytes\n", offsetof(struct BasicStruct, b),
         sizeof(example.b));
  printf("Offset>Size of 'c': %zu>%zu bytes\n", offsetof(struct BasicStruct, c),
         sizeof(example.c));

  print_memory_layout(&example, sizeof(struct BasicStruct));

  return 0;
}

void print_memory_layout(void *ptr, size_t size) {
  unsigned char *byte_ptr = (unsigned char *)ptr;
  printf("\nMemory layout:\n");
  for (size_t i = 0; i < size; i++) {
    printf("%02X ", byte_ptr[i]);
    if ((i + 1) % 8 == 0)
      printf("\n"); // Newline every 8 bytes for readability
  }
  printf("\n");
}
