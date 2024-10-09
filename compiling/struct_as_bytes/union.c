#include <stddef.h>
#include <stdio.h>

void print_memory_layout(void *ptr, size_t size);

union Data {
  int i;
  float f;
  char bytes[4];
};

int main() {
  union Data example;
  example.f = 3.00f;

  printf("Size of union: %zu bytes\n", sizeof(union Data));
  printf("Offset>Size of 'i': 0>%zu bytes\n", sizeof(example.i));
  printf("Offset>Size of 'f': 0>%zu bytes\n", sizeof(example.f));
  printf("Offset>Size of 'bytes': 0>%zu bytes\n", sizeof(example.bytes));

  print_memory_layout(&example, sizeof(union Data));
  puts("");

  example.i = 5;

  printf("Size of union: %zu bytes\n", sizeof(union Data));
  printf("Offset>Size of 'i': 0>%zu bytes\n", sizeof(example.i));
  printf("Offset>Size of 'f': 0>%zu bytes\n", sizeof(example.f));
  printf("Offset>Size of 'bytes': 0>%zu bytes\n", sizeof(example.bytes));

  print_memory_layout(&example, sizeof(union Data));

  return 0;
}

void print_memory_layout(void *ptr, size_t size) {
  unsigned char *byte_ptr = (unsigned char *)ptr;
  printf("\nMemory layout:\n");
  for (size_t i = 0; i < size; i++) {
    printf("%02X ", byte_ptr[i]);
  }
  printf("\n");
}
